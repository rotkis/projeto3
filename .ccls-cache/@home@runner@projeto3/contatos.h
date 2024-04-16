#define TOTAL 255
#define NOME 20
#define SOBRENOME 25
#define TELEFONE 11
#define EMAIL 50

typedef struct {
    char nome[NOME];
    char sobrenome[SOBRENOME];
    char telefone[TELEFONE];
    char email[EMAIL];
} Agenda;

typedef enum {OK, MAX_CONTATO, SEM_CONTATO, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

typedef ERROS (*funcao)(Agenda[], int*);

ERROS criar(Agenda contatos[], int *pos);
ERROS deletar(Agenda contatos[], int *pos);
ERROS listar(Agenda contatos[], int *pos);
ERROS salvar(Agenda contatos[], int *pos);
ERROS carregar(Agenda contatos[], int *pos);

void clearBuffer();