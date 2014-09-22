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

void push_back(int n,list **init);
void pop_back(list **init);
bool stack_empty(list *init);
list *check_back(list **init);
void free_stack(list **init);
void init_stack(list **init);