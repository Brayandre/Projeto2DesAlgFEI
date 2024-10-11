#ifndef PRODUTOS_H
#define PRODUTOS_H

struct Produtos{
    char nome[30];
    int quantidade;
    float preco;
};

void f_produtos(struct Produtos produto[], int tamanho);

#endif
