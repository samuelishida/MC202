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
	
	/*faz a leitura e inicializa os valores da estrutura mapa*/
	for(i=1;i<=nLinhas;i++)
		for(j=1;j<=nColunas;j++){
			scanf("%d",&m[i][j].n);
			m[i][j].i = i;
			m[i][j].j = j;
			m[i][j].rotulo = 0;
		}
		
	
	/*acha os pontos dissipadores e os coloca na fila*/
	rotular_pontos(m, f, nLinhas, nColunas);
	/*executa o algoritmo para resolver o problema*/
	calcula_lda(m, f, nLinhas, nColunas);
	
	/*imprime a saida*/
	for(i=1;i<=nLinhas;i++){
		for(j=1;j<=nColunas;j++)
			printf("%c ",m[i][j].rotulo);
		printf("\n");
	}
		
	return 0;
}

