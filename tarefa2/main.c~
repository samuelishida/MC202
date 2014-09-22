/*
	Tarefa 2 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "matrioshka.h"

int main()
{
	int n, in, i;
	bool flag = true;
	list *stack,*back;
	
	scanf("%d",&n);
	init_stack(&stack);
	back = NULL;
	
	while(n)
	{
		for(i=0 ; i<n ; i++)
		{
			scanf("%d",&in);
			
			/*caso nao seja uma matrioskha, eh possivel que tenha sobrado conteudo na entrada padrao*/
			if(flag)
			{
				/*caso seja o brinquedo que fecha o q esta no topo da pilha*/
				if(back && back->n < 0 &&  back->n == -in)
				{
					pop_back(&stack);
					
					if(!stack_empty(stack))
					{
						back = check_back(&stack);
						back->tam+=in;/*incrementa o tamanho acumulado naquele brinquedo*/
						
						/*caso nao atenda a condicao do tamanho, pare de considerar a leitura*/
						if(back->tam >= -back->n)
							flag  = false;
					}
				}
				else
					push_back(in,&stack);
				
				back = check_back(&stack);
			}
		}
		
		printf("%s\n",(stack_empty(stack))?(":-) Matrioshka!"):(":-( Tente novamente."));
		
		/*reinicializa as variaveis para nova operacao*/
		free_stack(&stack);
		flag = true;
		back = NULL;
		
		scanf("%d",&n);
	}
	
	return 0;
}