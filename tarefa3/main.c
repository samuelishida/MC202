/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "lda.h"

int main()
{
	Mapa m[MAX][MAX];
	Fila *f;
	int i,j;
	int nLinhas,nColunas;
	
	scanf("%d",&nLinhas,&nColunas);
	
	for(i=0;i<nLinhas;i++)
		for(j=0;j<nColunas;j++)
			scanf("%d",&m[i][j].n);
		
	return 0;
}