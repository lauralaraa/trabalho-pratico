#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cadastroendereco.h"

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
