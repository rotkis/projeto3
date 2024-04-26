#include <stdio.h>
#include <string.h>
#include "contatos.h"

int main(){
  funcao fs[] = {criar,listar, deletar , salvar, carregar};

  Agenda contatos[TOTAL];
  int pos;
  ERROS erro = fs[4](contatos, &pos);
  if(erro != OK)
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
        fs[opcao](contatos, &pos);
    else
        printf("Sair...\n");

    } while(opcao >= 0);

    fs[3](contatos, &pos);
    }