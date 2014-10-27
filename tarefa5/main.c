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
	lista *l, *p;
	char entrada[127];
	char nome[127];
	bool erro = false;
	
	scanf("%d",&n);
	
	while(n)
	{
		scanf("%s",entrada);
		
		cria_disco(&l,entrada);
		
		/*for(p = l; p ; p = p->prox)
			printf("%d ",p->n);*/
		
		while(n-- && !erro)
		{
			scanf("%s",entrada);
			
			if(!strcmp(entrada,"remove"))
			{
				scanf("%s",entrada);
				if(!erro)
					remove_disco(&l,entrada);
			}
			else if(!strcmp(entrada,"insere"))
			{
				scanf("%s",nome);
				scanf("%s",entrada);
				
				if(!insere_disco(&l,nome,calc_mem(entrada)) && !erro)
				{
					otimiza(&l);
					
					if(!insere_disco(&l,nome,calc_mem(entrada)))
					{
						printf("ERRO: disco cheio\n");
						
						erro = true;
					}
				}
			}
			else if(!strcmp(entrada,"otimiza") && !erro)
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