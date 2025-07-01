#ifndef ENDERECO_H
#define ENDERECO_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"limparbuffer.h"

typedef struct Endereco {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char cep[20];
}Endereco;

Endereco cadastrarEndereco() {

    Endereco Endereco;
    getchar();
    printf("\nInsira o nome da sua rua:\n");
    fgets(Endereco.rua,50,stdin);
    printf("\nInsira o nome do seu bairro:\n");
    fgets(Endereco.bairro,50,stdin);
    printf("\nInsira a cidade em que voce mora:\n");
    fgets(Endereco.cidade,50,stdin);
    printf("\nInsira o CEP\n");
    fgets(Endereco.cep,50,stdin);
    getchar();

    return Endereco;
    }

    Endereco editarEndereco() {

        Endereco Endereco;

        printf("Insira o novo nome da rua:\n");
        fgets(Endereco.rua,50,stdin);
        Endereco.rua[strcspn(Endereco.rua, "\n")] = 0;
        printf("Insira o novo nome do bairro:\n");
        fgets(Endereco.bairro,50,stdin);
        Endereco.bairro[strcspn(Endereco.bairro, "\n")] = 0;
        printf("Insira o novo nome da cidade:\n");
        fgets(Endereco.cidade,50,stdin);
        Endereco.cidade[strcspn(Endereco.cidade, "\n")] = 0;
        printf("Insira o novo CEP:\n");
        fgets(Endereco.cep,50,stdin);
        Endereco.cep[strcspn(Endereco.cep, "\n")] = 0;
    }

#endif