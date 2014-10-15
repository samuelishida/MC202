/*
Tarefa 4 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include <stdio.h>

#define MAX 50

/*retorna o valor do custo*/
double quick(int vet[], int tam);
/*calcula o custo individual para o pivo escolhido*/
double custoIndividual(int vet[], int tam, int pivo);
/*separa a lista dos valores menores que o pivo e a lista dos valores maiores*/
void sublistas(int vet[], int vetmenor[], int vetmaior[], int tam, int pivo, int *nMenor, int *nMaior);