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
        system("cls||clear");
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause"); 
    }

    Comprador comprador;
    limparBuffer();
    system("cls||clear");

    printf("\nInsira o nome do comprador: ");
    fgets(comprador.nome,100,stdin);
    comprador.nome[strcspn(comprador.nome, "\n")] = 0;
    system("cls||clear");

    printf("\nInsira o cpf do comprador: ");
    fgets(comprador.cpf,15,stdin);
    comprador.cpf[strcspn(comprador.cpf, "\n")] = 0;
    system("cls||clear");

    limparBuffer();

    printf("\nInsira o email do comprador: ");
    fgets(comprador.email,15,stdin);
    comprador.email[strcspn(comprador.email, "\n")] = 0;
    system("cls||clear");
    

    comprador.endereco = cadastrarEndereco();

        fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s\n", comprador.nome, comprador.cpf, comprador.email, comprador.endereco.bairro, comprador.endereco.rua, comprador.endereco.cidade, comprador.endereco.cep);
        fclose(arquivo);

    system("cls||clear");
    printf("\nComprador '%s' (CPF: %s) cadastrado com sucesso!\n", comprador.nome, comprador.cpf);
    system("pause");
    
}

void editarComprador() {
    char cpfBusca[15];
    int encontrado = 0;

    
    limparBuffer(); 
    system("cls||clear");

    printf("Digite o CPF do comprador que deseja editar: ");
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0; 

    FILE *arquivoOriginal = fopen("compradores.txt", "r");
    FILE *arquivoTemporario = fopen("temp.txt", "w");

    if (arquivoOriginal == NULL || arquivoTemporario == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        system("pause");
        return;
    }

    Comprador comprador;
    char linha[300]; 

    while (fgets(linha, sizeof(linha), arquivoOriginal) != NULL) {
        
        
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]",
               comprador.nome,
               comprador.cpf,
               comprador.email,
               comprador.endereco.bairro,
               comprador.endereco.rua,
               comprador.endereco.cidade,
               comprador.endereco.cep);

        
        if (strcmp(comprador.cpf, cpfBusca) == 0) {
            encontrado = 1;
            system("cls||clear");
            printf("--- Comprador Encontrado: %s ---\n", comprador.nome);
            printf("Insira os novos dados (deixe em branco e pressione Enter para manter o atual):\n\n");

            
            char novoNome[100];
            printf("Novo nome (Atual: %s): ", comprador.nome);
            fgets(novoNome, 100, stdin);
            novoNome[strcspn(novoNome, "\n")] = 0; // Remove '\n'
            if (strlen(novoNome) > 0) { 
                strcpy(comprador.nome, novoNome);
            }

            
            char novoEmail[50];
            printf("Novo email (Atual: %s): ", comprador.email);
            fgets(novoEmail, 50, stdin);
            novoEmail[strcspn(novoEmail, "\n")] = 0;
            if (strlen(novoEmail) > 0) {
                strcpy(comprador.email, novoEmail);
            }
            
            
            printf("\nDados de endereco mantidos. (Implementar edicao de endereco se necessario)\n");


            
            fprintf(arquivoTemporario, "%s;%s;%s;%s;%s;%s;%s\n",
                    comprador.nome,
                    comprador.cpf, 
                    comprador.email,
                    comprador.endereco.bairro,
                    comprador.endereco.rua,
                    comprador.endereco.cidade,
                    comprador.endereco.cep);
            
            printf("\n>> Comprador atualizado com sucesso! <<\n");
            system("pause");

        } else {
            
            fprintf(arquivoTemporario, "%s", linha);
        }
    }

    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    if (encontrado) {
        remove("compradores.txt");
        rename("temp.txt", "compradores.txt");
    } else {
        remove("temp.txt");
        system("cls||clear");
        printf("\nComprador com o CPF '%s' nao foi encontrado.\n", cpfBusca);
        system("pause");
    }
}



void deletarComprador() {
    char cpf[15];
    int encontrado = 0;
    
    printf("Digite o CPF do comprador que deseja remover: ");
    fgets(cpf, 15, stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; 
    
    FILE *arquivo = fopen("compradores.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    
    if(arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }
    
    char linha[300];
    while(fgets(linha, 300, arquivo) != NULL) {

        char cpfAtual[15];
        sscanf(linha, "%*[^;];%[^;]", cpfAtual);
        
        if(strcmp(cpfAtual, cpf) != 0) {
            fprintf(temp, "%s", linha);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arquivo);
    fclose(temp);
    
    if(encontrado) {
        remove("compradores.txt");
        rename("temp.txt", "compradores.txt");
        system("cls||clear");
        printf("Comprador removido com sucesso!\n");
    } else {
        remove("temp.txt");
        system("cls||clear");
        printf("Comprador não encontrado!\n");
    }
    
    printf("Pressione Enter para continuar...");
    getchar();
}
    

void consultarComprador() {

    char cpfBusca[15];
    int encontrado = 0;

    system("cls||clear");
    limparBuffer();

    printf("Digite o CPF do comprador que deseja consultar:\n");
    fgets(cpfBusca, 15, stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = 0;

    FILE *arquivo = fopen("compradores.txt", "r");

    if(arquivo == NULL) {
        system("cls||clear");
        printf("Erro ao abrir o arquivo! Nao ha compradores cadastrados.\n");
        system("pause");
        return;
    }

    Comprador comprador;
    char linha[300];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]",
               comprador.nome,
               comprador.cpf,
               comprador.email,
               comprador.endereco.bairro,
               comprador.endereco.rua,
               comprador.endereco.cidade,
               comprador.endereco.cep);

               if(strcmp(comprador.cpf, cpfBusca) == 0) {
                encontrado = 1;

                system("cls||clear");
            printf("--- Dados do Comprador Encontrado ---\n\n");
            printf("Nome: %s\n", comprador.nome);
            printf("CPF: %s\n", comprador.cpf);
            printf("Email: %s\n", comprador.email);
            printf("\n--- Endereco ---\n");
            printf("Bairro: %s\n", comprador.endereco.bairro);
            printf("Rua: %s\n", comprador.endereco.rua);
            printf("Cidade: %s\n", comprador.endereco.cidade);
            printf("CEP: %s\n\n", comprador.endereco.cep);
            
            break;
               }
    }

    fclose(arquivo);
    
    if(!encontrado) {
        system("cls||clear");
        printf("\nComprador com o CPF '%s' nao foi encontrado.\n\n", cpfBusca);
    }

    system("pause");


}

void menuComprador() {

    int select;
    int flag=1;

    while(flag=1){
    system("cls||clear");
    printf("\nCompradores\n\n");

    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Deletar\n\n");
    printf("[0] Voltar\n\n: ");
    
    scanf("%d",&select);

    switch(select) {

        case 0: flag=0; break;
        case 1: cadastrarComprador(); break;
        case 2: consultarComprador(); break;
        case 3: editarComprador(); break;
        case 4: deletarComprador(); break;
        default: flag=1; break;

    }
}
}

#endif