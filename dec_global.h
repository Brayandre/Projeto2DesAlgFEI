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


// void pegarData(int *dia, int *mes){
    
//     time_t d = time(NULL);

//     struct tm *dataA = localtime(&d);

//     *dia = dataA->tm_mday - 1;
//     *mes = dataA->tm_mon + 1;    
// };

extern struct Produtos frutveg[12];

#endif
