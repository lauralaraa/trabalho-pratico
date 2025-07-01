#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Produto {
    char nome[100];
    int codigo;
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
    while (fscanf(arquivo, "%d,%49[^,],%d,%f\n", &p.codigo, p.nome, &p.estoque, &p.preco) == 4) {
        if (p.codigo > id) {
            id = p.codigo;
        }
    }
    fclose(arquivo);
    return id+1;

}

void buscarProduto() {

}

void cadastrarProduto() {

    Produto produto;
    getchar();
    system("cls||clear");
    printf("\nInsira o nome do produto\n");
    fgets(produto.nome, 100, stdin);
    system("cls||clear");
    printf("\nInira a quantidade em estoque\n");
    scanf("%d",&produto.estoque);
    system("cls||clear");
    printf("\nInsira o preco unitario\n");
    scanf("%f",&produto.preco);
    getchar();
    system("cls||clear");
    
    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%d;%d;%f\n", produto.nome, proximoIDproduto(), produto.estoque, produto.preco);
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