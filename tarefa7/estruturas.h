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

typedef struct ArvoreBin {
    int rotulo;
    struct ArvoreBin *pai, *esq, *dir;
} ArvoreBin, NoArvBin;

ArvoreBin *criaArvoreBin();
ArvoreBin *criaNo(int info);
void insereNo(int info, ArvoreBin **arv);
ArvoreBin *busca(ArvoreBin *arv, int valor);
void troca( ArvoreBin **raiz, NoArvBin **u, NoArvBin **v );
void removeNo( ArvoreBin **raiz, int chave );
void removeConjunto(ArvoreBin *M, ArvoreBin **arv);
NoArvBin *min_subarv( NoArvBin *u );
void afunila(ArvoreBin **raiz, int valor);
void rotDir(ArvoreBin **raiz, NoArvBin *x );
void rotEsq( ArvoreBin **raiz, NoArvBin *x );
void freeArvBin( ArvoreBin **arv);