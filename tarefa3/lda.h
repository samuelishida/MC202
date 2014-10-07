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
	char rotulo;
};

typedef struct Mapa Mapa;

/*acha os pontos dissipadores e os coloca na fila*/
void rotular_pontos(void **m, void **f, int nLinhas, int nColunas);
/*faz as operacoes com a fila para resolver o problema*/
void calcula_lda(void **m, void **f);
/*coloca -1 nas bordas do mapa para facilitar na determinacao dos pontos dissipadores*/
void inicia_mapa(void (*m)[MAX+2], int nLinhas, int nColunas);
