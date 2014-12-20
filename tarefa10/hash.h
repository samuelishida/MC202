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

/*aloca a tabela*/
TabelaHash *CriaTabela();
/*funcao que dado a chave retorna o indice*/
unsigned int CodigoHash(char *chave);
/*insere uma chave na tabela, se der certo retorna true*/
bool InsereTabela(TabelaHash *t, Aluno *a);
/*remove uma chave na tabela, se der certo retorna true*/
bool RemoveTabela(TabelaHash *t, char *buf);
/*retorna true se existe a chave e false se nao existe*/
bool ConsultaTabela(TabelaHash *t, char *buf, Aluno *a);
/*conta o numero de alunos que tem na tabela inteira*/
int NumeroAlunosTabela(TabelaHash *t);
/*realiza a impressao da tabela*/
void ImprimeTabela(TabelaHash *t);
/*libera a memoria alocada para a tabela*/
void LiberaTabela(TabelaHash *t);
/*troca dois elementos consecutivos de uma lista*/
void troca(Lista *x, Lista *y);
/*ordena a lista em ordem alfabetica*/
void ordena(Lista *lista);


