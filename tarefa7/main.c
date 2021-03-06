
/* Nome: Samuel Toyoshi Ishida
 * RA: 160250
 * Laboratorio 07 - Cobertura de Conjuntos */

#include "cobertura.h"


int main()
{
   int i, tamUniverso, tamResp=0;
   int nSub, valor, pos;
   char c;
   ArvoreBin *U, *M, *R, **arvs;
   int resp[255];
   bool flag = true;

	scanf("%d %d", &tamUniverso, &nSub);

	criaUniverso(&U,tamUniverso);
	
   /* aloca o vetor de arvores que guarda os subconjubntos */
   arvs = (ArvoreBin **) malloc(nSub * sizeof(ArvoreBin *));
   
    /* le os subconjuntos */
   for(i = 0; i < nSub; i++){
       arvs[i] = criaArvoreBin();
       scanf("%c%c",&c,&c);
       do{
           scanf("%d%c", &valor, &c);
           insereNo(valor, &arvs[i]);    
       }while(c != '\n');
   }
   
   R = criaArvoreBin();
   resp[0] = '\0';

   /* Algoritmo guloso */
	while(U != NULL && flag)
	{
      /*acha M*/
		for(i = pos = 0; i < nSub; i++)
			if(arvs[i] && numNos(arvs[i]) >= numNos(arvs[pos]))
				pos = i;

      M = arvs[pos];

      
      /*C = C \ M*/
      for(i=0; i<nSub; i++)
			if(i != pos && arvs[i])
				removeConjunto(M,&arvs[i]);
				
		/*U = U \ M*/
		removeConjunto(M,&U);
		
		/*R = R U M*/
		uneConjuntos(M,&R);
		
		/*remove M de S*/
		freeArvBin(&arvs[pos]);
		arvs[pos] = NULL;
		
		resp[tamResp] = pos+1;
		tamResp++;

		flag = false;
		
		for(i = 0; i<nSub && !flag; i++)
			if(arvs[i] != NULL)
				flag = true;
		
	}
	
	/* imprime resultado */
	if(numNos(R) == tamUniverso){
		for(i = 0; i < tamResp; i++){
			printf("S%d ", resp[i]);
				if(i != tamResp-1)
					printf("U ");
		}
		printf(":)\n");
	}
	else
		printf(":(\n");
			
	freeArvBin(&U);
	free(arvs);
	
	return 0;
}