/*
	Tarefa 10 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#define TAMMAXNOME 100 /*tamanho máximo de nome de aluno*/

/* Definicao do tipo aluno*/
typedef struct Aluno{
	int ra;
	char *nome;
} Aluno;

/* Definicao do tipo Lista */
typedef struct Lista{
	Aluno info;
	struct Lista *prox;
} Lista;

/* A tabela hash eh um vetor de listas ligadas que guarda o no cabeca*/
typedef struct TabelaHash{
	Lista *Head;
} TabelaHash;

TabelaHash *CriaTabela();
unsigned int CodigoHash(char *chave);
bool InsereTabela(TabelaHash *t, Aluno *a);
bool RemoveTabela(TabelaHash *t, char *buf);
bool ConsultaTabela(TabelaHash *t, char *buf, Aluno *a);
int NumeroAlunosTabela(TabelaHash *t);
void ImprimeTabela(TabelaHash *t);
void LiberaTabela(TabelaHash *t);


