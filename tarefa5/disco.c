/*
	Tarefa 5 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "disco.h"

void remove_disco(lista **first, string nome)
{
	lista *p = *first->prox;
	
	for(p = *first->prox; p ; p=p->prox)
		if(!strcmp(p->nome,nome))
			strcpy(p->nome,"");
}

bool insere_disco(lista **first, string nome, int mem)
{
	lista *p, *ant;
	lista *init;
	lista *aux;
	int i;
	
	if(lista_vazia(*first))
	{
		ant = (*first)->prox;
		
		for(i=0; i<=mem; i++)
			insere_lista(&ant,nome,i);
		
		return true;
	}
	
	p = init = (*first)->prox;
	
	while(p)
	{
		/*se acabar o bloco livre*/
		if(!strcmp(init->nome,"") && strcmp(p->nome,""))		
		{
			aux = init;
			
			/*insere em um bloco livre de memoria se for possivel*/
			if(p->n - init->n > mem && (p->n - init->n + mem) < ((*first)->n)/8)
			{
				for(i = 0; i < mem ; i++)
				{
					strcpy(aux->nome,nome,init->n+i);
					aux = aux->prox;
				}
				return true;
			}
			else
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

void otimiza(lista **first)
{
	lista *p = (*first)->prox;
	lista *ant = *first;
	
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
	
	for(i = 0 ; p != NULL ; i++, p = p->prox)
		p->n = i;
}
