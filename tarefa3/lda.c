/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "lda.h"

void rotular_pontos(Mapa m[][MAX+2], Fila *f[MAX], int nLinhas, int nColunas)
{
	int i, j;
	char rotulo='a';

	for(i=1;i<=nLinhas;i++)
	{
		for(j=1;j<=nColunas;j++)
		{
			if(m[i][j].n > m[i-1][j].n && m[i][j].n > m[i][j-1].n 
			&& m[i][j].n > m[i+1][j].n && m[i][j].n > m[i][j+1].n)
			{
				m[i][j].rotulo = rotulo++;
				insere_fila(f[m[i][j].n],m[i][j].n);
			}
		}
	}
}

void calcula_lda(Mapa m[][MAX+2], Fila *f[MAX])
{
	
}

void inicia_mapa(Mapa m[][MAX+2], int nLinhas, int nColunas)
{
	int i;
	
	for(i=0;i<=nColunas+1; i++)
		m[0][i].n = m[nLinhas+1][i].n = -1;
	
	for(i=0;i<=nLinhas+1;i++)
		m[i][0].n = m[i][nColunas+1].n = -1;
}