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

/*a arvore em questao so quarda quem eh o pai, 
pois a implementacao de arvore geral 
fica mais simples e para o problema, so eh 
necessario saber o pai de cada no*/

typedef struct Arvore {
    int n;
    struct Arvore *pai;
} Arvore, NoArv;

Arvore *criaArvore();
Arvore **criaFloresta(int numArvs);
int lca(int a, int b, Arvore **floresta, int numArvs);
void link(int a, int b, Arvore **floresta);
void cut(int a, Arvore **floresta);
void liberaArv(Arvore *arv);
void liberaFloresta(Arvore **floresta, int numArvs);
