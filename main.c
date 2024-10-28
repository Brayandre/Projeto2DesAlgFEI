#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes_cli.h"
#include "dec_global.h"

#define NUM_USUARIO 10
#define NUM_ADM 2
#define NUM_PROD 50
char entrar;

struct adm {
    char cod_a[7];
    char senha[20];
};

struct usuarios {
    char cpf[12];
    char senha[20];
};


void passarConta(const char* senha, const char* cpf);
void load_cart(const char* cpf, tipoPag *carteira);

int main() {
    struct usuarios Clientes[NUM_USUARIO] = {
        {"12345678901", "professor"},
        {"47143403454", "senha143"},
        {"47143409804", "brayan12"},
        {"47143408904", "se22a123"},
        {"47144509564", "senhqwr3"},
        {"47143409834", "seqwa123"},
        {"47147609887", "s1n0a123"},
        {"47143423674", "senhanr3"},
        {"43138734812", "rafa0702"},
        {"47143409834", "wrna123"}
    };

    struct adm Administrador[NUM_ADM] = {
        {"lucas", "luciano10"},
        {"romero", "garro10"}
    };

    char login_A[12];
    char senha_A[20];

    printf("Bem-vindo ao MARKETFEI, nós somos um super mercado recheados de novas ofertas e produtos, acesse o conteúdo a partir de seu login\n");
    printf("Digite seu login (CPF): ");
    scanf("%11s", login_A);
    printf("Digite sua senha: ");
    scanf(" %11s", senha_A);

    int encontrado = 0;
    for (int i = 0; i < NUM_USUARIO; i++) {
        if (strcmp(Clientes[i].cpf, login_A) == 0 && strcmp(Clientes[i].senha, senha_A) == 0) {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        printf("*************************************************\n");
        printf("Você deseja acessar a nossa loja virtual?(S/N) ");
        scanf(" %c", &entrar);
        const char* cpf = login_A;

        if (toupper(entrar) == 'S') {
            const char* cpfE = login_A;
            const char* senhaE = senha_A;
            passarConta(senhaE, cpfE);
            printf("Você entrou!\n");
            printf("\n");
            load_cart(cpf, &carteira);

            while (true) {
                save_cart(cpf);
                int op;
                printf("-------------------------------------------------\n");
                printf("1 - Nossos Produtos\n");
                printf("2 - Carrinho\n");
                printf("3 - Pagamento\n");
                printf("4 - Sing out\n");
                printf("Digite a opção que deseja: ");
                scanf(" %d", &op);
                if (op == 1) {
                    f_produtos();
                } else if (op == 2) {
                    verCar();
                } else if (op == 3) {
                    formaPag();
                } else if (op == 4) {
                    printf("Até breve... S2\n");
                    return 1;
                } else {
                    return 1;
                }
            }
        } else {
            return 1;
        }
    } else {
        printf("Usuário inexistente\n");
    }

    return 0; // Finaliza o main
}
