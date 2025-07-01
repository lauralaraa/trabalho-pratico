#ifndef VENDAS_H
#define VENDAS_H
#include"notas.h"

typedef struct Venda {
    char codigovenda[10];
    char vendedor[10];
    int quantidade;
    float valortotal;
}Venda;

    void proximoIDvenda() {

    }

    void buscarVenda() {

    }

    void pesquisarComprador() {

    }

    void pesquisarVendedor() {
        
    }

    void pesquisarProduto() {
        
    }

    Venda cadastrarVenda() {

    Venda venda;

    printf("\nInsira o codigo da venda\n");
    fgets(venda.codigovenda,10,stdin);
    getchar();
    printf("\nInsira o codigo do vendedor\n");
    fgets(venda.vendedor,10,stdin);
    getchar();

   FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;\n", venda.codigovenda,venda.vendedor);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

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

    printf("\nCompradores\n\n");

    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Excluir\n\n");
    printf("[5] Emitir Nota Fiscal\n\n");
    printf("[0] Voltar\n\n: ");
    
    scanf("%d",&select);

    switch(select) {

        case 0: MainMenu(); break;

        case 1: cadastrarComprador(1); break;
        
        case 2: consultarComprador(); break;

        case 3: editarComprador(); break;

        case 4: deletarComprador(); break;

        case 5: gerarNota(); break;

        default: menuComprador(); break;

    }
    }

#endif