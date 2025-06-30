#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cadastrovendas.h>
#include<cadastroprodutovenda.h>

void salvarProduto(Venda v) {
    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s;%.2f;%.2f%\n", v.codigovenda, v.produto.codigo, v.produto.nome, v.produto.precounidade, v.produto.precototal);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }