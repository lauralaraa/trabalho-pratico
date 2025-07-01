#ifndef NOTAS_H
#define NOTAS_H
#include<stdio.h>
#include<stdlib.h>
#include"compradores.h"

void gerarNota() {

    Comprador comprador;

    FILE *arq = fopen("nota.txt", "w");
    if (arq != NULL) {
    fprintf(arq, "Nome: %s\nCPF: %s\nEmail: %s\nEndereço: %s,%s,%s,%s,%s,%s,%s ", comprador.nome, comprador.cpf, comprador.email, comprador.endereco.bairro, comprador.endereco.rua, comprador.endereco.cidade, comprador.endereco.cep);
    fclose(arq);
    } else {
        printf("Erro ao gerar a nota fiscal.\n");
    }
}


#endif