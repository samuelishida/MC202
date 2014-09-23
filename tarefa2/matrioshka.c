/*
	Tarefa 2 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "matrioshka.h"

void push_back(int n, list **head)
{
	list *p;
	
	p = malloc(sizeof(list));
	p->n = n;
	p->tam = 0;
	
	p->next = (*head)->next;
	(*head)->next = p;
	
}

bool stack_empty(list *head)
{
	return (head->next == NULL)?(true):(false);
}

void pop_back(list **head)
{
	list *p = *head;
	
	if(stack_empty(*head))
		return;
	
	p = (*head)->next->next;
		
	free((*head)->next);
	
	(*head)->next = p;
}

list *check_back(list **head)
{
	return (*head)->next;
}

void free_stack(list **head)
{
	while(!stack_empty(*head))
		pop_back(head);
}

void init_stack(list **head)
{
	*head = malloc(sizeof(list));
	(*head)->next = NULL;
}
