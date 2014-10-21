/*
	Tarefa 1 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista lista;
typedef char* string;

struct lista{
	int n;
	string nome;
	lista *prox;
};


/*Retorna o ponteiro do primeiro elemento de uma lista de N elementos indo de 1 a N*/
lista *init_lista(int n);
void desaloca_lista(lista **init);