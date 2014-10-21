/*
	Tarefa 5 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/
#include "disco.h"

int main()
{
	int n, mem;
	lista *l;
	char entrada[127];
	int j;
	
	scanf("%d",&n);
	
	while(n)
	{
		scanf("%s",entrada);
		
		mem = atoi(entrada);
		printf("mem = %d\n",mem);
		
		if(strspn(entrada,k))
			j = 1;
		else if(strspn(entrada,m))
			j = 1024;
		else 
			j = 1024*1024;
		
		printf("%d\n",j*mem);
		
		l = cria_lista(mem);
		
		while(n--)
		{
			printf("%d\n",n);
		}
		
		desaloca_lista(&l);
		scanf("%d",&n);
	}
	
	
	
	return 0;
}