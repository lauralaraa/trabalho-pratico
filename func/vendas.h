#ifndef VENDAS_H
#define VENDAS_H

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

    Venda cadastroVenda() {

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

#endif