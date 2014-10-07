/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/


#include "fila.h"

struct Mapa{
	int n;
	char rotulo;
};

typedef struct Mapa Mapa;

/*acha os pontos dissipadores e os coloca na fila*/
void rotular_pontos(Mapa m[][MAX+2], Fila *f[MAX], int nLinhas, int nColunas);
/*faz as operacoes com a fila para resolver o problema*/
void calcula_lda(Mapa m[][MAX+2], Fila *f[MAX], int nLinhas, int nColunas);
/*coloca 101 nas bordas do mapa para facilitar na determinacao dos pontos dissipadores*/
void inicia_mapa(Mapa m[][MAX+2], int nLinhas, int nColunas);
bool filaOrd_vazia(Fila *f[MAX]);
