#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Endereco {
    char rua[30];
    char bairro[30];
    char cidade[30];
    char cep[20];
}Endereco;

typedef struct Comprador {
    char nome[100];
    char cpf[15];
    char email[50];
    Endereco nome[100];
}Comprador;
