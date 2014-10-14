/*
Tarefa 4 de MC202
Aluno: Samuel Toyoshi Ishida
RA: 160250
Turma A
*/

#include "quick.h"
 
double quick(int vet[], int tam)
{	
	int vetmenor[MAX-1], vetmaior[MAX-1], pivo, nMenor, nMaior, i, custoi;
	double custo=0;
	
	printf("tam = %d\n",tam);
	
	if(tam < 2)
		return 0;
		
	if(tam == 2)
	{
		if(vet[0] < vet[1])
			return 0;
		else
			return 1;
	}
	
	for(pivo=0; pivo<tam; pivo++)
	{
		nMenor = nMaior = custoi = 0;
		
		printf("pivo = %d\n",pivo);
				
		for(i=0; i<pivo; i++)
			if(vet[i] > vet[pivo])
				custoi++;
		

		for(i=pivo+1; i<tam; i++)
			if(vet[i] < vet[pivo])
				custoi++;
		
		for(i=0; i<tam; i++)
		{
			if(vet[i] > vet[pivo])
				vetmaior[nMaior++] = vet[i];
				
			else if(vet[i] > vet[pivo])
				vetmenor[nMenor++] = vet[i];
		}
	
		
		for(i=0; i<nMenor; i++)
			printf("%d ",vetmenor[i]);
		
		printf("\n");
		
		for(i=0; i<nMaior; i++)
			printf("%d ",vetmaior[i]);
		
		printf("\n");
		
			
		custo += custoi + quick(vetmenor,nMenor) + quick(vetmaior,nMaior);
	}
	
	return custo/tam;
}