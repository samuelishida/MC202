/*
	Tarefa 5 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "disco.h"

/*remove o arquivo da memoria*/
void remove_disco(lista **first, string nome)
{
	lista *p = (*first)->prox;
	
	printf("--remove\n");
	
	for(p = (*first)->prox; p ; p=p->prox)
		if(!strcmp(p->nome,nome))
			strcpy(p->nome,"");
}

/*insere o arquivo se houver como*/
bool insere_disco(lista **first, string nome, int mem)
{
	lista *p, *ant;
	lista *init;
	lista *aux;
	int i;
	
	printf("--insere\n");
	
	if(mem > (*first)->n)
		return false;
	
	p = init = (*first)->prox;
	
	while(p)
	{
		/*se trocou o bloco*/
		/*if( !((p->n) % ( (*first)->n )/8) )
			init = p;/*recomeca a verificao de memoria livre*/
		
			
		/*se acabar o bloco livre*/
		if(!strcmp(init->nome,"") && (strcmp(p->nome,"") || p->prox == NULL))		
		{
			aux = init;
			/*printf("p->n = %d  init->n = %d\n",p->n, init->n);*/
			
			/* insere em um bloco livre de memoria se for possivel*/
			if(p->n - init->n + (p->prox == NULL) >= mem && (init->n + mem) <= ((*first)->n))
			{
				for(i = 0; i < mem ; i++)
				{
					strcpy(aux->nome,nome);
					aux = aux->prox;
				}
				return true;
			}
			else /*reseta a contagem do bloco*/
				init = p;
		}
		/*caso estava varrendo um arquivo*/
		else if(strcmp(init->nome,"") && !strcmp(p->nome,""))
			init = p;/*recomeca a verificao de memoria livre*/
			
		ant = p;
		p = p->prox;
	}
	
	for(p = (*first)->prox; p != NULL; p = p->prox)
		printf("%d: %s\n",p->n,p->nome);
	
	/*caso nao tenha como inserir o arquivo*/
	return false;
}

/*tira os espaços em branco da memoria*/
void otimiza(lista **first)
{
	lista *p;
	lista *arqs;
	lista *init;
	
	arqs = cria_lista(0);
	
	printf("--otimiza\n");
	
	/*cria uma lista com os nomes dos arquivos e seus respectivos tamanhos*/
	for(p = init = (*first)->prox; p ; p = p->prox)
	{
		if(strcmp(p->nome,init->nome))
		{
			/*caso estava varrendo um arquivo*/
			if(strcmp(init->nome,""))
				insere_lista(&arqs,init->nome,p->n-init->n);
				
			init = p;
		}
	}
	
	for(p = arqs; p ; p = p->prox)
		printf("-> %s\n",p->nome);
	
	/* limpa o disco para realocar os arquivos*/
	for(p = (*first)->prox; p ; p = p->prox)
		strcpy(p->nome,"");
	
	/*realoca os arquivos*/
	for(p = arqs->prox; p ; p = p->prox)
		insere_disco(first,p->nome,p->n);
	
	desaloca_lista(&arqs);
}

void cria_disco(lista **first, string entrada)
{	
	int mem = calc_mem(entrada), i;
	lista *p;
	
	printf("--cria_disco\n");
	
	*first = cria_lista(mem);
	p = insere_lista(first,"",0);
	
	for(i=1; i<mem; i++){
		
		insere_lista(&p,"",i);
		p = p->prox;
	}

}

int calc_mem(string entrada)
{
	int mem = atoi(entrada);
		
	if(strpbrk(entrada,"M"))
		mem *= 1024;
	else if(strpbrk(entrada,"G"))
		mem *= 1024*1024;
	
	return mem;
}

void disco_status(lista **first)
{
	lista *p;
	double cont = 0;
	
	printf("--status\n");
	
	for(p = (*first)->prox; p != NULL; p = p->prox)
	{
		/*se acabou o bloco*/
		if( !((p->n+1) % (((*first)->n)/8)))
		{
			/*ve o quanto de memoria foi ocupada no bloco e imprime*/
			if(8*cont/(double)((*first)->n ) <= 0.25)
				printf("[ ]");
			else if(8*cont/(double)((*first)->n ) <= 0.75)
				printf("[-]");
			else
				printf("[#]");
			
			cont = 0;
		}
		else if (!strcmp(p->nome,""))/*se for memoria livre*/
			cont++;
	}
	
	for(p = (*first)->prox; p != NULL; p = p->prox)
		printf("\n%d: %s",p->n,p->nome);
	
	printf("\n");
}
