/*
Tarefa 4 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "quick.h"

int main()
{
	int vet[MAX], n, i;
	double res;
	
	/*le a entrada*/
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
		scanf("%d",&vet[i]);
	/*fim da leitura*/
	
	/*res recebe o valor do custo do quick de vet*/
	res = quick(vet,n);
	
	/*imprime o resultado seguindo as especificacoes*/
	printf("%.10f\n",res);
	
	return 0;
}
