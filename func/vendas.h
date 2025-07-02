#ifndef VENDAS_H
#define VENDAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "notas.h"
#include "limparbuffer.h"

typedef struct Venda
{
    int id;
    char vendedor[50];
    int quantidade;
    float valortotal;
} Venda;

int proximoIDvenda()
{

    FILE *arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL)
    {
        return 1;
    }
    Venda v;
    int idMaximo = 0;
    while (fscanf(arquivo, "%d;%49[^;];%d;%f\n", &v.id, &v.vendedor, &v.quantidade, &v.valortotal) == 4)
    {
        if (v.id > idMaximo)
        {
            idMaximo = v.id;
        }
    }
    fclose(arquivo);
    return idMaximo + 1;
}

void buscarVenda()
{
}

void pesquisarComprador()
{
}

void pesquisarVendedor()
{
}

void pesquisarProduto()
{
}

void cadastrarVenda()
{

    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo == NULL)
    {
        system("cls||clear");
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause");
        return;
    }

    Venda venda;
    system("cls||clear");
    limparBuffer();

    venda.id = proximoIDvenda();

    printf("\n--- Nova Venda (ID: %d) ---\n", venda.id);

    printf("\nInsira o nome do vendedor\n");
    fgets(venda.vendedor, 50, stdin);
    venda.vendedor[strcspn(venda.vendedor, "\n")] = 0;
    system("cls||clear");

    printf("Insira a quantidade de itens: ");
    scanf("%d", &venda.quantidade);

    printf("Insira o valor total da venda: ");
    scanf("%f", &venda.valortotal);
    limparBuffer();

    
    fprintf(arquivo, "%d;%s;%d;%.2f\n", venda.id, venda.vendedor, venda.quantidade, venda.valortotal);
    fclose(arquivo);

    system("cls||clear");
    printf("\nVenda (ID: %d) cadastrada com sucesso!\n", venda.id);
    system("pause");
}

void editarVenda() {
    int idBusca; 
    int encontrado = 0;
    Venda venda;

    system("cls||clear");
    printf("\n--- Editar Venda ---\n");
    
    printf("Digite o ID da venda que deseja editar: ");
    scanf("%d", &idBusca);
    limparBuffer();

    FILE *arquivoOriginal = fopen("vendas.txt", "r");
    FILE *arquivoTemp = fopen("vendas_temp.txt", "w");

    if (arquivoOriginal == NULL || arquivoTemp == NULL) {
        printf("\nErro ao abrir os arquivos! Verifique se 'vendas.txt' existe.\n");
        system("pause");
        return;
    }

    
    while (fscanf(arquivoOriginal, "%d;%49[^;];%d;%f\n", &venda.id, venda.vendedor, &venda.quantidade, &venda.valortotal) == 4) {
        
        if (venda.id == idBusca) {
            encontrado = 1;
            system("cls||clear");
<<<<<<< HEAD
            printf("\n--- Venda Encontrada (%s) ---\n", venda.id);
            printf("Insira os novos dados:\n\n");

            printf("Novo codigo do vendedor:\n");
            fgets(venda.vendedor, 10, stdin);
            system("cls||clear");
=======
            printf("\n--- Venda Encontrada (ID: %d) ---\n", venda.id);
            printf("Insira os novos dados:\n\n");

            printf("Novo nome do vendedor: ");
            fgets(venda.vendedor, 50, stdin);
>>>>>>> 1adff5695ef755f1502b14702a9a4a1b926945b4
            venda.vendedor[strcspn(venda.vendedor, "\n")] = 0;

            printf("Nova quantidade de itens: ");
            scanf("%d", &venda.quantidade);
            system("cls||clear");
            limparBuffer();

            printf("Novo valor total da venda: ");
            scanf("%f", &venda.valortotal);
            limparBuffer();

<<<<<<< HEAD
            fprintf(arquivoTemp, "%s;%s;%d;%f\n", venda.id, venda.vendedor, venda.quantidade, venda.valortotal);
            system("cls||clear");
=======
>>>>>>> 1adff5695ef755f1502b14702a9a4a1b926945b4
            printf("\n>> Venda atualizada com sucesso! <<\n");
        }
        
        fprintf(arquivoTemp, "%d;%s;%d;%.2f\n", venda.id, venda.vendedor, venda.quantidade, venda.valortotal);
    }

    fclose(arquivoOriginal);
    fclose(arquivoTemp);

    if (encontrado) {
        remove("vendas.txt");
        rename("vendas_temp.txt", "vendas.txt");
    } else {
        remove("vendas_temp.txt");
<<<<<<< HEAD
        system("cls||clear");
        printf("\nERRO: Venda com o codigo '%s' nao foi encontrada.\n", codigoBusca);
    }

    printf("\nPressione ENTER para voltar ao menu...");
    limparBuffer();

=======
        printf("\nERRO: Venda com o ID '%d' nao foi encontrada.\n", idBusca);
    }

    system("pause");
>>>>>>> 1adff5695ef755f1502b14702a9a4a1b926945b4
}

void deletarVenda()
{
    int id;

    printf("Digite o ID da venda que deseja remover: "); 
    scanf("%d", &id);
    limparBuffer();

    FILE *arquivo = fopen("vendas.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
<<<<<<< HEAD
    
    if(arquivo == NULL || temp == NULL) {
        system("cls||clear");
=======

    if (arquivo == NULL || temp == NULL)
    {
>>>>>>> 1adff5695ef755f1502b14702a9a4a1b926945b4
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    char linha[200];
    int encontrado = 0;

    while (fgets(linha, 200, arquivo) != NULL)
    {
        int idAtual;
        sscanf(linha, "%d", &idAtual);

        if (idAtual != id)
        {
            fprintf(temp, "%s", linha);
        }
        else
        {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado)
    {
        remove("vendas.txt");
        rename("temp.txt", "vendas.txt");
        system("cls||clear");
        printf("Venda removida com sucesso!\n");
    }
    else
    {
        remove("temp.txt");
        system("cls||clear");
        printf("Venda não encontrada!\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
}

void consultarVenda()
{
    int idBusca;
    int encontrado = 0;
    Venda venda;

    system("cls||clear");
    printf("\n--- Consultar Venda ---\n");
    printf("Digite o ID da venda que deseja consultar: ");
    scanf("%d", &idBusca);
    limparBuffer();

    FILE *arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL) {
        system("cls||clear");
        printf("Erro ao abrir o arquivo! Nao ha vendas cadastradas.\n");
        system("pause");
        return;
    }

<<<<<<< HEAD
    void menuVenda() {
        
=======
    while (fscanf(arquivo, "%d;%49[^;];%d;%f\n", &venda.id, venda.vendedor, &venda.quantidade, &venda.valortotal) == 4) {
        if (venda.id == idBusca) {
            encontrado = 1;
            system("cls||clear");
            printf("--- Venda Encontrada ---\n\n");
            printf("ID da Venda: %d\n", venda.id);
            printf("Vendedor: %s\n", venda.vendedor);
            printf("Quantidade de Itens: %d\n", venda.quantidade);
            printf("Valor Total: R$ %.2f\n\n", venda.valortotal);
            break; 
        }
    }
    fclose(arquivo);

    if (!encontrado) {
        system("cls||clear");
        printf("\nVenda com o ID '%d' nao foi encontrada.\n\n", idBusca);
    }
    system("pause");
}

void menuVenda()
{
    system("cls||clear");
>>>>>>> 1adff5695ef755f1502b14702a9a4a1b926945b4

    int select;
    int flag=1;

    while(flag==1) {
    system("cls||clear");
    printf("\nVendas\n\n");

    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Deletar\n\n");
    printf("[5] Emitir Nota Fiscal\n\n");
    printf("[0] Voltar\n\n: ");

    scanf("%d", &select);

<<<<<<< HEAD
        case 0: flag=0; break;
        case 1: cadastrarVenda(); break;
        case 2: consultarVenda(); break;
        case 3: editarVenda(); break;
        case 4: deletarVenda(); break;
        default: flag=1; break;
=======
    switch (select)
    {
>>>>>>> 1adff5695ef755f1502b14702a9a4a1b926945b4

    case 0:
        return;
        break;
    case 1:
        cadastrarVenda();
        break;
    case 2:
        consultarVenda();
        break;
    case 3:
        editarVenda();
        break;
    case 4:
        deletarVenda();
        break;
    default:
        menuComprador();
        break;
    }
<<<<<<< HEAD
    }
    }
=======

    menuVenda();
}
>>>>>>> 1adff5695ef755f1502b14702a9a4a1b926945b4

#endif