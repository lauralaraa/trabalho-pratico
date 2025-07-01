#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cadastrovendas.h"
#include"cadastroprodutovenda.h"

void salvarProduto(Venda v) {
    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s;%.2f;%.2f\n", v.codigovenda, v.produtodavenda->codigo, v.produtodavenda->nome, v.produtodavenda->precounidade, v.produtodavenda->precototal);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}