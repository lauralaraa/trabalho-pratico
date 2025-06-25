#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vendedores.h>

void salvarVendedor(Vendedor v) {
    FILE *arquivo = fopen("vendedores.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%d;%d;%.2f\n", v.nome, v.numero, v.salario, v.comissao);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}