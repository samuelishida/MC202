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
	
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
		scanf("%d",&vet[i]);
	
	res = quick(vet,n);
	
	printf("%f\n",res);
	
	return 0;
}
