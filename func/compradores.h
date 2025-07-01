#ifndef COMPRADORES_H
#define COMPRADORES_H
#include"endereco.h"

typedef struct Comprador {
    char nome[100];
    char cpf[15];
    char email[50];
    Endereco endereco;
}Comprador;


Comprador cadastrocomprador () {
    Comprador infoComprador;
    Endereco endereco;
    printf("\nInsira o nome do comprador: ");
    fgets(infoComprador.nome,100,stdin);
    getchar();
    printf("\nInsira o codigo do produto: ");
    fgets(infoComprador.cpf,15,stdin);
    getchar();
    printf("\nInsira o email do comprador: ");
    fgets(infoComprador.cpf,15,stdin);
    getchar();
    infoComprador.endereco=cadastroendereco();
    
};

void salvarProduto(Comprador c) {
    FILE *arquivo = fopen("compradores.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s;%s;%s,%s,%s\n", c.nome, c.cpf, c.email, c.endereco.bairro, c.endereco.rua, c.endereco.cidade, c.endereco.cep);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}
#endif