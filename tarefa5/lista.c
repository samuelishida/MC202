/*
	Tarefa 1 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "lista.h"

/*Implementacao das funcoes mtf, tr e fc*/
int mtf(int req, int n, lista **init)
{
	int i;
	lista *ant;
	lista *atual = *init;
	
	if(req > n)
		return n;
		
	if(req < 1)
		return n;
	
	/*Requisicao eh o primeiro elemento*/
	if(atual->arq == req)
		return 1;
		
	/*procura o elemento requisistado salvando o elemento anterior e incrementando i*/
	for(i=1; atual->arq != req && atual != NULL; i++, atual = atual->prox)
		ant = atual;
	
	/*liga o elemento anterior ao requisitado ao depois do requisitado*/
	ant->prox = atual->prox;
	/*o atual aponta para o primeiro elemento*/
	atual->prox = *init;
	/*agora o atual passa a ser o primeiro elemento*/
	*init = atual;
	
	return i;
}

int tr(int req, int n, lista **init)
{
	int i;
	lista *ant = *init;
	lista *atual = *init;
	lista *aux;
	
	
	if(req > n)
		return n;
	
	if(req < 1)
		return n;
	
	/*Requisicao eh o primeiro elemento*/
	if(atual->arq == req)
		return 1;
		
	/*procura o elemento anteriror ao requisitado*/
	for(i=2; atual->prox->arq != req && atual != NULL; i++, atual = atual->prox)
		ant = atual;
	
		
	if(i == 2)
	{
		atual = ant->prox;
		ant->prox = atual->prox;
		atual->prox = *init;
		*init = atual;
	}
	
	else
	{
		ant->prox = atual->prox;
		aux = atual->prox->prox;
		ant->prox->prox = atual;
		atual->prox = aux;
	}
	
	return i+1;
}

int fc(int req, int n, lista **init)
{
	int i, j;
	lista *ant2, *reqArq, *antReq, *atual, *aux;
	
	if(req > n)
		return n;
		
	if(req < 1)
		return n;
	
	/*Requisicao eh o primeiro elemento*/
	if((*init)->arq == req)
	{
		(*init)->cont++;
		return 1;
	}
		
	/*procura o elemento anteriror ao requisitado*/
	for(i=1, atual = *init; atual != NULL && atual->arq != req; i++, atual = atual->prox)
		antReq = atual;
	
	atual->cont++;
	reqArq = atual;
	
	for(j=1, atual = *init; atual != NULL && atual->cont > reqArq->cont; atual = atual->prox, j++)
		ant2 = atual;
		
	
	if(j == 1)
	{
		antReq->prox = reqArq->prox;
		aux = *init;
		*init = reqArq;
		reqArq->prox = aux;
	}
	else if(reqArq->prox == NULL )
	{
		if(antReq->cont < reqArq->cont)
		{
			antReq->prox = reqArq->prox;
			ant2->prox = reqArq;
			reqArq->prox = atual;
			i--;
		}
	}
	else if(atual->arq == antReq->arq)
	{
		aux = reqArq->prox;
		ant2->prox = reqArq;
		reqArq->prox = antReq;
		antReq->prox = aux;
	}
	else if(ant2->cont > reqArq->cont && reqArq->cont > reqArq->prox->cont);
	else
	{
		aux = ant2->prox;
		antReq->prox = reqArq->prox;
		ant2->prox = reqArq;
		reqArq->prox = aux;
	}

	return i;
}

lista *init_lista(int n)
{
	lista *first = malloc(sizeof(lista));
	lista *p;
	int i;
	
	for(i=1, p = first; i<n; i++)
	{
		p->arq = i;
		p->cont = 0;
		p->prox = malloc(sizeof(lista));
		p = p->prox;
	}
	
	p->arq = n;
	p->cont = 0;
	/* Fim da lista */
	p->prox = NULL;
	
	return first;
}

void desaloca_lista(lista **init)
{
	lista *p = *init;
	lista *aux;
	
	while(p != NULL)
	{
		aux = p;
		p = p->prox;
		free(aux);
	}
}