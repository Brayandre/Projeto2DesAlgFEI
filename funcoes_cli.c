#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "dec_global.h"

void f_produtos(struct Produtos produto[], int tamanho){
    printf("\n");
    printf("Aqui estão os nossos produtos:\n");
    printf("\n");
    printf("1 - Bebidas\n");
    printf("2 - Frutas/Vegetais\n");
    printf("3 - Açougue\n");
    printf("4 - Alimentos Nao pereciveis\n");
    printf("5 - Limpeza\n");
    printf("6 - Padaria\n");
    printf("\n");

    int qtdP;
    char buy;
    int setor;
    float valorP;

    printf("Digite o numero do setor de compras que deseja acessar: \n");
    scanf(" %d", &setor);
    if (setor == 1){
        for (int i = 0; i < tamanho ; i++){
            printf("Nome: %s\n", produto[i].nome);
            printf("Quantidade: %d\n", produto[i].quantidade);
            printf("Preço: R$ %.2f\n", produto[i].preco);
            printf("**************************************\n");
            printf("voçê deseja comprar %s ? (S/N)\n ", produto[i].nome);
            scanf("%s", &buy);
            if (toupper(buy) == 'S'){
                printf("Digite a quantidade que deseja comprar\n");
                scanf("%d", &qtdP);
                if (qtdP <= produto[i].quantidade){
                    valorP = qtdP * produto[i].preco;
                    printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                }
                else{
                    printf("Não há quantidade suficiente!")
                }
            }
            printf("**************************************\n");
        }

    }
}