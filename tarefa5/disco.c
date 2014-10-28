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
	
	for(p = (*first)->prox; p ; p=p->prox)
		if(!strcmp(p->nome,nome)){
			p->aloc = false;
			return;
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
		
		if(p->prox == NULL)
		{
			/*printf("(*first)->n = %d \nmemTotal + mem = %d\n",
				(*first)->n,memTotal+mem);*/
				
			if(memTotal + mem <= (*first)->n)
			{
				insere_lista(&p,nome,mem);
				return true;
			}
		}
		else if(!(p->aloc))
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
	
	/*cria uma lista com os nomes dos arquivos e seus respectivos tamanhos*/
	for(p = (*first)->prox; p ; p = p->prox)
	{
		if(!(p->aloc))
		{
			ant->prox = p->prox;
			free(p);
			p = ant;
		}
		
		ant = p;
	}
	
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
	int i;
	int bloco[8]={0}, nBlocos=0;
	double pMem;
	
	contBloco = 0;
	
	for(p = (*first)->prox; p != NULL; p = p->prox)
	{
		contBloco = p->n;
		
		/*se ele passou do bloco*/
		while(contBloco >= (*first)->n/8)
		{
			bloco[nBlocos++] = (p->aloc)*(*first)->n/8;
			contBloco -= (*first)->n/8;
		}
		if(contBloco > 0)
		{
			if(bloco[nBlocos] + (p->aloc)*(contBloco) <= (*first)->n/8)
				bloco[nBlocos] += (p->aloc)*(contBloco);
			else 
			{
				bloco[nBlocos+1] = bloco[nBlocos] + contBloco;
				bloco[nBlocos] =  (*first)->n/8;
				bloco[nBlocos+1] %= (*first)->n/8;
				nBlocos++;
			}
		}
	}
	
	for(i=0; i<8; i++)
	{
		pMem = (bloco[i]-(*first)->n/8.0)/((*first)->n/8.0);		
		
		if(pMem > 0.75)
			printf("[ ]");
		else if(pMem > 0.25)
			printf("[-]");
		else 
			printf("[#]");
	}
	
	printf("\n");
	
	for(i=0; i<8; i++)
	{
		printf("%d ",bloco[i]);
	}	
	
	printf("Mem max = %d ",(*first)->n);
	
	for(p = (*first)->prox; p != NULL; p = p->prox)
		printf("\n%s: %d",p->nome,p->n);
	
	printf("\n");
}
