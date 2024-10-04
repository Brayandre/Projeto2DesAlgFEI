#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

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
    char nome;
    int quantidade;
    float preco;
}Produtos;


int main(){

    Produtos bebidas[4]{
        {"Agua", 10, 1.5},
        {"Coca-Cola", 5, 3.5},
        {"Fanta Uva", 7, 4.5},
        {"Suco Natural", 3, 8.5},
        {"Leite", 15, 5.5},
        {"Cerveja Heinekein", 6, 10},
    }

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

    printf("Bem-vindo ao MARKETFEI, nós somos um super mercado recheados de novas ofertas e produtos, acesse o conteúdo a partir de seu login\n");
    printf("Você deseja acessar a nossa loja virtual?(S/N)");
    scanf("%c", &entrar);

    if(toupper(entrar) == 'S'){
        printf("Você entrou!\n");
        printf("\n");
        printf("Aqui estão os nossos produtos:\n");
        printf("1 - Bebidas\n");
        printf("2 - Frutas/Vegetais\n");
        printf("3 - Açougue\n");
        printf("4 - Alimentos Nao pereciveis\n");
        printf("5 - Limpeza\n");
        printf("6 - Padaria\n");
    }
    else if(toupper(entrar) == 'A'){
        printf("Bem vindo ADEMIR\n");
    }
    else{
        return 1;
    }

}
