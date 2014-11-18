/*
	Tarefa 7 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct lista lista;
typedef const char* string;

struct lista{
	int n;
	bool aloc;
	lista *prox;
};

typedef struct No {
	int info ; 
	struct No *pai ; 
	struct No *esq, *dir ; 
} ArvBin, NoArvBin ;

lista *cria_lista();

lista *insere_lista(lista **last, string nome, int n);

void desaloca_lista(lista **first);

bool fim_lista(lista *p);

bool lista_vazia(lista **first);

void desaloca_lista(lista **init);
