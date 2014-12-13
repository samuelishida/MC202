/*
	Tarefa 10 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "hash.h"

TabelaHash *CriaTabela(){
	TabelaHash *t;
	t = (TabelaHash *)calloc(13, sizeof(TabelaHash));
	return t;
}

unsigned int FuncaoHash(char *chave){
	unsigned int indice = 0, i = 0;
	
	while(chave[i])
		indice ^= chave[i++];
	
	return indice%13;
}

bool InsereTabela(TabelaHash *t, Aluno *a){
	unsigned int indice;
	Lista *p, *anteriorP;
	
	indice = FuncaoHash(a->nome);
	p = anteriorP = t[indice].Head;
	
	while(p){
		if(strcmp(p->info.nome,a->nome) == 0)
			return false;
		anteriorP = p;
		p = p->prox;
	}
	
	
	p = malloc(sizeof(Lista));
	p->info.ra = a->ra;
	p->info.nome = malloc(strlen(a->nome)+1);
	strcpy(p->info.nome,a->nome);
	p->prox = NULL;
	
	if(t[indice].Head == NULL)
		t[indice].Head = p;
	else
		anteriorP->prox = p;
	
	return true;
}

bool RemoveTabela(TabelaHash *t, char *buf){
	unsigned int indice;
	Lista *p, *anteriorP = NULL;
	
	indice = FuncaoHash(buf);
	p = t[indice].Head;
	
	while(p){
		if(strcmp(p->info.nome,buf) == 0)
			break;
		p = p->prox;
		anteriorP = p;
	}
	
	if(p == NULL)
		return false;
	else if(p->info.ra == t[indice].Head->info.ra){
		t[indice].Head = p->prox;
	}
	else{
		anteriorP->prox = p->prox;
	}
		
	free(p);
	
	return true;
}

bool ConsultaTabela(TabelaHash *t, char *buf, Aluno *a){
	unsigned int indice;
	Lista *p, *anteriorP;
	
	indice = FuncaoHash(buf);
	p = t[indice].Head;
	
	while(p){
		if(strcmp(p->info.nome,buf) == 0)
			break;
		anteriorP = p;
		p = p->prox;
	}
	
	if(p == NULL)
		return false;
	
	a->ra = p->info.ra;
	a->nome = malloc(strlen(buf)+1);
	strcpy(a->nome,buf);
	
	return true;
}

int NumeroAlunosTabela(TabelaHash *t){
	int num, i;
	Lista *p;
	
	for(i = num = 0; i < 13; i++){
		p = t[i].Head;
		while(p){
			num++;
			p = p->prox;
		}
	}
	
	return num;
}

void ImprimeTabela(TabelaHash *t){
	int i;
	Lista *p;
	
	for(i = 0; i < 13; i++){
		p = t[i].Head;
		while(p){
			printf("(%d) %06d \"%s\"\n",i,p->info.ra,p->info.nome);
			p = p->prox;
		}
	}
}

void LiberaTabela(TabelaHash *t){
	int i;
	Lista *p, *aux;
	
	for(i = 0; i < 13; i++){
		p = t[i].Head;
		while(p){
			aux = p->prox;
			free(p->info.nome);
			free(p);
			p = aux;
		}
	}
}
