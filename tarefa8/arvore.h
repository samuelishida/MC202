/*
	Tarefa 8 de MC202
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

typedef struct Arvore {
    int rotulo;
    struct Arvore *pai;
    struct Arvore **filhos;
} Arvore, NoArv;

Arvore *criaArvore();
