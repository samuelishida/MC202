/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

struct Fila
{
	int inicio;
	int fim;
	int ponto[MAX];
};

typedef struct Fila Fila;

Fila *cria_fila();
void insere_fila(Fila *p,int n);
int remove_fila(Fila *p);
bool fila_cheia(Fila *p);
bool fila_vazia(Fila *p);