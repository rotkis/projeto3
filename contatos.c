#include "contatos.h" //incluir o arquivo contatos.h
#include <stdio.h>
#include <string.h>

ERROS criar(Agenda contatos[], int *pos) {
  if (*pos >= TOTAL)
    return MAX_CONTATO;

  printf("Digite o nome(20 caracteres no maximo): "); // NOME
  fgets(contatos[*pos].nome, NOME, stdin);
  contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';

  printf("Digite o sobrenome(25 caracteres no maximo): "); // Sobrenome
  fgets(contatos[*pos].sobrenome, SOBRENOME, stdin);
  contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome, "\n")] = '\0';

  printf("Digite seu Telefone(11 caracteres no maximo): "); // Telefone
  fgets(contatos[*pos].telefone, TELEFONE, stdin);
  contatos[*pos].telefone[strcspn(contatos[*pos].telefone, "\n")] = '\0';

  printf("Digite seu Email(11 caracteres no maximo): "); // Email
  fgets(contatos[*pos].email, EMAIL, stdin);
  contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';

  *pos = *pos + 1;
  return OK;
}
ERROS deletar(Agenda contatos[], int *pos) {
  int i, j;
  char telefone[TELEFONE];
  printf("Digite o telefone do contato que deseja deletar: ");
  fgets(telefone, TELEFONE, stdin);
  telefone[strcspn(telefone, "\n")] = '\0';
  for (i = 0; i < *pos; i++) {
    int num = strcmp(telefone, contatos[i].telefone);
    if (num == 0) {
      for (j = i; j < *pos - 1; j++) {
        strcpy(contatos[j].nome, contatos[j + 1].nome);
        strcpy(contatos[j].sobrenome, contatos[j + 1].sobrenome);
        strcpy(contatos[j].telefone, contatos[j + 1].telefone);
        strcpy(contatos[j].email, contatos[j + 1].email);
      }
      *pos = *pos - 1;
      return OK;
    }
  }

  return NAO_ENCONTRADO;
}

ERROS listar(Agenda contatos[], int *pos) {
  if (*pos == 0)
    return SEM_CONTATO;
  for (int i = 0; i < *pos; i++) {
    printf("Pos: %d\n", i + 1);
    printf("\nNome: %s\n", contatos[i].nome);
    printf("Sobrenome: %s\n", contatos[i].sobrenome);
    printf("Telefone: %s\n", contatos[i].telefone);
    printf("Email: %s\n\n", contatos[i].email);
  }
  return OK;
}

ERROS salvar(Agenda contatos[], int *pos) {
  FILE *arquivo = fopen("contatos.bin", "wb");
  if (arquivo == NULL)
    return ABRIR;

  size_t gravados = fwrite(contatos, sizeof(Agenda), *pos, arquivo);
  if (gravados != (size_t)*pos) {
    fclose(arquivo);
    return ESCREVER;
  }

  if (fclose(arquivo) == EOF)
    return FECHAR;

  return OK;
}

ERROS carregar(Agenda contatos[], int *pos) {
  FILE *arquivo = fopen("contatos.bin", "rb");
  if (arquivo == NULL)
    return ABRIR;
  int qtd = fread(contatos, sizeof(Agenda), TOTAL, arquivo);
  if(qtd == 0)
      return LER;
  qtd = fread(pos, 1, sizeof(int), arquivo);
  if(qtd == 0)
      return LER;
  if(fclose(arquivo))
    return FECHAR;
  return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}