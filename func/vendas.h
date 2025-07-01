#ifndef VENDAS_H
#define VENDAS_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"notas.h"
#include"limparbuffer.h"

typedef struct Venda {
    int id;
    char vendedor[10];
    int quantidade;
    float valortotal;
} Venda ;

    int proximoIDvenda() {

        FILE *arquivo = fopen("vendas.txt", "r");
    if (arquivo==NULL) {
        return 1;
    }
    Venda v;
    int id = 0;
    while (fscanf(arquivo, "%d;%9[^,];%d;%f\n",&v.id,&v.vendedor,&v.quantidade,&v.valortotal) == 4) {
        if (v.id > id) {
            id = v.id;
        }
    }
    fclose(arquivo);
    return id+1;

    }

    void buscarVenda() {

    }

    void pesquisarComprador() {

    }

    void pesquisarVendedor() {
        
    }

    void pesquisarProduto() {
        
    }

    void cadastrarVenda() {

    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo==NULL) { 
        system("cls||clear");
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause"); 
    }

    Venda venda;
    system("cls||clear");
    limparBuffer();

    printf("\nInsira o codigo do vendedor\n");
    fgets(venda.vendedor,10,stdin);
    system("cls||clear");

    fprintf(arquivo, "%s;%s;\n", venda.id,venda.vendedor);
    fclose(arquivo);

    system("cls||clear");
    printf("\nVenda (ID: %d) cadastrado com sucesso!\n", venda.id);
    system("pause");

    }

    void editarVenda() {

    }

    void deletarVenda() {

    }

    void consultarVenda() {

    }

    void menuVenda() {
        system("cls||clear");

    int select;

    printf("\nVendas\n\n");

    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Excluir\n\n");
    printf("[5] Emitir Nota Fiscal\n\n");
    printf("[0] Voltar\n\n: ");
    
    scanf("%d",&select);

    switch(select) {

        case 0: return; break;
        case 1: cadastrarVenda(); break;
        case 2: consultarVenda(); break;
        case 3: editarVenda(); break;
        case 4: deletarVenda(); break;
        default: menuComprador(); break;

    }
    }

#endif