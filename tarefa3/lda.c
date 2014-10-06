/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "fila.h"

void rotular_pontos(void **m, void **f, int nLinhas, int nColunas)
{
	int i, j;
	char rotulo='a';
	Mapa **mapa = (Mapa **) m;
	Fila **fila = (Fila **) f;
	
	for(i=0;i<nLinhas;i++)
	{
		for(j=0;j<nColunas;j++)
		{
			if(mapa[i][j].n > mapa[i-1][j].n && mapa[i][j].n > mapa[i][j-1].n) 
			&& mapa[i][j].n > mapa[i+1][j].n && mapa[i][j].n > mapa[i][j+1].n)
			{
				mapa[i][j].rotulo = rotulo++;
				insere_fila(f[mapa[i][j].n]->fim);
			}
		}
	}
}

void calcula_lda(void **m, void **f)
{
	
}
