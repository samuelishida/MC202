/*
	Tarefa 5 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "disco.h"

/*remove o arquivo da memoria*/
void remove_disco(lista **first, string nome)
{
	lista *p = (*first)->prox;
	
	for(p = (*first)->prox; p ; p=p->prox)
		if(!strcmp(p->nome,nome))
			strcpy(p->nome,"");
}

/*insere o arquivo se houver como*/
bool insere_disco(lista **first, string nome, int mem)
{
	lista *p, *ant;
	lista *init;
	lista *aux;
	int i;
	
	if(lista_vazia(first))
	{
		ant = (*first)->prox;
		
		for(i=0; i<=mem; i++)
			insere_lista(&ant,nome,i);
		
		return true;
	}
	
	p = init = (*first)->prox;
	
	while(p)
	{
		/*se trocou o bloco*/
		if( p->n % (( (*first)->n )/8) )
			init = p;/*recomeca a verificao de memoria livre*/
			
		/*se acabar o bloco livre*/
		if(!strcmp(init->nome,"") && strcmp(p->nome,""))		
		{
			aux = init;
			
			/* insere em um bloco livre de memoria se for possivel*/
			if(p->n - init->n > mem && (p->n - init->n + mem) < ((*first)->n)/8)
			{
				for(i = 0; i < mem ; i++)
				{
					strcpy(aux->nome,nome);
					aux = aux->prox;
				}
				return true;
			}
			else /*reseta a contagem do bloco*/
				init = p;
		}
			
		ant = p;
		p = p->prox;
	}
	
	/*caso tenha que alocar mais elementos para a lista*/
	if( ant->n - init->n >= mem && (ant->n - init->n + mem) <= ((*first)->n)/8)
	{
		for(i = ant->n; i <= (mem+ant->n); i++)
			insere_lista(&ant,nome,i);
			
		return true;
	}
	
	/*caso nao tenha como inserir o arquivo*/
	return false;
}

/*tira os espaços em branco da memoria*/
void otimiza(lista **first)
{
	lista *p = (*first)->prox;
	lista *ant = *first;
	int i;
	
	while(p)
	{
		/*bloco livre*/
		if(!strcmp(p->nome,""))
		{
			ant->prox = p->prox;
			free(p);
			p = ant->prox;
		}
		else
			p = p->prox;
	}
	
	for(i = 0 ; p != NULL ; p = p->prox)
		p->n = i++;
}

void cria_disco(lista **first, string entrada)
{	
	int mem = calc_mem(entrada);
	
	*first = cria_lista(mem);
}

int calc_mem(string entrada)
{
	int mem = atoi(entrada);
		
	if(strpbrk(entrada,"M"))
		mem *= 1024;
	else if(strpbrk(entrada,"G"))
		mem *= 1024*1024;
	
	return mem;
}

void disco_status(lista **first)
{
	lista *p;
	int aux;
	double cont = 0;
	
	for(p = (*first)->prox; p != NULL; p = p->prox)
	{
		/*se trocou de bloco*/
		if(p->n % ((*first)->n)/8)
		{
			/*ve o quanto de memoria foi ocupada no bloco e imprime*/
			if(8*cont/(double)((*first)->n ) > 75)
				printf("[#]");
			else if(8*cont/(double)((*first)->n ) > 25)
				printf("[-]");
			else
				printf("[ ]");
			
			cont = 0;
		}
		else if (!strcmp(p->nome,""))/*se for memoria livre*/
			cont = 0;
		else
			cont++;
			
		aux = p->n;
	}
	
	while(aux <= (*first)->n)
	{
		aux++;
		if(aux % ((*first)->n)/8)
			printf("[ ]");/*a memoria esta livre*/
	}
	
	printf("\n");
}
