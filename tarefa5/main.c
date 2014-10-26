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
	char entrada[127];
	char nome[127];
	bool erro = false;
	
	scanf("%d",&n);
	
	while(n)
	{
		scanf("%s",entrada);
		
		cria_disco(&l,entrada);
		
		while(n-- && erro)
		{
			scanf("%s",entrada);
			
			if(!strcmp(entrada,"remove"))
			{
				scanf("%s",entrada);
				remove_disco(&l,entrada);
			}
			else if(!strcmp(entrada,"insere"))
			{
				scanf("%s",nome);
				scanf("%s",entrada);
				
				if(!insere_disco(&l,nome,calc_mem(entrada)))
				{
					otimiza(&l);
					
					if(!insere_disco(&l,nome,calc_mem(entrada)))
					{
						printf("ERRO: disco cheio\n");
						
						erro = true;/*desconsidera o resto da entrada*/
					}
				}
			}
			else if(!strcmp(entrada,"otimiza"))
				otimiza(&l);
		}
		
		if(!erro)
			disco_status(&l);
			
		erro = false;
		
		desaloca_lista(&l);
		scanf("%d",&n);
	}
	
	
	
	return 0;
}