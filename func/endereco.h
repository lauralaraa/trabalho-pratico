#ifndef ENDERECO_H
#define ENDERECO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "limparbuffer.h"

typedef struct {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[3]; 
    char cep[20];
} Endereco;


Endereco cadastrarEndereco() {
    Endereco end;
    
    printf("--- Cadastro de Endereco ---\n");
    printf("Rua: ");
    fgets(end.rua, 50, stdin);
    end.rua[strcspn(end.rua, "\n")] = 0;

    printf("Bairro: ");
    fgets(end.bairro, 50, stdin);
    end.bairro[strcspn(end.bairro, "\n")] = 0;

    printf("Cidade: ");
    fgets(end.cidade, 50, stdin);
    end.cidade[strcspn(end.cidade, "\n")] = 0;

    printf("Estado (sigla, ex: SP): ");
    fgets(end.estado, 3, stdin);
    end.estado[strcspn(end.estado, "\n")] = 0;
    limparBuffer();

    printf("CEP: ");
    fgets(end.cep, 20, stdin);
    end.cep[strcspn(end.cep, "\n")] = 0;

    return end;
}


Endereco editarEndereco(Endereco enderecoAtual) {
    char buffer[100];
    printf("\n--- Editando Endereco ---\n");

    printf("Nova rua (Atual: %s): ", enderecoAtual.rua);
    fgets(buffer, 100, stdin);
    if (strlen(buffer) > 1) { 
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(enderecoAtual.rua, buffer);
    }

    printf("Novo bairro (Atual: %s): ", enderecoAtual.bairro);
    fgets(buffer, 100, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(enderecoAtual.bairro, buffer);
    }

    printf("Nova cidade (Atual: %s): ", enderecoAtual.cidade);
    fgets(buffer, 100, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(enderecoAtual.cidade, buffer);
    }
    
    printf("Novo estado (Atual: %s): ", enderecoAtual.estado);
    fgets(buffer, 3, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(enderecoAtual.estado, buffer);
    }
    limparBuffer();

    printf("Novo CEP (Atual: %s): ", enderecoAtual.cep);
    fgets(buffer, 20, stdin);
    if (strlen(buffer) > 1) {
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(enderecoAtual.cep, buffer);
    }

    return enderecoAtual;
}

#endif