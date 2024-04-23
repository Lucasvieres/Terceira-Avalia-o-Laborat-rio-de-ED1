#include "projeto.h"
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    inicializar_lista_usuarios();
    inicializar_lista_perifericos();
    
    int escolha;
    int logado = 0;

    do {
        if (!logado) {
            printf("Você precisa estar logado para acessar o menu.\n");
            printf("1. Cadastrar\n");
            printf("2. Login\n");
            printf("3. Sair\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    cadastrar_usuario();
                    break;
                case 2:
                    logado = fazer_login();
                    break;
                case 3:
                    printf("Encerrando programa. Adeus!\n");
                    return 0;
                default:
                    printf("Escolha inválida. Por favor, tente novamente.\n");
            }
        } else {
            menu();
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);

            switch (escolha) {
                case 3:
                    adicionar_periferico();
                    break;
                case 4:
                    listar_perifericos();
                    break;
                case 5:
                    ordenar_perifericos();
                    break;
                case 6:
                    editar_periferico();
                    break;
                case 7:
                    excluir_periferico();
                    break;
                case 8:
                    printf("Encerrando programa. Adeus!\n");
                    return 0;
                default:
                    printf("Escolha inválida. Por favor, tente novamente.\n");
            }
        }
    } while (1);

    return 0;
}

