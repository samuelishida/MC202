/*
	Tarefa 5 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "lista.h"

lista *cria_lista(int mem)
{
	lista first = (lista *) malloc(sizeof(lista));
	
	int n = mem;/*memoria maxima*/
	first->prox = NULL;
	
	return first;
}

bool insere_lista(lista **first, string nome, int mem)
{
	lista *p, *ant;
	lista *init;
	lista *aux;
	int i;
	
	if(lista_vazia(*first))
	{
		ant = (*first)->prox = (lista*) malloc(sizeof(lista));
		ant->n = 0;
		strcpy(ant->nome,nome);
		
		for(i=1; i<mem; i++)
		{
			ant->n = i;
			strcpy(ant->nome,nome);
			ant->prox = (lista*) malloc(sizeof(lista));
			ant = ant->prox;
		}
		
		ant->n = i;
		strcpy(ant->nome,nome);
		ant->prox = NULL;
		
		return true;
	}
	
	p = init = (*first)->prox;
	
	while(p)
	{
		if(!strcmp(p->nome,init->nome))
		{
			aux = init;
			
			if(p->n - init->n > mem)
			{
				while(aux != p)
				{
					strcpy(aux->nome,nome);
					aux = aux->prox;
				}
				return true;
			}
		}
		else
			init = p;
		
		ant = p;
		p = p->prox;
	}
	
	if(ant->n+mem <= (*first)->n)
	{
		for(i=ant->n; i<mem; i++)
		{
			ant->n = i;
			strcpy(ant->nome,nome);
			ant->prox = (lista*) malloc(sizeof(lista));
			ant = ant->prox;
		}
		
		ant->n = i;
		strcpy(ant->nome,nome);
		ant->prox = NULL;
		
		return false;
	}
	
	return false;
}

void remove_lista(string nome)
{
	
}

void desaloca_lista(lista **first)
{
	lista *p = *first;
	lista *aux;
	
	while(p)
	{
		aux = p;
		p = p->prox;
		free(aux);
	}
}

bool fim_lista(lista *p)
{
	return (lista->prox == NULL);
}

bool lista_vazia(lista *first)
{
	return (first->prox == NULL);
}