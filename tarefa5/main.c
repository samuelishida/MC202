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
	char entrada[15];
	char nome[15];
	bool erro = false;
	
	scanf("%d",&n);
	
	while(n)
	{
		scanf("%s",entrada);
		
		cria_disco(&l,entrada);
		
		/*for(p = l; p ; p = p->prox)
			printf("%d ",p->n);*/
		
		while(n--)
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
				
				if(!erro && !insere_disco(&l,nome,calc_mem(entrada)))
				{
					otimiza(&l);
					
					if(!insere_disco(&l,nome,calc_mem(entrada)))
					{
						printf("ERRO: disco cheio\n");
						
						erro = true;
					}
				}
			}
			else if(!erro && !strcmp(entrada,"otimiza"))
				otimiza(&l);
				
			for(p = (l)->prox; p != NULL; p = p->prox)
				printf("%s: %d aloc = %d\n",p->nome,p->n,(int)p->aloc);
		}
		
		if(!erro)
			disco_status(&l);
			
		erro = false;
		
		desaloca_lista(&l);
		scanf("%d",&n);
	}
	
	
	
	return 0;
}