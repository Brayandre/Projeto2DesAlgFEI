#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes_cli.h"

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

typedef struct{
    char nome[30];
    int quantidade;
    float preco;
}Produtos;


int main(){

    Produtos bebidas[6] = {
        {"Agua", 10, 1.5},
        {"Coca-Cola", 5, 3.5},
        {"Fanta Uva", 7, 4.5},
        {"Suco Natural", 3, 8.5},
        {"Leite", 15, 5.5},
        {"Cerveja Heinekein", 6, 10}
    };

    Produtos frutveg[12] = {
        {"Uva", 12, 9.0},
        {"Laranja", 20, 3.0},
        {"Banana", 20, 3.0},
        {"Limao", 14, 3.5},
        {"Morango", 25, 4.0},
        {"Maca", 15, 5.0},
        {"Alface", 17, 7.0},
        {"Tomate", 30, 3.5 },
        {"Beterraba", 10, 5.5},
        {"Repolho", 8, 8.5},
        {"Cenoura", 18, 6.0},
        {"Brocolis", 6, 9.0}
    };


    Produtos acougue[10] = {
        {"Filé Mignon", 20, 98},
        {"Picanha", 14, 65},
        {"Bife Ancho", 42, 79},
        {"Wagyu", 23, 134},
        {"Asinha Temperada", 48, 19},
        {"Linguica", 70, 28},
        {"Peito de Frango", 54, 22},
        {"Costela Bovina", 40, 18},
        {"Panceta", 25, 33},
        {"Acém", 10, 1.5}
    };

    Produtos alim_n_perec[5] = {
        {"Arroz", 30, 17},
        {"Feijao", 30, 7},
        {"Macarrao", 20, 4.5},
        {"Sal", 27, 5.0},
        {"Acucar", 18, 4.5}
            };

    Produtos limp[5] = {
        {"Desinfetante", 20, 12},
        {"Sabao em po", 30, 15},
        {"Detergente", 15, 9},
        {"Cloro", 10, 25},
        {"Bombril", 30, 1.8}
    };

    Produtos padaria[4] = {
        {"Pao Frances", 70, 2},
        {"Sonho", 30, 4},
        {"Baguete", 40, 5},
        {"Ovo", 10, 15}
    };


    struct usuarios Clientes [NUM_USUARIO] = {
    {"47169633817", "pepa10"},
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
    scanf("%11s", senha_A);
    int encontrado = 0;
    for (int i = 0; i < NUM_USUARIO; i++) {
        if (strcmp(Clientes[i].cpf, login_A) == 0 && strcmp(Clientes[i].senha, senha_A) == 0) {
            encontrado = 1;
            break;
        }
    }

    printf("*************************************************\n");
    printf("Você deseja acessar a nossa loja virtual?(S/N)");
    scanf(" %c", &entrar);
    if(toupper(entrar) == 'S'){
        printf("Você entrou!\n");
        printf("\n");
        printf("1 - Nossos Produtos\n");
        printf("2 - Carrinho\n");
        printf("3 - Forma de Pagamento\n");
        printf("4 - Sing out\n");

        while(true) {
            int op;
            printf("Digite a opção que deseja: ");
            scanf(" %d", &op);
            if (op == 1){
                f_produtos();
            }
            else if (op == 2){
                // f_carrinho();
            }
            else if (op == 3){
                // f_forma();
            }
            else{
                return 1;
            }
        }
    }
    else if(toupper(entrar) == 'A'){
        printf("Bem vindo ADEMIR\n");
    }
    else{
        return 1;
    }

}