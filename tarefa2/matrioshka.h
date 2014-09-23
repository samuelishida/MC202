/*
	Tarefa 2 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list list;

struct list{
	int n;
	int tam;
	list *next;
};

void push_back(int n,list **head);
void pop_back(list **head);
bool stack_empty(list *head);
list *check_back(list **head);
void free_stack(list **head);
void init_stack(list **head);