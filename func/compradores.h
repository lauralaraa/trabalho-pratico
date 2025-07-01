#ifndef COMPRADORES_H
#define COMPRADORES_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"endereco.h"
#include"limparbuffer.h"

typedef struct Comprador {
    char nome[100];
    char cpf[15];
    char email[50];
    Endereco endereco;
}Comprador;

void buscarComprador() {

}

void cadastrarComprador () {

    FILE *arquivo = fopen("compradores.txt", "a");
    if (arquivo==NULL) { 
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause"); 
    }

    Comprador comprador;
    limparBuffer();
    system("cls||clear");

    printf("\nInsira o nome do comprador: ");
    fgets(comprador.nome,100,stdin);
    system("cls||clear");

    printf("\nInsira o cpf do comprador: ");
    fgets(comprador.cpf,15,stdin);
    system("cls||clear");

    printf("\nInsira o email do comprador: ");
    fgets(comprador.email,15,stdin);
    system("cls||clear");
    limparBuffer();

    comprador.endereco=cadastrarEndereco();

        fprintf(arquivo, "%s;%s;%s;%s;%s,%s,%s\n", comprador.nome, comprador.cpf, comprador.email, comprador.endereco.bairro, comprador.endereco.rua, comprador.endereco.cidade, comprador.endereco.cep);
        fclose(arquivo);

    printf("\nComprador '%s' (CPF: %s) cadastrado com sucesso!\n", comprador.nome, comprador.cpf);
    system("pause");
    
}

void editarComprador() {

    char cpfBusca[15];
    int encontrado = 0;

    system("cls||clear");
    printf("Digite o CPF do comprador que deseja editar:\n");
    fgets(cpfBusca, 15, stdin);
    system("cls||clear");

    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    FILE *arquivoOriginal = fopen("compradores.txt", "r");
    FILE *arquivoTemporario = fopen("temp.txt", "w");

    if(arquivoOriginal == NULL || arquivoTemporario == NULL) {

        printf("Erro ao abrir os arquivos!\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    Comprador comprador;
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivoOriginal) != NULL) {
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^,],%[^,],%[^\n]",
               comprador.nome,
               comprador.cpf,
               comprador.email,
               comprador.endereco.bairro,
               comprador.endereco.rua,
               comprador.endereco.cidade,
               comprador.endereco.cep);

               if(strcmp(comprador.cpf, cpfBusca) == 0) {
                encontrado = 1;
                printf("Comprador encontrado! Insira os novos dados:\n");

                limparBuffer();

                printf("Novo nome: ");
                fgets(comprador.nome, 100, stdin);
                system("cls||clear");
                comprador.nome[strcspn(comprador.nome, "\n")] = 0;

                printf("Novo email: ");
                fgets(comprador.email,50,stdin);
                system("cls||clear");
                comprador.email[strcspn(comprador.email, "\n")] = 0;

                comprador.endereco = editarEndereco();

                fprintf(arquivoTemporario, "%s;%s;%s;%s;%s,%s,%s\n",
                comprador.nome,
                    comprador.cpf, // Mantém o CPF original
                    comprador.email,
                    comprador.endereco.bairro,
                    comprador.endereco.rua,
                    comprador.endereco.cidade,
                    comprador.endereco.cep);

                    printf("\nComprador atualizado com sucesso!\n");

                        } else{

                fprintf(arquivoTemporario, "%s", linha);

               }

    }

    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    if(encontrado) {
        remove("compradores.txt");
        rename("temp.txt", "compradores.txt");
    } else{
        remove("temp.txt");
        printf("\nComprador com o CPF '%s' nao foi encontrado.\n", cpfBusca);
    }

}



void deletarComprador() {
    
}

void consultarComprador() {

}

void menuComprador() {

    system("cls||clear");

    int select;

    printf("\nCompradores\n\n");

    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Excluir\n\n");
    printf("[0] Voltar\n\n: ");
    
    scanf("%d",&select);

    switch(select) {

        case 0: return; break;

        case 1: cadastrarComprador(); break;
        
        case 2: consultarComprador(); break;

        case 3: editarComprador(); break;

        case 4: deletarComprador(); break;

        default: menuComprador(); break;

    }
}

#endif