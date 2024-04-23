#ifndef PROJETO_H
#define PROJETO_H

#define MAX_TAMANHO_EMAIL 80
#define MAX_TAMANHO_SENHA 20
#define MAX_TAMANHO_NOME 50

typedef struct UsuarioNode {
    char email[MAX_TAMANHO_EMAIL];
    char senha[MAX_TAMANHO_SENHA];
    struct UsuarioNode *next;
} UsuarioNode;

typedef struct {
    UsuarioNode *head;
} UsuarioLista;

typedef struct PerifericoNode {
    char nome[MAX_TAMANHO_NOME];
    float preco;
    int estoque;
    struct PerifericoNode *next;
} PerifericoNode;

typedef struct {
    PerifericoNode *head;
} PerifericoLista;

int email_e_valido(const char *email);
void inicializar_lista_usuarios();
void inicializar_lista_perifericos();
void cadastrar_usuario();
int fazer_login();
void adicionar_periferico();
void listar_perifericos();
void ordenar_perifericos();
void editar_periferico();
void excluir_periferico();
void menu();

#endif /* PROJETO_H */

