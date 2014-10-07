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
	char rotulo = 'a';

	for(i=1;i<=nLinhas;i++)
	{
		for(j=1;j<=nColunas;j++)
		{
			if(m[i][j].n < m[i-1][j].n && m[i][j].n < m[i][j-1].n 
			&& m[i][j].n < m[i+1][j].n && m[i][j].n < m[i][j+1].n)
			{
				m[i][j].rotulo = rotulo++;
				insere_fila(f[m[i][j].n],m[i][j]);
			}
		}
	}
}

void calcula_lda(Mapa m[][MAX+2], Fila *f[MAX], int nLinhas, int nColunas)
{
	int i, j, h;
	bool flag;
	Mapa n;
	
	h = filaOrd(f);
	
	while(h < MAX)
	{
		flag = true;
		n = remove_fila(f[h]);
		
		/*for(i=0; i<=9; i++){
			printf("f[%d] = ",i);
			for(j=f[i]->inicio%MAX; j<f[i]->fim%MAX; j++)
				printf("%d ",f[i]->ponto[j].n);
			printf("\n");
		}*/
		
		for(i=1; i<=nLinhas && flag; i++)
			for(j=1; j<=nColunas && flag; j++)
				if(m[i][j].i == n.i && m[i][j].j == n.j)
					flag = false;
					
		i--;
		j--;
		
		/*printf("m[%d,%d] %d  n.i %d n.j %d\n",i,j,m[i][j].n,n.i,n.j);*/
		
		if(m[i-1][j].n < MAX && !m[i-1][j].rotulo){
			m[i-1][j].rotulo = n.rotulo;
			insere_fila(f[m[i-1][j].n],m[i-1][j]);
		}
		if(m[i][j-1].n < MAX && !m[i][j-1].rotulo){
			m[i][j-1].rotulo = n.rotulo;
			insere_fila(f[m[i][j-1].n],m[i][j-1]);
		}
		if(m[i+1][j].n < MAX && !m[i+1][j].rotulo){
			m[i+1][j].rotulo = n.rotulo;
			insere_fila(f[m[i+1][j].n],m[i+1][j]);
		}
		if(m[i][j+1].n < MAX && !m[i][j+1].rotulo){
			m[i][j+1].rotulo = n.rotulo;
			insere_fila(f[m[i][j+1].n],m[i][j+1]);
		}
		
		h = filaOrd(f);
		
		/*for(i=0;i<=nLinhas+1;i++){
			for(j=0;j<=nColunas+1;j++)
				printf("%c ",m[i][j].rotulo);
			printf("\n");
		}*/
	}
}

void inicia_mapa(Mapa m[][MAX+2], int nLinhas, int nColunas)
{
	int i;
	
	for(i=0;i<=nColunas+1; i++)
		m[0][i].n = m[nLinhas+1][i].n = MAX;
	
	for(i=0;i<=nLinhas+1;i++)
		m[i][0].n = m[i][nColunas+1].n = MAX;
}

int filaOrd(Fila *f[MAX])
{
	int i;
	
	for(i=0; i<MAX ; i++)
		if(!fila_vazia(f[i]))
			break;
			
	return i;
}