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

struct Mapa{
	int n;
	int i, j;
	char rotulo;
};

typedef struct Mapa Mapa;

struct Fila
{
	int inicio;
	int fim;
	Mapa ponto[MAX];
};

typedef struct Fila Fila;

/*funcoes para manipular a fila*/
Fila *cria_fila();
void insere_fila(Fila *p,Mapa n);
Mapa remove_fila(Fila *p);
bool fila_cheia(Fila *p);
bool fila_vazia(Fila *p);