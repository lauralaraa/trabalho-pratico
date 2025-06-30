#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cadastroprodutos.h>
#include<cadastroprodutovenda.h>

void salvarProduto(Produto p) {
    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%d;%.2f\n", p.nome, p.codigo, p.estoque, p.preco);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}