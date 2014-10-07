/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "fila.h"

Fila *cria_fila()
{
	Fila *p;
	
	p = (Fila*)malloc(sizeof(Fila));
	
	p->inicio = p->fim = 0;
	
	return p;
}

void insere_fila(Fila *p,Mapa n)
{
	if(fila_cheia(p))
		return;
	else
	{
		p->ponto[p->fim] = n;
		p->fim = (p->fim+1)%MAX;
	}
}

Mapa remove_fila(Fila *p)
{
	Mapa n;
	
	if(fila_vazia(p))
		return;
		
	else
	{
		n = p->ponto[p->inicio]; 
		p->inicio = (p->inicio + 1)%MAX;
	}
	
	return n;
}

bool fila_cheia(Fila *p)
{
	return (p->inicio == ((p->fim + 1) % MAX));
}

bool fila_vazia(Fila *p)
{
	return (p->inicio == p->fim) ;
}