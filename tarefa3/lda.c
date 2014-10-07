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
	
	for(i=1;i<=nLinhas;i++)
	{
		for(j=1;j<=nColunas;j++)
		{
			if(mapa[i][j].n > mapa[i-1][j].n && mapa[i][j].n > mapa[i][j-1].n 
			&& mapa[i][j].n > mapa[i+1][j].n && mapa[i][j].n > mapa[i][j+1].n)
			{
				mapa[i][j].rotulo = rotulo++;
				insere_fila(fila[mapa[i][j].n],mapa[i][j]);
			}
		}
	}
}

void calcula_lda(void **m, void **f)
{
	
}

void inicia_mapa(void (*m)[MAX+2], int nLinhas, int nColunas)
{
	int i;
	Mapa **mapa = (Mapa **) m;
	
	for(i=0;i<=nColunas+1; i++)
		mapa[0][i].n = mapa[nLinhas+1][i].n = -1;
	
	for(i=0;i<=nLinhas+1;i++)
		mapa[i][0].n = mapa[i][nColunas+1].n = -1;
}