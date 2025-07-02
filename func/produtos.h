#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "limparbuffer.h"
typedef struct Produto {
    char nome[100];
    int id;
    int estoque;
    float preco;
} Produto;

int proximoIDproduto() {

    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo==NULL) {
        return 1;
    }
    Produto p;
    int id = 0;
    while (fscanf(arquivo, "%d;%99[^;];%d;%f\n", &p.id, p.nome, &p.estoque, &p.preco) == 4) {
        if (p.id > id) {
            id = p.id;
        }
    }
    fclose(arquivo);
    return id + 1;
}

void cadastrarProduto() {

    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo==NULL) { 
        system("cls||clear");
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause");
        return;
    }

    Produto produto;
    limparBuffer();
    system("cls||clear");

    printf("\nInsira o nome do produto: ");
    fgets(produto.nome, 100, stdin);
    produto.nome[strcspn(produto.nome, "\n")] = 0;

    printf("\nInsira a quantidade em estoque: ");
    scanf("%d", &produto.estoque);
    limparBuffer();

    printf("\nInsira o preco unitario: ");
    scanf("%f", &produto.preco);
    limparBuffer();
    system("cls||clear");

    produto.id=proximoIDproduto();

    if(produto.estoque<0||produto.preco<0){

        printf("Quantidade em estoque/valor do preco invalido(s)\n");
        system("pause");
        fclose(arquivo);

        }else{
    fprintf(arquivo, "%d;%s;%d;%.2f\n", produto.id, produto.nome, produto.estoque, produto.preco);
    fflush(arquivo);
    fclose(arquivo);

    printf("\nProduto '%s' (ID: %d) cadastrado com sucesso!\n", produto.nome, produto.id);
    system("pause");
        }
}

void editarProduto() {
    int idBusca;
    int encontrado = 0;
    Produto produto;

    system("cls||clear");
    printf("\n--- Editar Produto ---\n");
    printf("Digite o ID do produto que deseja editar:\n");
    scanf("%d", &idBusca);
    limparBuffer();

    FILE *arquivoOriginal = fopen("produtos.txt", "r");
    FILE *arquivoTemp = fopen("produtos_temp.txt", "w");

    if (arquivoOriginal == NULL || arquivoTemp == NULL) {
        printf("\nErro ao abrir os arquivos! Verifique se 'produtos.txt' existe.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }

    while (fscanf(arquivoOriginal, "%d;%99[^;];%d;%f\n", &produto.id, produto.nome, &produto.estoque, &produto.preco) == 4) {
        if (produto.id == idBusca) {
            encontrado = 1;
            printf("\n--- Produto Encontrado (ID: %d) ---\n", produto.id);
            printf("Nome atual: %s\n", produto.nome);
            system("pause");
            system("cls||clear");
            printf("------------------------------------\n");
            printf("Insira os novos dados:\n");

            printf("Novo nome do produto:\n");
            fgets(produto.nome, 100, stdin);
            produto.nome[strcspn(produto.nome, "\n")] = 0;
            system("cls||clear");

            printf("Nova quantidade em estoque: ");
            scanf("%d", &produto.estoque);
            system("cls||clear");

            printf("Novo preco unitario: ");
            scanf("%f", &produto.preco);
            system("cls||clear");
            limparBuffer();

            fprintf(arquivoTemp, "%d;%s;%d;%.2f\n", produto.id, produto.nome, produto.estoque, produto.preco);
            printf("\n>> Produto atualizado com sucesso! <<\n");
        } else {
            fprintf(arquivoTemp, "%d;%s;%d;%.2f\n", produto.id, produto.nome, produto.estoque, produto.preco);
        }
    }

    fclose(arquivoOriginal);
    fclose(arquivoTemp);

    if (encontrado) {
        remove("produtos.txt");
        rename("produtos_temp.txt", "produtos.txt");
    } else {
        remove("produtos_temp.txt");
        printf("\nERRO: Produto com o ID '%d' não foi encontrado.\n", idBusca);
    }

    printf("\nPressione Enter para voltar ao menu...");
    getchar();
}

  void deletarProduto() {

    int id;
    
    system("cls||clear");
    printf("Digite o ID do produto que deseja remover: ");
    scanf("%d", &id);
    limparBuffer();
    
    FILE *arquivo = fopen("produtos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    
    if(arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }
    
    char linha[200];
    int encontrado = 0;
    
    while(fgets(linha, 200, arquivo) != NULL) {

        int idAtual;
        sscanf(linha, "%d", &idAtual);
        
        if(idAtual != id) {
            fprintf(temp, "%s", linha);
        } else {
            encontrado = 1;
        }
    }
    
    fclose(arquivo);
    fclose(temp);
    
    if(encontrado) {
        remove("produtos.txt");
        rename("temp.txt", "produtos.txt");
        system("cls||clear");
        printf("Produto removido com sucesso!\n");
    } else {
        remove("temp.txt");
        system("cls||clear");
        printf("Produto não encontrado!\n");
    }
    
    printf("Pressione Enter para continuar...");
    getchar();
}


void consultarProduto() {
    
    int idBusca;
    int encontrado = 0;
    Produto produto;

    system("cls||clear");

    printf("\n--- Consultar Produto ---\n");
    printf("Digite o ID do produto que deseja consultar:\n");
    scanf("%d",&idBusca);
    limparBuffer();

    FILE *arquivo = fopen("produtos.txt", "r");

    if(arquivo == NULL) {
        system("cls||clear");
        printf("Erro ao abrir o arquivo! Nao ha produtos cadastrados.\n");
        system("pause");
        return;
    }

    while (fscanf(arquivo, "%d;%99[^;];%d;%f\n", &produto.id, produto.nome, &produto.estoque, &produto.preco) == 4) {

        if(produto.id == idBusca) {
            encontrado = 1;

            system("cls||clear");
            printf("--- Produto Encontrado ---\n\n");
            printf("ID: %d\n", produto.id);
            printf("Nome: %s\n", produto.nome);
            printf("Quantidade em Estoque: %d\n", produto.estoque);
            printf("Preco: R$ %.2f\n\n", produto.preco);
            break;
        }

}

    fclose(arquivo);

    if(!encontrado) {
        system("cls||clear");
        printf("\nProduto com o ID '%d' nao foi encontrado.\n\n", idBusca);
    }

    system("pause");

}

void menuProduto() {

    int flag=1;
    int select;

    while(flag==1){
    system("cls||clear");
    printf("\nProdutos\n\n");
    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Deletar\n\n");
    printf("[0] Voltar\n\n: ");

    scanf("%d", &select);

    switch (select) {
        case 0: flag=0; break;
        case 1: cadastrarProduto(); break;
        case 2: consultarProduto(); break;
        case 3: editarProduto(); break;
        case 4: deletarProduto(); break;
        default: flag=1; break;
    }
}
}

#endif
