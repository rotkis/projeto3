#include <stdio.h>
#include <string.h>
#include "contatos.h"


int main(){
  funcao fs[] = {criar,listar, deletar , salvar, carregar};
    Agenda pessoais[MAX_CONTATOS];
    Agenda trabalho[MAX_CONTATOS];
    int pos;
    int escolha;
    printf("Selecione a agenda que deseja usar:\n");
    printf("1- Pessoal\n");
    printf("2- Trabalho\n");
    printf("Digite o qual agenda vc deseja abrir: ");
    scanf("%d", &escolha);
    getchar(); 

    if (escolha == 1) {
        strcpy(pessoais, "pessoal.txt");
        ERROS erro_pessoal = fs[4](pessoais, &pos);
        if(erro_pessoal != OK)
      pos = 0;

  int opcao;
  do{
      printf("\nMenu principal\n");
      printf("1 - Criar Contato\n");
      printf("2 - Listar Contatos\n");
      printf("3 - Deletar Contato\n");
      printf("4 - Salvar Contatos\n");
      printf("0 - Sair\n");
      printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    clearBuffer();
    opcao--;
    if(opcao > 4)
        printf("Opcao invalida\n");
    else if(opcao >= 0)
        fs[opcao](pessoais, &pos);
    else
        printf("Sair...\n");

    } while(opcao >= 0);

    fs[3](pessoais, &pos);
    } else if (escolha == 2) {
        strcpy(trabalho, "trabalho.txt");
                ERROS erro_trabalho = fs[4](trabalho, &pos);
        if(erro_trabalho != OK)
      pos = 0;

  int opcao;
  do{
      printf("\nMenu principal\n");
      printf("1 - Criar Contato\n");
      printf("2 - Listar Contatos\n");
      printf("3 - Deletar Contato\n");
      printf("4 - Salvar Contatos\n");
      printf("0 - Sair\n");
      printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    clearBuffer();
    opcao--;
    if(opcao > 4)
        printf("Opcao invalida\n");
    else if(opcao >= 0)
        fs[opcao](trabalho, &pos);
    else
        printf("Sair...\n");

    } while(opcao >= 0);

    fs[3](trabalho, &pos);
    }
  
    }