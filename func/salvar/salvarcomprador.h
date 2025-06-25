#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<comprador.h>

void salvarProduto(Comprador c) {
    FILE *arquivo = fopen("compradores.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s;%s;%s,%s,%s\n", c.nome, c.cpf, c.email, c.endereco.bairro, c.endereco.rua, c.endereco.cidade, c.endereco.cep);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}