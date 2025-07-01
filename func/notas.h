#ifndef NOTAS_H
#define NOTAS_H
#include<stdio.h>
#include<stdlib.h>
#include"compradores.h"
#include"vendas.h"

void gerarNota() {

    Comprador comprador;
    Venda venda;

    FILE *arq = fopen("nota.txt", "w");
    if (arq != NULL) {
    fprintf(arq, "Nome: %s\nCPF: %s\nEmail: %s\nEndereço: %s,%s,%s,%s", comprador.nome, comprador.cpf, comprador.email, comprador.endereco.bairro, comprador.endereco.rua, comprador.endereco.cidade, comprador.endereco.cep);
        
        if (venda.valortotal <= 100){
            fprintf(arq, "Valor da venda: %.2f\n", venda.valortotal);
            fprintf(arq, "Valor do frete: R$ 30,00\n");
            fprintf(arq, "Valor total: R$ %.2f\n", venda.valortotal + 30);
        }
        else if (venda.valortotal > 100 && venda.valortotal <= 300){
            fprintf(arq, "Valor da venda: %.2f\n", venda.valortotal);
            fprintf(arq, "Valor do frete: R$ 20,00\n");
            fprintf(arq, "Valor total: R$ %.2f\n", venda.valortotal + 20);
        }
        else {
            fprintf(arq, "Valor da venda: %.2f\n", venda.valortotal);
            fprintf(arq, "Frete grátis para compras acima de R$ 300,00!\n");
            fprintf(arq, "Valor total: R$ %.2f\n", venda.valortotal);
        }

    fclose(arq);
    } else {
        printf("Erro ao gerar a nota fiscal.\n");
    }
}


#endif