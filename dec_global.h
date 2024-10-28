#ifndef PRODUTOS_H
#define PRODUTOS_H

struct Produtos{
    char nome[30];
    int quantidade;
    float preco;
};

typedef struct{
    float creditoFEI;
    int numCartao;
    float cartaoD;
}tipoPag;

tipoPag carteira;

extern struct Produtos frutveg[12];

#endif
