#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UsuarioLista usuarios = {NULL};
PerifericoLista perifericos = {NULL};

int email_e_valido(const char *email) {
    // Implementa��o da fun��o de valida��o de e-mail
    // Aqui voc� pode adicionar a l�gica para verificar se o e-mail � v�lido
}

void inicializar_lista_usuarios() {
    usuarios.head = NULL;
}

void inicializar_lista_perifericos() {
    perifericos.head = NULL;
}

void cadastrar_usuario() {
    printf("Digite seu email: ");
    char email[MAX_TAMANHO_EMAIL];
    scanf("%s", email);

    if (!email_e_valido(email)) {
        printf("Email inv�lido.\n");
        return;
    }

    printf("Digite sua senha: ");
    char senha[MAX_TAMANHO_SENHA];
    scanf("%s", senha);

    UsuarioNode *novo_usuario = (UsuarioNode*)malloc(sizeof(UsuarioNode));
    if (novo_usuario == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return;
    }

    strcpy(novo_usuario->email, email);
    strcpy(novo_usuario->senha, senha);
    novo_usuario->next = usuarios.head;
    usuarios.head = novo_usuario;

    printf("Cadastro realizado com sucesso!\n");
}

int fazer_login() {
    printf("Digite seu email: ");
    char email[MAX_TAMANHO_EMAIL];
    scanf("%s", email);

    printf("Digite sua senha: ");
    char senha[MAX_TAMANHO_SENHA];
    scanf("%s", senha);

    UsuarioNode *atual = usuarios.head;
    while (atual != NULL) {
        if (strcmp(atual->email, email) == 0 && strcmp(atual->senha, senha) == 0) {
            printf("Bem-vindo � HighTech Store!\n");
            return 1;
        }
        atual = atual->next;
    }

    printf("Email ou senha inv�lidos.\n");
    return 0;
}

void adicionar_periferico() {
    printf("Digite o nome do perif�rico: ");
    char nome[MAX_TAMANHO_NOME];
    scanf("%s", nome);

    printf("Digite o pre�o: ");
    float preco;
    scanf("%f", &preco);

    printf("Digite o estoque: ");
    int estoque;
    scanf("%d", &estoque);

    PerifericoNode *novo_periferico = (PerifericoNode*)malloc(sizeof(PerifericoNode));
    if (novo_periferico == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return;
    }

    strcpy(novo_periferico->nome, nome);
    novo_periferico->preco = preco;
    novo_periferico->estoque = estoque;
    novo_periferico->next = perifericos.head;
    perifericos.head = novo_periferico;

    printf("Perif�rico adicionado com sucesso!\n");
}

void listar_perifericos() {
    PerifericoNode *atual = perifericos.head;
    printf("\n--- Lista de Perif�ricos ---\n");
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("Pre�o: %.2f\n", atual->preco);
        printf("Estoque: %d\n\n", atual->estoque);
        atual = atual->next;
    }
}

void ordenar_perifericos() {
    // Implementa��o da fun��o de ordenar perif�ricos
    PerifericoNode *atual, *proximo;
    char temp_nome[MAX_TAMANHO_NOME];
    float temp_preco;
    int temp_estoque;
    int trocado;

    if (perifericos.head == NULL || perifericos.head->next == NULL) {
        // Lista vazia ou com apenas um elemento, n�o h� necessidade de ordenar
        return;
    }

    do {
        trocado = 0;
        atual = perifericos.head;
        proximo = perifericos.head->next;

        while (proximo != NULL) {
            if (strcmp(atual->nome, proximo->nome) > 0) {
                // Troca as informa��es dos perif�ricos
                strcpy(temp_nome, atual->nome);
                strcpy(atual->nome, proximo->nome);
                strcpy(proximo->nome, temp_nome);

                temp_preco = atual->preco;
                atual->preco = proximo->preco;
                proximo->preco = temp_preco;

                temp_estoque = atual->estoque;
                atual->estoque = proximo->estoque;
                proximo->estoque = temp_estoque;

                trocado = 1;
            }
            atual = atual->next;
            proximo = proximo->next;
        }
    } while (trocado);
}

void editar_periferico() {
    // Implementa��o da fun��o de editar perif�rico
    char nome[MAX_TAMANHO_NOME];
    printf("Digite o nome do perif�rico para editar: ");
    scanf("%s", nome);

    PerifericoNode *atual = perifericos.head;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Digite o novo pre�o: ");
            scanf("%f", &atual->preco);

            printf("Digite o novo estoque: ");
            scanf("%d", &atual->estoque);

            printf("Perif�rico editado com sucesso!\n");
            return;
        }
        atual = atual->next;
    }

    printf("Perif�rico n�o encontrado.\n");
}

void excluir_periferico() {
    // Implementa��o da fun��o de excluir perif�rico
    char nome[MAX_TAMANHO_NOME];
    printf("Digite o nome do perif�rico para excluir: ");
    scanf("%s", nome);

    PerifericoNode *atual = perifericos.head;
    PerifericoNode *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                // O perif�rico a ser exclu�do � o primeiro da lista
                perifericos.head = atual->next;
            } else {
                // O perif�rico a ser exclu�do n�o � o primeiro da lista
                anterior->next = atual->next;
            }
            free(atual);
            printf("Perif�rico exclu�do com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->next;
    }

    printf("Perif�rico n�o encontrado.\n");
}

void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar\n");
    printf("2. Login\n");
    printf("3. Adicionar Perif�rico\n");
    printf("4. Listar Perif�ricos\n");
    printf("5. Ordenar Perif�ricos\n");
    printf("6. Editar Perif�rico\n");
    printf("7. Excluir Perif�rico\n");
    printf("8. Sair\n");
}

