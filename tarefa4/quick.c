/*
Tarefa 4 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "quick.h"
 
double quick(int vet[], int tam)
{	
	int vetmenor[MAX-1], vetmaior[MAX-1], pivo, nMenor, nMaior, i;
	double custo;
	
	if(tam < 2)
		return 0;
		
	if(tam == 2)
	{
		if(vet[0] < vet[1])
			return 0;
		else
			return 1;
	}
	
	for(pivo=0; pivo<tam; i++)
	{
		nMenor = nMaior = 0;
		
		for(i=0; i<pivo; i++)
			if(vet[i] > vet[pivo])
				vetmaior[nMaior++] = vet[i];
		
		for(i=tam-1; i>pivo; i++)
			if(vet[i] < vet[pivo])
				vetmenor[nMenor++] = vet[i];
			
		custo += nMenor + nMaior + quick(vetmenor,nMenor) + quick(vetmaior,nMaior);
	}
	
	return custo/tam;
}