/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "lda.h"

int main()
{
	Mapa m[MAX+2][MAX+2];
	Fila *f[MAX];
	int i,j;
	int nLinhas,nColunas;
	
	scanf("%d%d",&nLinhas,&nColunas);
	
	for(i=0;i<MAX;i++)
		f[i] = cria_fila();
	
	inicia_mapa(m,nLinhas,nColunas);
	
	for(i=1;i<=nLinhas;i++)
		for(j=1;j<=nColunas;j++){
			scanf("%d",&m[i][j].n);
			m[i][j].i = i;
			m[i][j].j = j;
		}
		
	for(i=0;i<=nLinhas+1;i++){
		for(j=0;j<=nColunas+1;j++)
			printf("%3d ",m[i][j].n);
			
			printf("\n");
	}
	
	rotular_pontos(m, f, nLinhas, nColunas);
	calcula_lda(m, f, nLinhas, nColunas);
	
	for(i=0;i<=nLinhas+1;i++){
		for(j=0;j<=nColunas+1;j++)
			printf("%c ",m[i][j].rotulo);
			
			printf("\n");
	}
		
	return 0;
}

