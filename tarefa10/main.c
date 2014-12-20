/*
	Tarefa 10 de MC202
	Aluno: Samuel Toyoshi Ishida
	RA: 160250
	Turma A
*/

#include "hash.h"

/*le RA e nome de aluno*/
void LeAluno(Aluno *a) {
   char buf[TAMMAXNOME];
   scanf("%d \"%[^\"]\"", &a->ra, buf);

   a->nome = malloc(strlen(buf)+1);
   strcpy(a->nome, buf);
   return;
}

/*le linha de comando*/
void lelinha() {
   int c;
   do { c= getchar(); } while (c!='\n');
}

int main(int argc, char *argv[]) {

   TabelaHash *t = CriaTabela();
   char comando[100], buf[TAMMAXNOME];
   Aluno a;  

   /*loop para ler entrada*/
   while ( scanf("%s", comando) > 0 ) {
      if ( strcmp(comando,"insere") == 0 ) {

	 LeAluno(&a);
	 printf("Insere: %06d \"%s\"\n", a.ra, a.nome);
	 if (!InsereTabela(t, &a)) {	/*insere aluno 'a' na tabela 't'*/
	    printf("Nome repetido: \"%s\"\n", a.nome);
	    free(a.nome);
	 }

      } else if ( strcmp(comando, "remove") == 0 ) {

	 scanf(" \"%[^\"]\"", buf);
	 printf("Remove: \"%s\"\n", buf);
	 if (!RemoveTabela(t, buf))	/*remove aluno de nome 'buf' da tabela 't'*/
	    printf("Nome inexistente: \"%s\"\n", buf);

      } else if ( strcmp(comando, "consulta") == 0 ) {

	 scanf(" \"%[^\"]\"", buf);
	 printf("Consulta: \"%s\"\n", buf);
	 if (ConsultaTabela(t, buf, &a)) 
	/*consulta aluno de nome 'buf' na tabela 't', grava dados em 'a', retorna 0 se nao encontrou aluno*/
	    printf("%06d \"%s\"\n", a.ra, a.nome);
	 else
	    printf("Nome inexistente: \"%s\"\n", buf);

      } else if ( strcmp(comando, "imprime") == 0 ) {

	 printf("\nImprime Tabela: %d aluno(s):\n", NumeroAlunosTabela(t)); /*Calcula numero de alunos na tabela 't'*/
	 ImprimeTabela(t);
	 printf("\n");
      } else if ( strcmp(comando, "sair") == 0 ) { /*termina programa*/
			break;
      } else {
	 printf("Comando desconhecido: `%sŽ\n", comando);
      }
   }

   LiberaTabela(t); /*libera memoria*/

   return 0;
}
