#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vendas.h>

void salvarProduto(Venda v) {
    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "\n", );
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }