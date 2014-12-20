/*
	Tarefa 10 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250 
	Turma A
*/

#include "hash.h"

/*aloca a tabela*/
TabelaHash *CriaTabela(){
	TabelaHash *t;
	/* inicia a tabela com tudo valendo 0 */
	t = (TabelaHash *)calloc(13, sizeof(TabelaHash));
	return t;
}

/*funcao que dado a chave retorna o indice*/
unsigned int FuncaoHash(char *chave){
	unsigned int indice = 0, i = 0;
	
	while(chave[i])
		indice ^= chave[i++];
	
	return indice%13;
}

/*insere uma chave na tabela, se der certo retorna true*/
bool InsereTabela(TabelaHash *t, Aluno *a){
	unsigned int indice;
	Lista *p, *anteriorP;
	
	indice = FuncaoHash(a->nome);
	p = anteriorP = t[indice].Head;
	
	while(p){
		if(strcmp(p->info.nome,a->nome) == 0)/* se achar um nome igual nao insira */
			return false;
		anteriorP = p;
		p = p->prox;
	}
	
	/* aloca um elemnto novo para a lista */
	p = malloc(sizeof(Lista));
	p->info.ra = a->ra;
	p->info.nome = malloc(strlen(a->nome)+1);
	strcpy(p->info.nome,a->nome);
	p->prox = NULL;
	
	if(t[indice].Head == NULL)/*lista vazia*/
		t[indice].Head = p;
	else
		anteriorP->prox = p;
	
	ordena(t[indice].Head);
	
	return true;
}

/*remove uma chave na tabela, se der certo retorna true*/
bool RemoveTabela(TabelaHash *t, char *buf){
	unsigned int indice;
	Lista *p, *anteriorP = NULL;
	
	indice = FuncaoHash(buf);
	p = t[indice].Head;
	
	while(p){/* se achar a chave, pare o loop */
		if(strcmp(p->info.nome,buf) == 0)
			break;
		anteriorP = p;
		p = p->prox;
	}
	
	if(p == NULL)/*nao existe a chave na tabela*/
		return false;
	else if(strcmp(p->info.nome,t[indice].Head->info.nome) == 0){
		t[indice].Head = p->prox;/*se a chave esta no inicio da lista*/
	}
	else{
		anteriorP->prox = p->prox;
	}
		
	free(p);
	
	return true;
}

/*retorna true se existe a chave e false se nao existe*/
bool ConsultaTabela(TabelaHash *t, char *buf, Aluno *a){
	unsigned int indice;
	Lista *p;
	
	indice = FuncaoHash(buf);
	p = t[indice].Head;
	
	while(p){/* se achar a chave, pare o loop */
		if(strcmp(p->info.nome,buf) == 0)
			break;
		p = p->prox;
	}
	
	if(p == NULL)/*nao existe a chave*/
		return false;
	
	a->ra = p->info.ra;
	a->nome = malloc(strlen(buf)+1);
	strcpy(a->nome,buf);
	
	return true;
}

/* retorna o numero de elementos que foram inseridos na tabela */
int NumeroAlunosTabela(TabelaHash *t){
	int num, i;
	Lista *p;
	
	for(i = num = 0; i < 13; i++){
		p = t[i].Head;
		while(p){
			num++;
			p = p->prox;
		}
	}
	
	return num;
}

/* imprime os elementos da tabela */
void ImprimeTabela(TabelaHash *t){
	int i;
	Lista *p;
	
	for(i = 0; i < 13; i++){
		p = t[i].Head;
		while(p){
			printf("(%d) %06d \"%s\"\n",i,p->info.ra,p->info.nome);
			p = p->prox;
		}
	}
}

/* libera a memoria que foi alocada para a tabela */
void LiberaTabela(TabelaHash *t){
	int i;
	Lista *p, *aux;
	
	for(i = 0; i < 13; i++){
		p = t[i].Head;
		while(p){
			aux = p->prox;
			free(p->info.nome);
			free(p);
			p = aux;
		}
	}
}

/*troca dois elementos consecutivos de uma lista*/
void troca(Lista *x, Lista *y) {
    int raAux;
	char *nomeX;
	char *nomeY;
	
	/* troca os RA's */
	raAux = x->info.ra;
	x->info.ra = y->info.ra;
	y->info.ra = raAux;
	
	/* copia os nomes */
	nomeX = malloc(strlen(x->info.nome)+1);
	strcpy(nomeX,x->info.nome);
	nomeY = malloc(strlen(y->info.nome)+1);
	strcpy(nomeY,y->info.nome);
	
	/* redimensiona as strings */
	free(x->info.nome);
	free(y->info.nome);
	
	x->info.nome =  malloc(strlen(nomeY)+1);
	strcpy(x->info.nome,nomeY);
	y->info.nome =  malloc(strlen(nomeX)+1);
	strcpy(y->info.nome,nomeX);
	
	free(nomeX);
	free(nomeY);
}

/*ordena a lista em ordem alfabetica*/
void ordena(Lista *lista){
	Lista *p, *q;
	for(p = lista; p ; p = p->prox)
		for(q = lista; q->prox ; q = q->prox)
			if(strcmp(q->info.nome,q->prox->info.nome) > 0)
				troca(q,q->prox);
}