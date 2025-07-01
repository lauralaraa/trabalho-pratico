#ifndef COMPRADORES_H
#define COMPRADORES_H
#include"endereco.h"

typedef struct Comprador {
    char nome[100];
    char cpf[15];
    char email[50];
    Endereco endereco;
}Comprador;

void proximoIDcomprador() {

}

void buscarComprador() {

}

Comprador cadastroComprador () {

    Comprador comprador;

    printf("\nInsira o nome do comprador: ");
    fgets(comprador.nome,100,stdin);
    getchar();
    printf("\nInsira o codigo do produto: ");
    fgets(comprador.cpf,15,stdin);
    getchar();
    printf("\nInsira o email do comprador: ");
    fgets(comprador.cpf,15,stdin);
    getchar();
    comprador.endereco=cadastroEndereco();

    FILE *arquivo = fopen("compradores.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s;%s;%s,%s,%s\n", comprador.nome, comprador.cpf, comprador.email, comprador.endereco.bairro, comprador.endereco.rua, comprador.endereco.cidade, comprador.endereco.cep);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
    
}

void editarComprador() {

}

void deletarComprador() {
    
}

#endif