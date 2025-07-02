#ifndef VENDAS_H
#define VENDAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "limparbuffer.h"
#include "produtos.h"   
#include "vendedores.h" 

typedef struct {
    int idProduto;
    int quantidade;
    float precoUnitario;
} ItemVenda;

typedef struct {
    int id;
    char cpfComprador[15];
    int idVendedor;
    float valorTotal;
    ItemVenda itens[50]; 
    int numItens;
} Venda;


int proximoIDvenda() {
    FILE *arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL) return 1;
    int id = 0, idAtual;
    char linha[256];
    while(fgets(linha, sizeof(linha), arquivo)){
        sscanf(linha, "%d;", &idAtual);
        if(idAtual > id) id = idAtual;
    }
    fclose(arquivo);
    return id + 1;
}


void atualizarEstoqueProduto(int idProduto, int quantidadeVendida) {
    FILE *f_orig = fopen("produtos.txt", "r");
    FILE *f_temp = fopen("temp.txt", "w");
    if (!f_orig || !f_temp) return;

    Produto p;
    while (fscanf(f_orig, "%d;%99[^;];%d;%f\n", &p.id, p.nome, &p.estoque, &p.preco) == 4) {
        if (p.id == idProduto) {
            p.estoque -= quantidadeVendida; 
        }
        fprintf(f_temp, "%d;%s;%d;%.2f\n", p.id, p.nome, p.estoque, p.preco);
    }
    fclose(f_orig);
    fclose(f_temp);
    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");
}


void atualizarComissaoVendedor(int idVendedor, float valorVenda) {
    FILE *f_orig = fopen("vendedores.txt", "r");
    FILE *f_temp = fopen("temp.txt", "w");
    if (!f_orig || !f_temp) return;

    Vendedor v;
    float comissao = valorVenda * 0.03;
    while (fscanf(f_orig, "%d;%99[^;];%f;%f\n", &v.id, v.nome, &v.salario, &v.comissao) == 4) {
        if (v.id == idVendedor) {
            v.comissao += comissao; 
        }
        fprintf(f_temp, "%d;%s;%.2f;%.2f\n", v.id, v.nome, v.salario, v.comissao);
    }
    fclose(f_orig);
    fclose(f_temp);
    remove("vendedores.txt");
    rename("temp.txt", "vendedores.txt");
}


void cadastrarVenda() {
    Venda v;
    v.id = proximoIDvenda();
    v.valorTotal = 0;
    v.numItens = 0;

    system("cls||clear");
    printf("--- Iniciando Nova Venda (ID: %d) ---\n", v.id);
    limparBuffer();

    printf("Digite o CPF do comprador: ");
    fgets(v.cpfComprador, 15, stdin);
    v.cpfComprador[strcspn(v.cpfComprador, "\n")] = 0;
    

    printf("Digite o ID do vendedor: ");
    scanf("%d", &v.idVendedor);
    limparBuffer();
    

    char continuar = 's';
    while ((continuar == 's' || continuar == 'S') && v.numItens < 50) {
        system("cls||clear");
        printf("--- Venda %d | Itens: %d | Total Parcial: R$%.2f ---\n", v.id, v.numItens, v.valorTotal);
        
        int idProdBusca;
        printf("Digite o ID do produto: ");
        scanf("%d", &idProdBusca);

        Produto p;
        FILE* f_prod = fopen("produtos.txt", "r");
        int prodEncontrado = 0;
        if(f_prod != NULL){
            while(fscanf(f_prod, "%d;%99[^;];%d;%f\n", &p.id, p.nome, &p.estoque, &p.preco) == 4){
                if(p.id == idProdBusca){
                    prodEncontrado = 1;
                    break;
                }
            }
            fclose(f_prod);
        }

        if(prodEncontrado){
            printf("Produto: %s | Estoque: %d | Preco: R$%.2f\n", p.nome, p.estoque, p.preco);
            int qtdDesejada;
            printf("Digite a quantidade: ");
            scanf("%d", &qtdDesejada);

            if(qtdDesejada > 0 && qtdDesejada <= p.estoque){
                v.itens[v.numItens].idProduto = p.id;
                v.itens[v.numItens].quantidade = qtdDesejada;
                v.itens[v.numItens].precoUnitario = p.preco;
                v.valorTotal += qtdDesejada * p.preco;
                v.numItens++;
                printf("Produto adicionado!\n");
            } else {
                printf("Erro: Estoque insuficiente ou quantidade invalida.\n");
            }
        } else {
            printf("Erro: Produto com ID %d nao encontrado.\n", idProdBusca);
        }

        printf("Adicionar outro produto? (s/n): ");
        limparBuffer();
        scanf(" %c", &continuar);
    }

    if(v.numItens > 0){
        FILE* f_vendas = fopen("vendas.txt", "a");
        FILE* f_itens = fopen("itens_venda.txt", "a");
        
        if(f_vendas && f_itens){
            fprintf(f_vendas, "%d;%s;%d;%.2f\n", v.id, v.cpfComprador, v.idVendedor, v.valorTotal);
            
            for(int i = 0; i < v.numItens; i++){
                fprintf(f_itens, "%d;%d;%d;%.2f\n", v.id, v.itens[i].idProduto, v.itens[i].quantidade, v.itens[i].precoUnitario);
                atualizarEstoqueProduto(v.itens[i].idProduto, v.itens[i].quantidade);
            }
            
            atualizarComissaoVendedor(v.idVendedor, v.valorTotal);

            fclose(f_vendas);
            fclose(f_itens);
            printf("\nVenda %d finalizada com sucesso!\n", v.id);
        }
    } else {
        printf("\nVenda cancelada.\n");
    }
    system("pause");
}

#endif