/*
	Tarefa 5 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/
#include "disco.h"

int main()
{
	int n;
	lista *l;
	
	l = cria_lista(0);
	
	scanf("%d",&n);
	
	while(n)
	{

		while(n--)
		{
			scanf("%d",&n);
			printf("%d\n",n);
		}
		desaloca_lista(&l);
		scanf("%d",&n);
	}
	
	
	
	return 0;
}