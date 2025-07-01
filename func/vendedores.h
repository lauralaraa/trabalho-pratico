#ifndef VENDEDORES_H
#define VENDEDORES_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"limparbuffer.h"

typedef struct Vendedor {
    char nome[100];
    int id;
    float salario;
    float comissao;
}Vendedor;

int proximoIDvendedor() {

     FILE *arquivo = fopen("vendedores.txt", "r");
    if (arquivo == NULL) {
        return 1;
    }
    Vendedor v;
    int id = 0;
    while (fscanf(arquivo, "%49[^,];%d;%f;%f\n",&v.nome,&v.id,&v.salario,&v.comissao) == 4) {
        if (v.id > id) {
            id = v.id;
        }
    }
    fclose(arquivo);
    return id+1;
}

void buscarVendedor() {

}

void cadastrarVendedor() {

    FILE *arquivo = fopen("vendedores.txt", "a");
    if (arquivo==NULL) { 
        system("cls||clear");
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause"); 
        return;
    }

    int vendascom;
    Vendedor vendedor;
    limparBuffer();
    system("cls||clear");

    printf("\nInsira o nome do vendedor\n");
    fgets(vendedor.nome,100,stdin);
    system("cls||clear");

    printf("\nInsira o salario fixo atual do vendedor\n");
    scanf("%f",&vendedor.salario);
    limparBuffer();
    system("cls||clear");

    vendedor.id=proximoIDvendedor();
    vendedor.comissao=(vendascom/100)*3;

    fprintf(arquivo, "%s;%d;%f;%f\n", vendedor.nome, vendedor.id, vendedor.salario, vendedor.comissao);
    fclose(arquivo);

    printf("\nVendedor '%s' (ID: %d) cadastrado com sucesso!\n", vendedor.nome, vendedor.id);
    system("pause");
}

void editarVendedor() {

    int codigoBusca;
    int encontrado = 0;
    Vendedor vendedor;

    system("cls||clear");
    printf("\nEditar Vendedor\n");
    printf("Digite o codigo do vendedor que deseja editar: ");
    scanf("%d", &codigoBusca);
    limparBuffer(); 

    FILE *arquivoOriginal = fopen("vendedores.txt", "r");
    FILE *arquivoTemp = fopen("vendedores_temp.txt", "w");

    if(arquivoOriginal = NULL || arquivoTemp == NULL) {
        system("cls||clear");
        printf("Erro ao abrir os arquivos!\n");
        printf("Pressione ENTER para continuar...\n");
        getchar();
        return;
    }

     while (fscanf(arquivoOriginal, "%[^;];%d;%f;%f\n", vendedor.nome, &vendedor.id, &vendedor.salario, &vendedor.comissao) == 4) {

        if(vendedor.id == codigoBusca) {
            encontrado = 1;
            printf("\nVendedor encontrado (Codigo: %d)\n",vendedor.id);
            printf("Nome atual: %s\n",vendedor.nome);
            printf("--------------------------------------------------\n");
            printf("Insira os novos dados:\n");

            printf("Novo nome:\n");
            fgets(vendedor.nome,100,stdin);
            system("cls||clear");

            printf("Novo salario fixo:\n");
            scanf("%f",&vendedor.salario);
            limparBuffer();

            printf("\nA comissao sera mantida/recalculada em outra area.\n");

            fprintf(arquivoTemp, "%s;%d;%f;%f\n",vendedor.nome,vendedor.id, vendedor.salario,vendedor.comissao);
            printf("\n>> Vendedor atualizado com sucesso! <<\n");

        }else {
            fprintf(arquivoTemp, "%s;%d;%f;%f\n",vendedor.nome, vendedor.id,vendedor.salario,vendedor.comissao);
}

     }

     fclose(arquivoOriginal);
     fclose(arquivoTemp);

     if(encontrado) {
        remove("vendedores.txt");
        rename("vendedores_temp.txt", "vendedores.txt");
    } else {
        remove("vendedores_temp.txt");
        printf("\nERRO: Vendedor com o codigo '%d' nao foi encontrado.\n", codigoBusca);
    }

    system("cls||clear");
    printf("\nPressione Enter para voltar ao menu...");
    getchar(); 
}
     
 


void deletarVendedor() {

}

void consultarVendedor() {

}

void menuVendedor() {

    system("cls||clear");

    int select;

    printf("\nVendedores\n\n");

    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Deletar\n\n");
    printf("[0] Voltar\n\n: ");
    
    scanf("%d",&select);

    switch(select) {

        case 0: return; break;
        case 1: cadastrarVendedor(); break;
        case 2: consultarVendedor(); break;
        case 3: editarVendedor(); break;
        case 4: deletarVendedor(); break;
        default: menuVendedor(); break;

    }

}

#endif