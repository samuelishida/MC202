/*
Tarefa 3 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "fila.h"

int main()
{
	Mapa m[MAX+2][MAX+2];
	Fila *f[MAX];
	int i,j;
	int nLinhas,nColunas;
	
	scanf("%d%d",&nLinhas,&nColunas);
	
	for(i=0;i<MAX;i++)
		f[i] = cria_fila();
	
	for(i=0;i<nColunas+2; i++)
		m[0][i].n = m[nLinhas+2][i].n = -1;
	
	for(i=0;i<nLinhas+2;i++)
		m[i][0].n = m[i][nColunas+2].n = -1;
	
	for(i=1;i<=nLinhas;i++)
		for(j=1;j<=nColunas;j++)
			scanf("%d",&m[i][j].n);
		
	for(i=0;i<=nLinhas+1;i++)
		for(j=0;j<=nColunas+1;j++)
			printf("%d%s",m[i][j].n,(i == nLinhas+1)?("\n"):(""));
	
	/*rotular_pontos(m, f, nLinhas, nColunas);*/
		
	return 0;
}

