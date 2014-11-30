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
	lista *ant;
	int mem;
	
	for(p = (*first)->prox; p ; p=p->prox)
		if(!strcmp(p->nome,nome)){
			p->aloc = false;
			break;
		}
		
	for(p = (*first)->prox; p->prox != NULL ; p = p->prox)
	{
		
		if(!(p->aloc) && !(p->prox->aloc))
		{
			
			if(p == (*first)->prox)
			{	
				(*first)->prox = p->prox;
				mem = p->n;
				free(p);
				p = (*first)->prox;
				p->n += mem;
			}
			else
			{
				printf("else if\n");
				ant->prox = p->prox;
				mem = p->n;
				free(p);
				p = ant;
				p->prox->n += mem;
			}
		}
		
		/*printf("p->nome %s %d\n",p->nome, p->n);*/
		if(!p->prox)
			return;
		
		ant = p;
	}
}

/*insere o arquivo se houver como*/
bool insere_disco(lista **first, string nome, int mem)
{
	lista *p, *aux;
	int memTotal;
	
	if(mem > (*first)->n)
		return false;
	
	p = (*first)->prox;
	memTotal = 0;
	
	if(lista_vazia(first))
	{
		if(mem <= (*first)->n)
		{
			insere_lista(first,nome,mem);
			return true;
		}
	}
	
	if(mem > (*first)->n)
		return false;
	
	while(p)
	{
		memTotal += p->n;	
		
		if(!(p->aloc))
		{
			if(p->n == mem)
			{
				strcpy(p->nome,nome);
				p->n = mem;
				p->aloc = true;
				
				return true;
			}
			else if(p->n > mem)
			{			
				aux = p->prox;
				
				p->prox = (lista *)malloc(sizeof(lista));
				p->prox->n = p->n - mem;
				p->prox->aloc = false;
				p->prox->prox = aux;
				
				strcpy(p->nome,nome);
				p->n = mem;
				p->aloc = true;	
				
				return true;
			}
		}
		else if(p->prox == NULL)
		{
			/*printf("(*first)->n = %d \nmemTotal + mem = %d\n",
				(*first)->n,memTotal+mem);*/
				
			if(memTotal + mem <= (*first)->n)
			{
				insere_lista(&p,nome,mem);
				return true;
			}
		}
		
		p = p->prox;
	}
	
	/*for(p = (*first)->prox; p != NULL; p = p->prox)
		printf("%s: %d aloc = %d\n",p->nome,p->n,(int)p->aloc);*/

	/*caso nao tenha como inserir o arquivo*/
	return false;
}

/*tira os espaços em branco da memoria*/
void otimiza(lista **first)
{
	lista *p;
	lista *ant;
	
	/*printf("otimiza1\n");*/
	
	/*cria uma lista com os nomes dos arquivos e seus respectivos tamanhos*/
	for(p = (*first)->prox; p ; p = p->prox)
	{
		
		if(!(p->aloc))
		{
			if(p == (*first)->prox)
			{
				ant = p->prox;
				free(p);
				p = ant;
			}
			else
			{
				ant->prox = p->prox;
				free(p);
				p = ant;
			}
		}
		
		ant = p;
	}
	/*printf("otimiza2\n");*/
	
	/*for(p = (*first)->prox; p != NULL; p = p->prox)
		printf("%s: %d aloc = %d\n",p->nome,p->n,(int)p->aloc);*/
	
}

void cria_disco(lista **first, string entrada)
{	
	int mem = calc_mem(entrada);
	
	*first = cria_lista(mem);
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
	int contBloco;
	int i, j;
	int bloco[8]={0}, nBlocos=0;
	double pMem;
	
	contBloco = 0;
	
	for(i=1, j=1, p = (*first)->prox; i <= ((*first)->n/8) && p ; i++, j++)
	{
		
		if(j < p->n)
			bloco[nBlocos] += p->aloc;
		else if(j == p->n){
			j = 0;
			bloco[nBlocos] += p->aloc;
			p = p->prox;
		}
		else{
			j = 0;
			p = p->prox;
		}
			
		if(i == ((*first)->n/8)){
			nBlocos++;
			i = 0;
		}
		
	}
	
	for(i=0; i<8; i++)
	{
		pMem = ((*first)->n/8.0 - bloco[i])/((*first)->n/8.0);		
		
		/*printf("%.2f",pMem);*/
		
		if(pMem > 0.75)
			printf("[ ]");
		else if(pMem > 0.25)
			printf("[-]");
		else 
			printf("[#]");
	}
	
	/*printf("\n");
	
	for(i=0; i<8; i++)
	{
		printf("%d ",bloco[i]);
	}	
	
	printf("Mem max = %d ",(*first)->n);
	
	for(p = (*first)->prox; p != NULL; p = p->prox)
		printf("\n%s: %d %d",p->nome,p->n,p->aloc);*/
	
	printf("\n");
}
