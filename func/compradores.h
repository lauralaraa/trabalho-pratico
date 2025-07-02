#ifndef COMPRADORES_H
#define COMPRADORES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "endereco.h"
#include "limparbuffer.h"

typedef struct {
    char nome[100];
    char cpf[15];
    char email[50];
    Endereco endereco;
} Comprador;


void cadastrarComprador();
void editarComprador();
void consultarComprador();
void deletarComprador();
void menuComprador();
Endereco editarEndereco(Endereco enderecoAtual);

void cadastrarComprador() {
    FILE *arquivo = fopen("compradores.txt", "a");
    if (arquivo == NULL) {
        printf("Erro fatal: Nao foi possivel abrir compradores.txt\n");
        system("pause");
        return;
    }

    Comprador c;
    limparBuffer();
    system("cls||clear");

    printf("--- Cadastrar Novo Comprador ---\n");
    printf("Nome completo: ");
    fgets(c.nome, 100, stdin);
    c.nome[strcspn(c.nome, "\n")] = 0;

    printf("CPF (apenas numeros): ");
    fgets(c.cpf, 15, stdin);
    c.cpf[strcspn(c.cpf, "\n")] = 0;

    printf("E-mail: ");
    fgets(c.email, 50, stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    c.endereco = cadastrarEndereco();

    fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s;%s\n", c.nome, c.cpf, c.email,
            c.endereco.rua, c.endereco.bairro, c.endereco.cidade, c.endereco.estado, c.endereco.cep);
    fclose(arquivo);
    printf("\nComprador '%s' cadastrado com sucesso!\n", c.nome);
    system("pause");
}

void editarComprador() {
    char cpfBusca[15];
    int encontrado = 0;
    
    system("cls||clear");
    printf("Digite o CPF do comprador que deseja editar: ");
    limparBuffer();
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    FILE *f_orig = fopen("compradores.txt", "r");
    FILE *f_temp = fopen("temp.txt", "w");

    if (f_orig == NULL || f_temp == NULL) {
        printf("Erro ao abrir arquivos para edicao.\n");
        system("pause");
        return;
    }

    Comprador c;
    char linha[300];
    while(fgets(linha, sizeof(linha), f_orig)){
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]",
                  c.nome, c.cpf, c.email, c.endereco.rua, c.endereco.bairro, c.endereco.cidade, c.endereco.estado, c.endereco.cep);
        
        if (strcmp(c.cpf, cpfBusca) == 0) {
            encontrado = 1;
            system("cls||clear");
            printf("--- Editando Comprador: %s ---\n", c.nome);
            
            char buffer[100];
            printf("Novo nome (Atual: %s): ", c.nome);
            fgets(buffer, 100, stdin);
            if(strlen(buffer) > 1) {
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(c.nome, buffer);
            }

            printf("Novo e-mail (Atual: %s): ", c.email);
            fgets(buffer, 50, stdin);
            if(strlen(buffer) > 1) {
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(c.email, buffer);
            }
            
            c.endereco = editarEndereco(c.endereco);
             fprintf(f_temp, "%s;%s;%s;%s;%s;%s;%s;%s\n", c.nome, c.cpf, c.email,
                c.endereco.rua, c.endereco.bairro, c.endereco.cidade, c.endereco.estado, c.endereco.cep);
        } else {
            fprintf(f_temp, "%s", linha);
        }
    }
    
    fclose(f_orig);
    fclose(f_temp);

    if (encontrado) {
        remove("compradores.txt");
        rename("temp.txt", "compradores.txt");
        printf("\nComprador atualizado com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("\nComprador com CPF '%s' nao encontrado.\n", cpfBusca);
    }
    system("pause");
}

void consultarComprador() {
    char cpfBusca[15];
    int encontrado = 0;
    Comprador comprador;

    system("cls||clear");
    printf("Digite o CPF do comprador que deseja consultar: ");
    limparBuffer();
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    FILE *arquivo = fopen("compradores.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de compradores nao encontrado.\n");
        system("pause");
        return;
    }
    
    while (fscanf(arquivo, "%99[^;];%14[^;];%49[^;];%49[^;];%49[^;];%49[^;];%2[^;];%19[^\n]\n",
                  comprador.nome, comprador.cpf, comprador.email, comprador.endereco.rua, comprador.endereco.bairro, comprador.endereco.cidade, comprador.endereco.estado, comprador.endereco.cep) == 8) {
        if(strcmp(comprador.cpf, cpfBusca) == 0){
            encontrado = 1;
            system("cls||clear");
            printf("--- Dados do Comprador ---\n");
            printf("Nome: %s\n", comprador.nome);
            printf("CPF: %s\n", comprador.cpf);
            printf("E-mail: %s\n", comprador.email);
            printf("Endereco: %s, %s, %s - %s, CEP: %s\n\n", comprador.endereco.rua, comprador.endereco.bairro, comprador.endereco.cidade, comprador.endereco.estado, comprador.endereco.cep);
            break;
        }
    }
    fclose(arquivo);

    if(!encontrado){
        printf("\nComprador com CPF '%s' nao encontrado.\n", cpfBusca);
    }
    system("pause");
}

void deletarComprador() {
    char cpfBusca[15];
    int encontrado = 0;
    

    system("cls||clear");
    printf("Digite o CPF do comprador a ser deletado: ");
    limparBuffer();
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    FILE *f_orig = fopen("compradores.txt", "r");
    FILE *f_temp = fopen("temp.txt", "w");

    if (f_orig == NULL || f_temp == NULL) {
        printf("Erro ao abrir arquivos para delecao.\n");
        system("pause");
        return;
    }

    char linha[300];
    while(fgets(linha, sizeof(linha), f_orig)){
        char cpfAtual[15];
        sscanf(linha, "%*[^;];%[^;]", cpfAtual);

        if(strcmp(cpfAtual, cpfBusca) != 0){
            fprintf(f_temp, "%s", linha);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(f_orig);
    fclose(f_temp);

    if (encontrado) {
        remove("compradores.txt");
        rename("temp.txt", "compradores.txt");
        printf("\nComprador deletado com sucesso!\n");
    } else {
        remove("temp.txt");
        printf("\nComprador com CPF '%s' nao encontrado.\n", cpfBusca);
    }
    system("pause");
}

void menuComprador() {
    int select;
    while(1){
        system("cls||clear");
        printf("\n--- Modulo de Compradores ---\n\n");
        printf("[1] Cadastrar\n");
        printf("[2] Consultar\n");
        printf("[3] Editar\n");
        printf("[4] Deletar\n\n");
        printf("[0] Voltar\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d",&select);
        switch(select) {
            case 0: return;
            case 1: cadastrarComprador(); break;
            case 2: consultarComprador(); break;
            case 3: editarComprador(); break;
            case 4: deletarComprador(); break;
            default: break;
        }
    }
}

#endif