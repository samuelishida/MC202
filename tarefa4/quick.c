/*
Tarefa 4 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "quick.h"

/*calcula o custo individual para o pivo escolhido*/
double custoIndividual(int vet[], int tam, int pivo)
{
	int i;
	double custoi=0;
	
	/*conta o numero de elementos maiores que o pivo e a esquerda*/
	for(i=0; i<pivo; i++)
		if(vet[i] > vet[pivo])
			custoi++;
	/*conta o numero de elementos menores que o pivo e a direita*/
	for(i=pivo+1; i<tam; i++)
		if(vet[i] < vet[pivo])
			custoi++;
	/*retorna o custo individual*/
	return custoi;
}

/*separa a lista dos valores menores que o pivo e a lista dos valores maiores*/
void sublistas(int vet[], int vetmenor[], int vetmaior[], int tam, int pivo, int *nMenor, int *nMaior)
{
	int i;
	
	for(i=0; i<tam; i++)
	{
		if(vet[i] > vet[pivo])
			vetmaior[(*nMaior)++] = vet[i];
			
		else if(vet[i] < vet[pivo])
			vetmenor[(*nMenor)++] = vet[i];
	}
}

/*retorna a valor do custo*/
double quick(int vet[], int tam)
{	
	int vetmenor[MAX-1], vetmaior[MAX-1], pivo, nMenor, nMaior;
	double custo=0;
	
	/*se o tamanho for 0 ou 1, nao ha custo operacional*/
	if(tam < 2)
		return 0;
	/*se for 2, tem que analisar se tem ou nao que realizar uma troca, que custa 1*/
	if(tam == 2)
	{
		if(vet[0] < vet[1])
			return 0;
		else
			return 1;
	}
	/*seleciona cada numero como pivo*/
	for(pivo=0; pivo<tam; pivo++)
	{
		nMenor = nMaior = 0;
		/*separa os elementos de vet em elementos maiores e menores que o pivo*/
		sublistas(vet,vetmenor,vetmaior,tam,pivo,&nMenor,&nMaior);
		/*incrementa o custo total com o custo individual mais o custo do quick dos valores menores e dos maiores*/
		custo += custoIndividual(vet,tam,pivo) + quick(vetmenor,nMenor) + quick(vetmaior,nMaior);
	}
	/*retorna a media dos custos*/
	return custo/tam;
}