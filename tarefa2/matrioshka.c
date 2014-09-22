/*
	Tarefa 2 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "matrioshka.h"

void push_back(int n, list **init)
{
	list *p = *init;
	
	while(p->next != NULL)
		p = p->next;
	
	p->next = malloc(sizeof(list));
	p->next->n = n;
	p->next->tam = 0;
	p->next->next = NULL;
	
}

bool stack_empty(list *init)
{
	return (init->next == NULL)?(true):(false);
}

void pop_back(list **init)
{
	list *p = *init;
	
	if(stack_empty(*init))
		return;
	
	while(p->next->next != NULL)
		p = p->next;
		
	free(p->next);
	p->next = NULL;
}

list *check_back(list **init)
{
	list *p = *init;
	
	if(stack_empty(*init))
		return (list*) NULL;
	
	while(p->next != NULL)
		p = p->next;
	
	return p;
}

void free_stack(list **init)
{
	while(!stack_empty(*init))
		pop_back(init);
}

void init_stack(list **init)
{
	*init = malloc(sizeof(list));
	(*init)->next = NULL;
}
