/*
	Tarefa 1 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista lista;

struct lista{
	int arq;
	int cont;
	lista *prox;
};

/*As tres funcoes da tarefa retornam o custo operacional*/

/*Move-To-Front*/
int mtf(int req, int n, lista **init);
/* Transpose*/
int tr(int req, int n, lista **init);
/*Frequency Count*/
int fc(int req, int n, lista **init);

/*Retorna o ponteiro do primeiro elemento de uma lista de N elementos indo de 1 a N*/
lista *init_lista(int n);
void desaloca_lista(lista **init);