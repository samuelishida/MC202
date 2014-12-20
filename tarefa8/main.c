/*
	Tarefa 8 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "arvore.h"

int main()
{
	int numArvs, numOp, a, b;
	char in[7];
	Arvore **floresta;
	
	scanf("%d%d",&numArvs,&numOp);
	
	/*cria um vetor que contem as raizes das arvores*/
	floresta = criaFloresta(numArvs);
	
	/*le as N operacoes e chama as respectivas funcoes*/
	while(numOp--){
		scanf("%s%d", in, &a);
		if(!strcmp(in,"link")){
			scanf("%d",&b);
			link(a-1,b-1,floresta);
		}
		else if(!strcmp(in,"lca")){
			scanf("%d",&b);
			printf("%d\n",lca(a-1,b-1,floresta,numArvs)+1);
		}
		else{
			cut(a-1,floresta);
		}
	}
	
	/*desaloca a memoria*/
	liberaFloresta(floresta, numArvs);
	
	return 0;
}