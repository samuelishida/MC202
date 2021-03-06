/*
	Tarefa 7 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "estruturas.h"

ArvoreBin *Remove_Aux;

ArvoreBin *criaArvoreBin() {
    return NULL;
}

ArvoreBin *busca(ArvoreBin *arv, int valor){
    if(arv == NULL || arv->rotulo == valor)
        return arv;
    if(arv->rotulo > valor)
        return busca(arv->esq, valor);
    if(arv->rotulo < valor)
        return busca(arv->dir, valor);
    return NULL;
}

void afunila(ArvoreBin **raiz, int valor){
    ArvoreBin *x;
	x = busca(*raiz, valor);

	if(!x)
		return;

	while( x->pai )
	{
		if( !x->pai->pai )
		{
			if( x->pai->esq == x )
				rotDir(raiz, x->pai );
			else 
				rotEsq(raiz, x->pai );
		}
		else if( x->pai->esq == x && x->pai->pai->esq == x->pai )
		{		
			rotDir(raiz, x->pai->pai );
			rotDir(raiz, x->pai );
		} 
		else if( x->pai->dir == x && x->pai->pai->dir == x->pai )
		{
			rotEsq(raiz, x->pai->pai );
			rotEsq(raiz, x->pai );
		}
		else if( x->pai->esq == x && x->pai->pai->dir == x->pai )
		{
			rotDir(raiz, x->pai );
			rotEsq(raiz, x->pai );
		}
		else
		{
			rotEsq(raiz, x->pai );
			rotDir(raiz, x->pai );
		}
	}
}

void rotDir(ArvoreBin **raiz, NoArvBin *x )
{
	NoArvBin *y = x->esq;
	if(y) {
		x->esq = y->dir;
		if( y->dir ) y->dir->pai = x;
		y->pai = x->pai;
	}
	if( !x->pai ) *raiz = y;
	
	else if( x == x->pai->esq )
		x->pai->esq = y;
	else
		x->pai->dir = y;
	if(y)
		y->dir = x;
	
	x->pai = y;
}

 void rotEsq( ArvoreBin **raiz, NoArvBin *x ) 
 {
    NoArvBin *y = x->dir;
    if(y) {
      x->dir = y->esq;
      if( y->esq ) y->esq->pai = x;
      y->pai = x->pai;
    }
 
    if( !x->pai ) 
    	*raiz = y;
    else if( x == x->pai->esq )
    	x->pai->esq = y;
    else
    	x->pai->dir = y;
    if(y)
    	y->esq = x;
    	
    x->pai = y;
}

void removeNo( ArvoreBin **raiz, int chave ){
   NoArvBin *z = busca( *raiz, chave );
	if( !z )
		return;
	
	if(!z->esq && !z->dir && z == *raiz)
	{
		free(*raiz);
		*raiz = NULL;
		return;
	}
 
	afunila( &z , chave);
 
	if( !z->esq )
		troca( raiz, &z, &z->dir );
   else if( !z->dir )
		troca( raiz, &z, &z->esq );
	else
	{
		Remove_Aux = min_subarv( z->dir );

		if( Remove_Aux->pai != z )
		{
			troca( raiz, &Remove_Aux, &Remove_Aux->dir );
			Remove_Aux->dir = z->dir;
			Remove_Aux->dir->pai = Remove_Aux;
		}

		troca( raiz, &z, &Remove_Aux );
		Remove_Aux->esq = z->esq;
		Remove_Aux->esq->pai = Remove_Aux;
	}
	
	free(z);
	z = NULL;
}

NoArvBin *min_subarv( NoArvBin *u ) {
	while( u->esq )
		u = u->esq;
	return u;
}

void troca( ArvoreBin **raiz, NoArvBin **u, NoArvBin **v ) {
	if( !(*u)->pai ) 
		*raiz = *v;
	else if( *u == (*u)->pai->esq )
		(*u)->pai->esq = *v;
	else 
		(*u)->pai->dir = (*v);
	if( *v ) 
		(*v)->pai = (*u)->pai;
}

/* funcao que chama pra inserir o no e que faz os afunilamentos */
void insereNo(int info, ArvoreBin **arv) {
	NoArvBin *p = *arv;
	NoArvBin *pai;
	bool esq;

	if(*arv == NULL)
	{
   	(*arv) = (ArvoreBin *)malloc(sizeof(NoArvBin));
   	(*arv)->rotulo = info;
   	(*arv)->dir = NULL;
  		(*arv)->esq = NULL;
   	(*arv)->pai = NULL;
	}
	
   else
	{
		while(p)
		{
			pai = p;
			if(info < p->rotulo){
				p = p->esq;
				esq = true;
			}
			else{
				p = p->dir;
				esq = false;
			}
		}

		p = (ArvoreBin *)malloc(sizeof(NoArvBin));
		p->rotulo = info;
		p->dir = NULL;
		p->esq = NULL;
		p->pai = pai;

		if(esq)
			pai->esq = p;
		else
			pai->dir = p;
	}

	afunila(arv, info);
}

void freeArvBin(ArvoreBin **arv)
{
	if(*arv)
	{	
		free(*arv);
		freeArvBin(&(*arv)->esq);
		freeArvBin(&(*arv)->dir);
	}
}






