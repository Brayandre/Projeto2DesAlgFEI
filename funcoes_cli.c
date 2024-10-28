#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "dec_global.h"
#include <unistd.h>

char senha[12];
char cpf[12];

tipoPag carteira;

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
        char nome_p[50];
        int qtd_p;
        float preco_p;
        float val_p; 
    };

void passarConta(const char* senhaE, const char* cpfE){
    strcpy(senha, senhaE);
    strcpy(cpf, cpfE);
}

void save_carrinho(const char* cpf, char* nome_p, float preco_p, int qtdP, float valorP){
    struct carrinho c;

    //determinação de envio
    strcpy(c.nome_p, nome_p);
    c.preco_p = preco_p;
    c.qtd_p = qtdP;
    c.val_p = valorP;

    char nome_arq[50];

    snprintf(nome_arq, sizeof(nome_arq), "%s_carrinho.bin", cpf);

    FILE *file = fopen(nome_arq,"ab");
    if (file == NULL){
        printf("Erro ao abrir o arquivo\n");
    } 

    fwrite(&c, sizeof(struct carrinho), 1, file);

    fclose(file);
}
void criaCart(){
    char nome_arq_c[50];
    snprintf(nome_arq_c, sizeof(nome_arq_c), "%s_carteira.txt", cpf);

    FILE *file = fopen(nome_arq_c,"w");
    if (file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    } 

    fprintf(file, "Credito FEI: %.2f\n", carteira.creditoFEI = 0);
    fprintf(file, "Número do Cartão: %d\n", carteira.numCartao = 0) ;
    fprintf(file, "Dinheiro Disp. Cartao: %.2f\n", carteira.cartaoD = 2000);

    fclose(file);
}


void load_cart(const char* cpf, tipoPag *carteira) {
    char nome_arq_c[50];
    snprintf(nome_arq_c, sizeof(nome_arq_c), "%s_carteira.txt", cpf);

    FILE *file = fopen(nome_arq_c, "r");
    if (file == NULL) {
        criaCart();
        return;
    }

    fscanf(file, "Credito FEI: %f\n", &carteira->creditoFEI);
    fscanf(file, "Número do Cartão: %d\n", &carteira->numCartao);
    fscanf(file, "Dinheiro Disp. Cartao: %f\n", &carteira->cartaoD);

    fclose(file);
}

void save_cart(const char* cpf){
    char nome_arq_c[50];
    snprintf(nome_arq_c, sizeof(nome_arq_c), "%s_carteira.txt", cpf);

    FILE *file = fopen(nome_arq_c,"w");
    if (file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    } 

    fprintf(file, "Credito FEI: %.2f\n", carteira.creditoFEI);
    fprintf(file, "Número do Cartão: %d\n", carteira.numCartao);
    fprintf(file, "Dinheiro Disp. Cartao: %.2f\n", carteira.cartaoD);

    fclose(file);
}

void lerCarrinho(const char* cpf){
    struct carrinho c;
    char nome_arq[50];
    int totCar, lerCar, i;
    float totalCar;

    snprintf(nome_arq, sizeof(nome_arq), "%s_carrinho.bin", cpf);

    FILE *file = fopen(nome_arq, "rb");
    if (file == NULL){
        printf("Ainda não há carrinho em sua conta!\n");
        return;
    } 

    //calcula a qtd de produtos do carrinho
    fseek(file, 0, SEEK_END);
    long tam_arq = ftell(file);
    totCar = tam_arq / sizeof(struct carrinho);

    lerCar = totCar > 100 ? 100: totCar;
    fseek(file, -(lerCar * sizeof(struct carrinho)), SEEK_END);

    for (i = 0; i < lerCar;i++){
        printf("-------------------------------------------------\n");
        fread(&c, sizeof(struct carrinho),1,file);
        printf("Produto: %s\n", c.nome_p);
        printf("Preço: %.2f\n", c.preco_p);
        printf("Quantidade: %.0d\n", c.qtd_p);
        printf("Valor total (quantidade x valor) %.2f\n", c.val_p);
        totalCar += c.val_p;
    }
    printf("Total a pagar: %.2f\n", totalCar);

    fclose(file);

}

void verCar(){
    printf("-------------------------------------------------\n");
    printf("Aqui estão seus carrinhos: \n");
    lerCarrinho(cpf);
}

void formaPag(){
    printf("-------------------------------------------------\n");
    printf("Digite seu login: ");
    char log_f[12];
    scanf("%12s", log_f);
    printf("Digite sua senha: ");
    char sen_f[20];
    scanf("%20s", sen_f);

    if (strcmp(log_f, cpf) != 0 || strcmp(sen_f, senha) != 0){
        return;
    };
    printf("Aqui estão as formas de pagamento disponiveis para voce utilizar: \n");
    printf("1 - Crédito FEI\n");
    printf("2 - Cartão de Crédito\n");
    printf("3 - Chave Pix\n");
    printf("4 - Sair\n");
    int escolha;
    printf("Selecione sua escolha: ");
    scanf("%d", &escolha);
    
    char entry;
    int credF;
    float credT;
    float valS;
    char nome_arq[50];
    switch (escolha){
        case 1: 
            printf("Crédito FEI: A cada hora complementar cumprida, você recebe R$ 2.50\n");
            printf("Você quer visualizar quantos Reais em horas complementarem você tem em sua conta(S/N)? ");
            scanf(" %c", &entry);
            if (toupper(entry) == 'S'){
                printf("-------------------------------------------------\n");
                printf("Você possui R$ %.2f em horas complementares\n", carteira.creditoFEI);
            
            }
            if(toupper(entry) != 'S' && toupper(entry) != 'N'){
                printf("opção não econtrada");
            }
            printf("Você deseja fazer um deposito de horas complementares(S/N)? ");
            scanf(" %c", &entry);
            printf("-------------------------------------------------\n");
            if(toupper(entry) == 'S'){
                printf("Digite quantas horas complementares você quer trocar: ");
                scanf(" %d", &credF);
                credT = 0; 
                credT = credF * 2.5;
                printf("R$ %.2f é o valor recebido por suas horas complementarem, ainda deseja trocar(S/N)? ", credT);   
                scanf(" %c", &entry);
                printf("-------------------------------------------------\n");
                if(toupper(entry) == 'N'){
                    printf("Voltando ao menu: \n");
                    return;
                }
                if(toupper(entry) != 'S' && toupper(entry) != 'N'){
                    printf("Opção não encontrada\n");
                    return;
                }
            }
            else{
                printf("Retornando ao menu.\n");
                return;
            }
            carteira.creditoFEI += credT;
            printf("Deseja pagar seu carrinho atual? ");
            scanf(" %c", &entry);
            if (toupper(entry) == 'N'){
                printf("Retornando ao menu...\n");
                return;
            }
            if(toupper(entry) != 'S' && toupper(entry) != 'N'){
                printf("Opção não encontrada\n");
                return;
            }
            //somando os valores
            snprintf(nome_arq, sizeof(nome_arq), "%s_carrinho.bin", cpf);
            struct carrinho c;
            int totCar, lerCar, i;
            FILE *file = fopen(nome_arq, "rb");
            if (file == NULL){
                printf("Ainda não há carrinho em sua conta!\n");
                return;
            } 
            fseek(file, 0, SEEK_END);
            long tam_arq = ftell(file);
            totCar = tam_arq / sizeof(struct carrinho);
            lerCar = totCar > 100 ? 100: totCar;
            fseek(file, -(lerCar * sizeof(struct carrinho)), SEEK_END);
            for (i = 0; i < lerCar;i++){
                fread(&c, sizeof(struct carrinho),1,file);
                valS += c.val_p;   
            }
            if(valS > credT){
                printf("Horas complementarem insuficientes %d x 2.5 = %.2f \n", credF, credT);
                return;
            }
            printf("-------------------------------------------------\n");
            printf("Total a pago pelo carinho: %.2f\n", valS);
            carteira.creditoFEI = credT - valS;
            printf("Sobrou esse valor de creditos FEI R$ %.2f\n", carteira.creditoFEI);
            printf("-------------------------------------------------\n");
            if (remove(nome_arq) == 0) {
                printf(" ");
            } else {
                    perror("Erro ao remover o arquivo");
            }

            break;
        case 2:
            printf("Você possui nosso cartão de crédito FEI?(S/N) : ");
            scanf(" %c", &entry);
            if(toupper(entry) == 'S'){
                int numCart;
                printf("Digite o número do seu cartão: ");
                scanf(" %d", &numCart);
                if (numCart == carteira.numCartao){
                    printf("Lembrando que o seu limite é %2.f \n", carteira.cartaoD);
                    float credito;
                    //somando as compras
                    char nome_arq[50];
                    snprintf(nome_arq, sizeof(nome_arq), "%s_carrinho.bin", cpf);
                    struct carrinho c;
                    int totCar, lerCar, i;
                    FILE *file = fopen(nome_arq, "rb");
                    if (file == NULL){
                        printf("Ainda não há carrinho em sua conta!\n");
                        return;
                    } 
                    fseek(file, 0, SEEK_END);
                    long tam_arq = ftell(file);
                    totCar = tam_arq / sizeof(struct carrinho);
                    lerCar = totCar > 100 ? 100: totCar;
                    fseek(file, -(lerCar * sizeof(struct carrinho)), SEEK_END);
                    for (i = 0; i < lerCar;i++){
                        fread(&c, sizeof(struct carrinho),1,file);
                        credito += c.val_p;   
                    }
                    printf("Valor total a ser pago: %.2f\n", credito);
                    if (credito >= carteira.cartaoD){
                        printf("Limite indisponivel\n");
                        printf("-------------------------------------------------\n");
                    }
                    else{
                        carteira.cartaoD -= credito;
                        printf(" \n");
                        printf("Agora o seu limite é de %.2f\n ", carteira.cartaoD);
                        //apagando o carrinho
                        if (remove(nome_arq) == 0) {

                        } else {
                            perror("Erro ao remover o arquivo");
                        }
                        printf("Carrinho pago\n");
                    }
                }
                else{
                    printf("Cartão não encontrado\n");
                }
                break;

            }
            if(toupper(entry) == 'N'){
                printf("Você deseja fazer um cartão de crédito FEI?(S/N): ");
                scanf(" %c", &entry);
                if(toupper(entry) == 'S'){
                    printf("Criando cartão...\n");

                    int t = 8;
                    while (t > 0) {
                        sleep(1);   
                        for (int i = 0; i < t; i++) {
                            printf("."); 
                        }
                        printf("\n"); 
                        t--; 
                    }
                    srand(time(NULL)); 
                    carteira.numCartao = 1000000000LL + ((long long int)rand() * (9000000000LL / RAND_MAX));
                    printf("Número do Cartão de Crédito: %d\n", carteira.numCartao);
                    printf("-------------------------------------------------\n");
                
                }
            }
            printf("Voltando ao menu...\n");
            printf("-------------------------------------------------\n");
            break;

        case 3:
            ; // manter o rotulo vazio
            snprintf(nome_arq, sizeof(nome_arq), "%s_carrinho.bin", cpf);

            if (file == NULL){
                printf("Ainda não há carrinho em sua conta!\n");
                return;
            } 


            printf("Gerando Chave...  \n");
            //temporizador
            int t = 8; 
            while (t > 0) {
                sleep(1);
                
                for (int i = 0; i < t; i++) {
                    printf("."); 
                }
                printf("\n"); 
                t--; 
            }
            srand(time(NULL));
            long long int chave_pix = 1000000000LL + rand() % 9000000000LL;
            printf("Chave pix: %lld\n", chave_pix);

            if (remove(nome_arq) == 0) {
                
            } else {
                    perror("Não há carinnho em sua conta.");
                    return;
            }
            printf("Carrinho pago\n");
            printf("-------------------------------------------------\n");
            break;

        case 4:
            printf("Saindo..\n");
            break;

        default:
        printf("Opção não encontrada!!\n");
        break;
    }
}

void f_produtos(struct Produtos produto[], int tamanho){

    const char *opcoes[] = {
        "Bebidas",
        "Frutas/Vegetais",
        "Açougue",
        "Alimentos Nao pereciveis",
        "Limpeza",
        "Padaria",
        "Sair",
    };

    int setor;

    do{
        printf("-------------------------------------------------");
        printf("\n");
        printf("Aqui estão os nossos produtos:\n");
        printf("\n");
        for (int w = 0; w < (sizeof(opcoes)/ sizeof(opcoes[0])); w++ ){
            printf("%d - %s\n", w + 1, opcoes[w]);
        }
        printf("\n");

        int qtdP;
        char buy;
        float valorP;
        char nome_p;
        float preco_p;

        printf("Digite o numero do setor de compras que deseja acessar: ");
        scanf(" %d", &setor);

        switch (setor){
            case 1:
                printf("Bem-vindo ao setor de BEBIDAS, aqui você encontra as melhores marcas com os melhores preços!\n");
                printf("--------------------------------------------------------------------------------------------\n");
                int tamanho1 = sizeof(bebidas) / sizeof(bebidas[0]);
                for (int i = 0; i < tamanho1; i++){
                    printf("**************************************************\n");
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
                            char *nome_p = malloc(strlen(bebidas[i].nome) + 1); 
                            strcpy(nome_p, bebidas[i].nome); 
                            preco_p = bebidas[i].preco;
                            save_carrinho(cpf,nome_p,preco_p, qtdP, valorP);
                        }
                        else{
                            printf("Não há quantidade suficiente!\n");
                        }
                    }
                }
                printf("...\n");
                printf("**************************************************\n");
                break;

            case 2:
                printf("Bem-vindo ao setor de FRUTAS & VEGETAIS, aqui você encontra as mais maduras e com o precinho la em baixo!\n");
                printf("---------------------------------------------------------------------------------------------------------\n");
                int tamanho2 = sizeof(frutveg) / sizeof(frutveg[0]);
                for (int i = 0; i < tamanho2; i++){
                    printf("**************************************************\n");
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
                            frutveg[i].quantidade -= qtdP;
                            char *nome_p = malloc(strlen(frutveg[i].nome) + 1); 
                            strcpy(nome_p, frutveg[i].nome); 
                            preco_p = frutveg[i].preco;
                            save_carrinho(cpf,nome_p,preco_p, qtdP, valorP);    
                        }
                        else{
                            printf("Não há quantidade suficiente!\n");
                        }
                    }
                }
                printf("...\n");
                printf("**************************************************\n");
                break;
            
            case 3:
                printf("Bem-vindo ao setor de Alimentos Não Perecíveis, aqui você encontra as peças mais bela que cabem no SEU BOLSO!\n");
                printf("-----------------------------------------------------------------------------------------\n");
                int tamanho3 = sizeof(acougue) / sizeof(acougue[0]);
                for (int i = 0; i < tamanho3; i++){
                    printf("**************************************************\n");
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
                            acougue[i].quantidade -= qtdP;
                            char *nome_p = malloc(strlen(acougue[i].nome) + 1); 
                            strcpy(nome_p, acougue[i].nome); 
                            preco_p = acougue[i].preco;
                            save_carrinho(cpf,nome_p,preco_p, qtdP, valorP);
                        }
                        else{
                            printf("Não há quantidade suficiente!\n");
                        }
                    }
                    printf("...\n");
                    printf("**************************************************\n");
                }
                break;
                
            case 4:
                printf("Bem-vindo ao setor de Alimentos Não perecíveis, onde o produto é bom e barato!\n");
                printf("---------------------------------------------------------------------------------------------------------\n");
                int tamanho4 = sizeof(alim_n_perec) / sizeof(alim_n_perec[0]);
                for (int i = 0; i < tamanho4; i++){
                    printf("**************************************************\n");
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
                            alim_n_perec[i].quantidade -= qtdP;
                            char *nome_p = malloc(strlen(alim_n_perec[i].nome) + 1); 
                            strcpy(nome_p, alim_n_perec[i].nome); 
                            preco_p = alim_n_perec[i].preco;
                            save_carrinho(cpf,nome_p,preco_p, qtdP, valorP);
                        }
                        else{
                            printf("Não há quantidade suficiente!\n");
                        }
                    }
                }
                printf("...\n");
                printf("**************************************************\n");
                break;

            case 5:
                printf("Bem-vindo ao setor de LIMPEZA, aqui você encontra de tudo para deixar sua casa no brinco!\n");
                printf("---------------------------------------------------------------------------------------------------------\n");
                int tamanho5 = sizeof(limp) / sizeof(limp[0]);
                for (int i = 0; i < tamanho5; i++){
                    printf("**************************************************\n");
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
                            limp[i].quantidade -= qtdP;
                            char *nome_p = malloc(strlen(limp[i].nome) + 1); 
                            strcpy(nome_p, limp[i].nome); 
                            preco_p = limp[i].preco;
                            save_carrinho(cpf,nome_p,preco_p, qtdP, valorP);
                        }
                        else{
                            printf("Não há quantidade suficiente!\n");
                        }
                    }
                }
                printf("...\n");
                printf("**************************************************\n");
                break;

            case 6:
                printf("Bem-vindo ao setor PADARIA, onde o pão sai quentinho!\n");
                printf("---------------------------------------------------------------------------------------------------------\n");
                int tamanho6 = sizeof(padaria) / sizeof(padaria[0]);
                for (int i = 0; i < tamanho6; i++){
                    printf("**************************************************\n");
                    printf("Nome: %s\n", padaria[i].nome);
                    printf("Quantidade: %d\n", padaria[i].quantidade);
                    printf("Preço: R$ %.2f\n", padaria[i].preco);
                    printf("voçê deseja comprar %s ? (S/N) ", padaria[i].nome);
                    scanf("%s", &buy);
                    if (toupper(buy) == 'S'){
                        printf("Digite a quantidade que deseja comprar: ");
                        scanf("%d", &qtdP);
                        if (qtdP <= padaria[i].quantidade){
                            valorP = qtdP * padaria[i].preco;
                            printf("Valor adicionado ao carrinho: %.2f\n", valorP);
                            padaria[i].quantidade -= qtdP;
                            char *nome_p = malloc(strlen(padaria[i].nome) + 1); 
                            strcpy(nome_p, padaria[i].nome); 
                            preco_p = padaria[i].preco;
                            save_carrinho(cpf,nome_p,preco_p, qtdP, valorP);
                        }
                        else{
                            printf("Não há quantidade suficiente!\n");
                        }
                    }
                }
                printf("...\n");
                printf("**************************************************\n");
                break;
                
            case 7:
                printf("Saindo do menu de Produtos...\n");
                break;
            default:
                printf("Setor inexistente\n");
                break;
        }  

    } while (setor != 7);
        
}