/*
	Tarefa 1 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/
#include "lista.h"

int main()
{
	int n, i, nReq, req, fc_count, tr_count, mtf_count;
	lista *arq[3];
	
	fc_count = tr_count = mtf_count = 0;
	
	scanf("%d %d",&n, &nReq);
	
	/*cria tres listas para serem manipuladas*/
	arq[0] = init_lista(n);
	arq[1] = init_lista(n);
	arq[2] = init_lista(n);

	for(i=0; i<nReq; i++)
	{
		scanf("%d",&req);
		
		mtf_count += mtf(req,n,&arq[0]);
		
		tr_count += tr(req,n,&arq[1]);
		
		fc_count += fc(req,n,&arq[2]);
	}
	
	printf("%d %d %d\n",mtf_count, tr_count, fc_count);
	
	/*desaloca a memoria alococada pelo programa*/
	desaloca_lista(&arq[0]);
	desaloca_lista(&arq[1]);
	desaloca_lista(&arq[2]);
	
	return 0;
}