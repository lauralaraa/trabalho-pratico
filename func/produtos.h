#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "limparbuffer.h"

#define CAMINHO_PRODUTOS "docs/produtos.txt"
#define CAMINHO_PRODUTOS_TEMP "docs/produtos_temp.txt"

typedef struct Produto {
    char nome[100];
    int id;
    int estoque;
    float preco;
} Produto;

int proximoIDproduto() {

    FILE *arquivo = fopen("docs/produtos.txt", "r");
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

    FILE *arquivo = fopen("docs/produtos.txt", "a");
    if (arquivo==NULL) { 
        system("cls||clear");
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause");
        return;
    }

    Produto produto;
    limparBuffer();
    system("cls||clear");

    printf("\nInsira o nome do produto\n");
    fgets(produto.nome, 100, stdin);
    produto.nome[strcspn(produto.nome, "\n")] = 0;

    printf("\nInsira a quantidade em estoque\n");
    scanf("%d", &produto.estoque);
    limparBuffer();

    printf("\nInsira o preco unitario\n");
    scanf("%f", &produto.preco);
    limparBuffer();
    system("cls||clear");

    produto.id=proximoIDproduto();
    
    
    fprintf(arquivo, "%d;%s;%d;%f\n", produto.id, produto.nome, produto.estoque, produto.preco);
    fflush(arquivo);
    fclose(arquivo);

    printf("\nProduto '%s' (ID: %d) cadastrado com sucesso!\n", produto.nome, produto.id);
    system("pause");
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

    FILE *arquivoOriginal = fopen(CAMINHO_PRODUTOS, "r");
    FILE *arquivoTemp = fopen(CAMINHO_PRODUTOS_TEMP, "w");

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
            printf("------------------------------------\n");
            printf("Insira os novos dados:\n");

            printf("Novo nome do produto:\n");
            fgets(produto.nome, 100, stdin);
            produto.nome[strcspn(produto.nome, "\n")] = 0;

            printf("Nova quantidade em estoque: ");
            scanf("%d", &produto.estoque);

            printf("Novo preco unitario: ");
            scanf("%f", &produto.preco);
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
        remove(CAMINHO_PRODUTOS);
        rename(CAMINHO_PRODUTOS_TEMP, CAMINHO_PRODUTOS);
    } else {
        remove(CAMINHO_PRODUTOS_TEMP);
        printf("\nERRO: Produto com o ID '%d' não foi encontrado.\n", idBusca);
    }

    printf("\nPressione Enter para voltar ao menu...");
    getchar();
}

void deletarProduto() {
    // implementar depois
}

void consultarProduto() {
    // implementar depois
}

void menuProduto() {
    system("cls||clear");

    int select;

    printf("\nProdutos\n\n");
    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Excluir\n\n");
    printf("[0] Voltar\n\n: ");

    scanf("%d", &select);

    switch (select) {
        case 0: return;
        case 1: cadastrarProduto(); break;
        case 2: consultarProduto(); break;
        case 3: editarProduto(); break;
        case 4: deletarProduto(); break;
        default: menuProduto(); break;
    }
}

#endif
