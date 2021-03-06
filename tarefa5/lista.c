/*
	Tarefa 5 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "lista.h"

lista *cria_lista(int mem)
{	
	lista *p = (lista *)malloc(sizeof(lista));

	p->n = mem; /* first->n = memoria maxima */
	p->prox = NULL;

	return p;
}

lista *insere_lista(lista **last, string nome, int n)
{
	lista *p = (lista *)malloc(sizeof(lista));
	
	p->n = n;
	strcpy(p->nome,nome);
	p->prox = NULL;
	p->aloc = true;
	
	(*last)->prox = p;
	
	return p;
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
	return (p->prox == NULL)?(true):(false);
}

bool lista_vazia(lista **first)
{
	return ( (*first)->prox == NULL)?(true):(false);
}