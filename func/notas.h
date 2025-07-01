#ifndef NOTAS_H
#define NOTAS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "compradores.h"
#include "produtos.h"
#include "vendas.h"

void gerarNota(Comprador infoComprador, Produto infoProduto, Venda infoVenda) {

    FILE *arquivoNota = fopen("nota.txt", "w");
    
      if (arquivoNota == NULL) {
        perror("Erro ao abrir arquivos"); 
        return;
      }
    
    fprintf(arquivoNota, "Nota Fiscal: \n\n");
    fprintf(arquivoNota, "Dados do comprador:\n");
    fprintf(arquivoNota, "Nome do Comprador: %s\n", infoComprador.nome);
    fprintf(arquivoNota, "CPF: %s\n", infoComprador.cpf);
    fprintf(arquivoNota, "Email: %s\n", infoComprador.email);
    fprintf(arquivoNota, "Endereco: %s, %s, %s, %s\n", infoComprador.endereco.rua, infoComprador.endereco.bairro, infoComprador.endereco.cidade, infoComprador.endereco.cep);
    fprintf(arquivoNota, "\nProdutos vendidos:\n");
    fprintf(arquivoNota, "Produto: %s\n", infoProduto.nome);
    fprintf(arquivoNota, "Preço do produto: %.2f\n", infoProduto.preco);
    fprintf(arquivoNota, "Quantidade comprada: %d\n", infoVenda.quantidade);
    fprintf(arquivoNota, "\nPreço: %.2f\n", infoVenda.valortotal);
    if (infoVenda.valortotal <= 100){
            fprintf(arquivoNota, "Valor da venda: %.2f\n", infoVenda.valortotal);
            fprintf(arquivoNota, "Valor do frete: R$ 30,00\n");
            fprintf(arquivoNota, "Valor total: R$ %.2f\n", infoVenda.valortotal + 30);
        }
        else if (infoVenda.valortotal > 100 && infoVenda.valortotal <= 300){
            fprintf(arquivoNota, "Valor da infoVenda: %.2f\n", infoVenda.valortotal);
            fprintf(arquivoNota, "Valor do frete: R$ 20,00\n");
            fprintf(arquivoNota, "Valor total: R$ %.2f\n", infoVenda.valortotal + 20);
        }
        else {
            fprintf(arquivoNota, "Valor da infoVenda: %.2f\n", infoVenda.valortotal);
            fprintf(arquivoNota, "Frete grátis para compras acima de R$ 300,00!\n");
            fprintf(arquivoNota, "Valor total: R$ %.2f\n", infoVenda.valortotal);
        }

    
    fclose(arquivoNota);

}

#endif