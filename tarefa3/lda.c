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
		{	/*se acchar um ponto dissipador*/
			if(m[i][j].n <= m[i-1][j].n && m[i][j].n <= m[i][j-1].n 
			&& m[i][j].n <= m[i+1][j].n && m[i][j].n <= m[i][j+1].n)
			{
				/*atribua o rotulo e depois o incremente*/
				m[i][j].rotulo = rotulo++;
				/*coloque o ponto na sua respectiva fila*/
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
	
	/*enquanto a fila ordenada nao estiver vazia*/
	while(h < MAX)
	{
		flag = true;
		/*remova o elemento de maior prioridade*/
		n = remove_fila(f[h]);
		
		/*procure o elemento no mapa*/
		for(i=1; i<=nLinhas && flag; i++)
			for(j=1; j<=nColunas && flag; j++)
				if(m[i][j].i == n.i && m[i][j].j == n.j)
					flag = false;
					
		i--;
		j--;
		
		/*verifica se esta dentro do mapa e se esta rotulado*/
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
		
		/*pega a proxima fila com maior prioridade*/
		h = filaOrd(f);
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