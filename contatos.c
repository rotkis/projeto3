#include "contatos.h" //incluir o arquivo contatos.h
#include <stdio.h>
#include <string.h>

ERROS criar(Agenda contatos[], int *pos) {
  if (*pos >= TOTAL)
    return MAX_CONTATO;
  clearBuffer();
  printf("Digite o nome: "); // NOME
  fgets(contatos[*pos].nome, NOME, stdin);
  contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';

  printf("Digite o sobrenome: ");//Sobrenome
  fgets(contatos[*pos].sobrenome, SOBRENOME, stdin);
  contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome, "\n")] = '\0';

  printf("Digite seu Telefone: ");//Telefone
  fgets(contatos[*pos].telefone, TELEFONE, stdin);
  contatos[*pos].telefone[strcspn(contatos[*pos].telefone, "\n")] = '\0';

  printf("Digite seu Email: "); //Email
  fgets(contatos[*pos].email, EMAIL, stdin);
  contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';

  *pos = *pos + 1;
  return OK;
}
ERROS deletar(Agenda contatos[], int *pos) {}

ERROS listar(Agenda contatos[], int *pos) {}

ERROS salvar(Agenda contatos[], int *pos) {}

ERROS carregar(Agenda contatos[], int *pos) {}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}