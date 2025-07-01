#ifndef ENDERECO_H
#define ENDERECO_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Endereco {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char cep[20];
}Endereco;

Endereco cadastrarEndereco() {

    Endereco Endereco;
    printf("\nInsira o nome da sua rua:\n");
    fgets(Endereco.rua,50,stdin);
    getchar();
    printf("\nInsira o nome do seu bairro:\n");
    fgets(Endereco.bairro,50,stdin);
    getchar();
    printf("\nInsira a cidade em que voce mora:\n");
    fgets(Endereco.cidade,50,stdin);
    getchar();
    printf("\nInsira o CEP\n");
    fgets(Endereco.cep,50,stdin);
    getchar();

    return Endereco;
    }



#endif