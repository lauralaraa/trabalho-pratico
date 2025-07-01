#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include"limparbuffer.h"

typedef struct Produto {
    char nome[100];
    int id;
    int estoque;
    float preco;
}Produto;

int proximoIDproduto() {

    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        return 1;
    }
    Produto p;
    int id = 0;
    while (fscanf(arquivo, "%d,%49[^,],%d,%f\n", &p.id, p.nome, &p.estoque, &p.preco) == 4) {
        if (p.id > id) {
            id = p.id;
        }
    }
    fclose(arquivo);
    return id+1;

}

void buscarProduto() {

}

void cadastrarProduto() {

    Produto produto;
    limparBuffer();
    system("cls||clear");

    printf("\nInsira o nome do produto\n");
    fgets(produto.nome, 100, stdin);
    system("cls||clear");

    printf("\nInira a quantidade em estoque\n");
    scanf("%d",&produto.estoque);
    limparBuffer();
    system("cls||clear");

    printf("\nInsira o preco unitario\n");
    scanf("%f",&produto.preco);
    limparBuffer();
    system("cls||clear");

    produto.id=proximoIDproduto();
    
    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%d;%d;%f\n", produto.nome, produto.id, produto.estoque, produto.preco);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

    main();

}

void editarProduto() {

}

void deletarProduto() {

}

void consultarProduto() {

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
    
    scanf("%d",&select);

    switch(select) {

        case 0: main(); break;
        case 1: cadastrarProduto(); break;
        case 2: consultarProduto(); break;
        case 3: editarProduto(); break;
        case 4: deletarProduto(); break;
        default: menuProduto(); break;

    }

}

#endif