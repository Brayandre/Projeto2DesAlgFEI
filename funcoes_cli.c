#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "dec_global.h"

    struct Produtos bebidas[6] = {
        {"Agua", 10, 1.5},
        {"Coca-Cola", 5, 3.5},
        {"Fanta Uva", 7, 4.5},
        {"Suco Natural", 3, 8.5},
        {"Leite", 15, 5.5},
        {"Cerveja Heinekein", 6, 10}
    };
    
    struct Produtos acougue[10] = {
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

    struct Produtos alim_n_perec[5] = {
        {"Arroz", 30, 17},
        {"Feijao", 30, 7},
        {"Macarrao", 20, 4.5},
        {"Sal", 27, 5.0},
        {"Acucar", 18, 4.5}
            };

    struct Produtos limp[5] = {
        {"Desinfetante", 20, 12},
        {"Sabao em po", 30, 15},
        {"Detergente", 15, 9},
        {"Cloro", 10, 25},
        {"Bombril", 30, 1.8}
    };

    struct Produtos padaria[4] = {
        {"Pao Frances", 70, 2},
        {"Sonho", 30, 4},
        {"Baguete", 40, 5},
        {"Ovo", 10, 15}
    };

    struct Produtos frutveg[12] = {
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

    struct carrinho{
        char nome_p;
        int quantidade_p;
        float preco_p;
        float valT; 
    }

void save_carrinho(const char cpf, char nome_p, float preco_p, int qtdP, float valorP){
    struct carrinho c;

    //determinação de envio
    strncpy(c.nome_p, nome_p, sizeof(c, nome_p) -1);
    c.preco_p = preco_p;
    c.qtdP = qtdP;
    c.valorP = valorP;

    char nome_arq[50];

    snprintf(nome_arq, sizeof(nome_arq), "%s_carrinho.bin", cpf);

    FILE *file = fopen(nome_arq,"ab");
    if (file == NULL){
        printf("Erro ao abrir o arquivo\n");
    } 

    fwrite(&e, sizeof(struct carrinho), 1, file);

    fclose(file);
}


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
    printf("7 - Sair\n");
    printf("\n");

    int qtdP;
    char buy;
    int setor;
    float valorP;

    printf("Digite o numero do setor de compras que deseja acessar: ");
    scanf(" %d", &setor);
    if (setor == 1){
        printf("Bem-vindo ao setor de BEBIDAS, aqui você encontra as melhores marcas com os melhores preços!\n");
        printf("--------------------------------------------------------------------------------------------\n");
        int tamanho = sizeof(bebidas) / sizeof(bebidas[0]);
        for (int i = 0; i < tamanho; i++){
            printf("Nome: %s\n", bebidas[i].nome);
            printf("Quantidade: %d\n", bebidas[i].quantidade);
            printf("Preço: R$ %.2f\n", bebidas[i].preco);
            printf("voçê deseja comprar %s ? (S/N) ", bebidas[i].nome);
            scanf("%s", &buy);
            if (toupper(buy) == 'S'){
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &qtdP);
                if (qtdP <= bebidas[i].quantidade){
                    valorP = qtdP * bebidas[i].preco;
                    printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                    bebidas[i].quantidade -= qtdP;
                    nome_p = bebidas[i].nome;
                    preco_p = bebidas[i].preco;
                    save_carrinho(cpf,nome_p,preco_p, qtdP, valorP);
                }
                else{
                    printf("Não há quantidade suficiente!\n");
                }
            }
            printf("...\n");
            printf("**************************************\n");
        }

    }
    else if(setor == 2){
        printf("Bem-vindo ao setor de FRUTAS & VEGETAIS, aqui você encontra as mais maduras e com o precinho la em baixo!\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        int tamanho = sizeof(frutveg) / sizeof(frutveg[0]);
        for (int i = 0; i < tamanho; i++){
            printf("Nome: %s\n", frutveg[i].nome);
            printf("Quantidade: %d\n", frutveg[i].quantidade);
            printf("Preço: R$ %.2f\n", frutveg[i].preco);
            printf("voçê deseja comprar %s ? (S/N) ", frutveg[i].nome);
            scanf("%s", &buy);
            if (toupper(buy) == 'S'){
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &qtdP);
                if (qtdP <= frutveg[i].quantidade){
                    valorP = qtdP * frutveg[i].preco;
                    printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                }
                else{
                    printf("Não há quantidade suficiente!\n");
                }
            }
            printf("...\n");
            printf("**************************************\n");
        }
    }
    else if(setor == 3){
        printf("Bem-vindo ao setor de Alimentos Não Perecíveis, aqui você encontra as peças mais bela que cabem no SEU BOLSO!\n");
        printf("-----------------------------------------------------------------------------------------\n");
        int tamanho = sizeof(acougue) / sizeof(acougue[0]);
        for (int i = 0; i < tamanho; i++){
            printf("Nome: %s\n", acougue[i].nome);
            printf("Quantidade: %d\n", acougue[i].quantidade);
            printf("Preço: R$ %.2f\n", acougue[i].preco);
            printf("voçê deseja comprar %s ? (S/N) ", acougue[i].nome);
            scanf("%s", &buy);
            if (toupper(buy) == 'S'){
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &qtdP);
                if (qtdP <= acougue[i].quantidade){
                    valorP = qtdP * acougue[i].preco;
                    printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                }
                else{
                    printf("Não há quantidade suficiente!\n");
                }
            }
            printf("...\n");
            printf("**************************************\n");
        }
    }
    else if(setor == 4){
        printf("Bem-vindo ao setor de Alimentos Não perecíveis, onde o produto é bom e barato!");
        printf("---------------------------------------------------------------------------------------------------------\n");
        int tamanho = sizeof(alim_n_perec) / sizeof(alim_n_perec[0]);
        for (int i = 0; i < tamanho; i++){
            printf("Nome: %s\n", alim_n_perec[i].nome);
            printf("Quantidade: %d\n", alim_n_perec[i].quantidade);
            printf("Preço: R$ %.2f\n", alim_n_perec[i].preco);
            printf("voçê deseja comprar %s ? (S/N) ", alim_n_perec[i].nome);
            scanf("%s", &buy);
            if (toupper(buy) == 'S'){
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &qtdP);
                if (qtdP <= alim_n_perec[i].quantidade){
                    valorP = qtdP * alim_n_perec[i].preco;
                    printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                }
                else{
                    printf("Não há quantidade suficiente!\n");
                }
            }
            printf("...\n");
            printf("**************************************\n");
        }
    }
    else if(setor == 5){
        printf("Bem-vindo ao setor de LIMPEZA, aqui você encontra de tudo para deixar sua casa no brinco!");
        printf("---------------------------------------------------------------------------------------------------------\n");
        int tamanho = sizeof(limp) / sizeof(limp[0]);
        for (int i = 0; i < tamanho; i++){
            printf("Nome: %s\n", limp[i].nome);
            printf("Quantidade: %d\n", limp[i].quantidade);
            printf("Preço: R$ %.2f\n", limp[i].preco);
            printf("voçê deseja comprar %s ? (S/N) ", limp[i].nome);
            scanf("%s", &buy);
            if (toupper(buy) == 'S'){
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &qtdP);
                if (qtdP <= limp[i].quantidade){
                    valorP = qtdP * limp[i].preco;
                    printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                }
                else{
                    printf("Não há quantidade suficiente!\n");
                }
            }
            printf("...\n");
            printf("**************************************\n");
        }
    }
    else if(setor == 6){
        printf("Bem-vindo ao setor PADARIA, onde o pão sai quentinho!");
        printf("---------------------------------------------------------------------------------------------------------\n");
        int tamanho = sizeof(alim_n_perec) / sizeof(alim_n_perec[0]);
        for (int i = 0; i < tamanho; i++){
            printf("Nome: %s\n", alim_n_perec[i].nome);
            printf("Quantidade: %d\n", alim_n_perec[i].quantidade);
            printf("Preço: R$ %.2f\n", alim_n_perec[i].preco);
            printf("voçê deseja comprar %s ? (S/N) ", alim_n_perec[i].nome);
            scanf("%s", &buy);
            if (toupper(buy) == 'S'){
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &qtdP);
                if (qtdP <= alim_n_perec[i].quantidade){
                    valorP = qtdP * alim_n_perec[i].preco;
                    printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                }
                else{
                    printf("Não há quantidade suficiente!\n");
                }
            }
            printf("...\n");
            printf("**************************************\n");
        }
    }
    else if(setor == 7){
    return;
    }
    else{
        printf("Esse setor não existe\n");
    }
}