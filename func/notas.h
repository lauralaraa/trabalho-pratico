#ifndef NOTAS_H
#define NOTAS_H

#include <stdio.h>
#include <stdlib.h>
#include "compradores.h"
#include "vendas.h"
#include "produtos.h"

float calcularFrete(float valorVenda) {
    if (valorVenda <= 100.0) return 30.0;
    if (valorVenda <= 300.0) return 20.0;
    return 0.0;
}

void emitirNotaFiscal() {
    int idVendaBusca;
    system("cls||clear");
    printf("--- Emissao de Nota Fiscal ---\n");
    printf("Digite o ID da venda: ");
    scanf("%d", &idVendaBusca);

    FILE* f_vendas = fopen("vendas.txt", "r");
    if(!f_vendas) { return; }

    Venda vendaEncontrada;
    int vendaExiste = 0;
    while(fscanf(f_vendas, "%d;%14[^;];%d;%f\n", &vendaEncontrada.id, vendaEncontrada.cpfComprador, &vendaEncontrada.idVendedor, &vendaEncontrada.valorTotal) == 4){
        if(vendaEncontrada.id == idVendaBusca){
            vendaExiste = 1;
            break;
        }
    }
    fclose(f_vendas);

    if(!vendaExiste){
        printf("Erro: Venda com ID %d nao encontrada.\n", idVendaBusca);
        system("pause");
        return;
    }

    Comprador compradorEncontrado;
    int compradorExiste = 0;
    FILE* f_compradores = fopen("compradores.txt", "r");
    if(f_compradores){
        while (fscanf(f_compradores, "%99[^;];%14[^;];%49[^;];%49[^;];%49[^;];%49[^;];%2[^;];%19[^\n]\n",
                  compradorEncontrado.nome, compradorEncontrado.cpf, compradorEncontrado.email, compradorEncontrado.endereco.rua, 
                  compradorEncontrado.endereco.bairro, compradorEncontrado.endereco.cidade, 
                  compradorEncontrado.endereco.estado, compradorEncontrado.endereco.cep) == 8){
            if(strcmp(compradorEncontrado.cpf, vendaEncontrada.cpfComprador) == 0){
                compradorExiste = 1;
                break;
            }
        }
        fclose(f_compradores);
    }
    
    FILE* f_itens = fopen("itens_venda.txt", "r");
    ItemVenda itens[50];
    int numItens = 0;
    if(f_itens){
        int idVendaItem, idProd, qtd;
        float preco;
        while(fscanf(f_itens, "%d;%d;%d;%f", &idVendaItem, &idProd, &qtd, &preco) == 4){
            if(idVendaItem == idVendaBusca){
                itens[numItens].idProduto = idProd;
                itens[numItens].quantidade = qtd;
                itens[numItens].precoUnitario = preco;
                numItens++;
            }
        }
        fclose(f_itens);
    }

    float frete = calcularFrete(vendaEncontrada.valorTotal);

    system("cls||clear");
    printf("=========================================================\n");
    printf("                     NOTA FISCAL\n");
    printf("=========================================================\n");
    printf("Venda No: %d\n\n", vendaEncontrada.id);
    
    if(compradorExiste){
        printf("CLIENTE:\n");
        printf("  Nome: %s\n  CPF: %s\n", compradorEncontrado.nome, compradorEncontrado.cpf);
        printf("  Endereco: %s, %s, %s - %s, CEP: %s\n",
               compradorEncontrado.endereco.rua, compradorEncontrado.endereco.bairro,
               compradorEncontrado.endereco.cidade, compradorEncontrado.endereco.estado,
               compradorEncontrado.endereco.cep);
    }
    
    printf("---------------------------------------------------------\n");
    printf("PRODUTOS\n");
    printf("---------------------------------------------------------\n");
    printf("%-10s %-5s %-15s %-15s\n", "ID PROD.", "QTD.", "PRECO UNIT.", "PRECO TOTAL");
    for(int i=0; i<numItens; i++){
        printf("%-10d %-5d R$ %-13.2f R$ %-13.2f\n",
               itens[i].idProduto, itens[i].quantidade, itens[i].precoUnitario,
               itens[i].quantidade * itens[i].precoUnitario);
    }
    printf("---------------------------------------------------------\n");
    printf("%42s R$ %-13.2f\n", "SUBTOTAL:", vendaEncontrada.valorTotal);
    printf("%42s R$ %-13.2f\n", "FRETE:", frete);
    printf("=========================================================\n");
    printf("%42s R$ %-13.2f\n", "VALOR TOTAL:", vendaEncontrada.valorTotal + frete);
    printf("=========================================================\n\n");
    
    system("pause");
}

#endif