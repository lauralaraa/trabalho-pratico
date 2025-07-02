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
    int idMaximo = 0;
    while (fscanf(arquivo, "%99[^;];%d;%f;%f\n",&v.nome,&v.id,&v.salario,&v.comissao) == 4) {
        if (v.id > idMaximo) {
            idMaximo = v.id;
        }
    }
    fclose(arquivo);
    return idMaximo+1;
}

void buscarVendedor() {

}

void cadastrarVendedor() {

    FILE *arquivo = fopen("vendedores.txt", "a");
    if (arquivo == NULL) { 
        system("cls||clear");
        printf("Erro ao abrir o arquivo para escrita.\n");
        system("pause"); 
        return;
    }

    Vendedor vendedor;
    limparBuffer();
    system("cls||clear");

    printf("\n--- Cadastrar Vendedor ---\n");
    printf("\nInsira o nome do vendedor\n");
    fgets(vendedor.nome,100,stdin);
    vendedor.nome[strcspn(vendedor.nome, "\n")] = 0;
    system("cls||clear");

    printf("\nInsira o salario fixo atual do vendedor\n");
    scanf("%f",&vendedor.salario);
    limparBuffer();
    system("cls||clear");

    vendedor.id = proximoIDvendedor();
    vendedor.comissao = 0.0;

    fprintf(arquivo, "%s;%d;%.2f;%.2f\n", vendedor.nome, vendedor.id, vendedor.salario, vendedor.comissao);
    fclose(arquivo);

    printf("\nVendedor '%s' (ID: %d) cadastrado com sucesso!\n", vendedor.nome, vendedor.id);
    system("pause");
}

void editarVendedor() {
    int idBusca;
    int encontrado = 0;
    Vendedor vendedor;

    system("cls||clear");
    printf("\n--- Editar Vendedor ---\n");
    printf("Digite o ID do vendedor que deseja editar: ");

    
    scanf("%d", &idBusca);
    
    limparBuffer(); 

    FILE *arquivoOriginal = fopen("vendedores.txt", "r");
    FILE *arquivoTemp = fopen("vendedores_temp.txt", "w");

    if (arquivoOriginal == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        system("pause");
        return;
    }

   
    while (fscanf(arquivoOriginal, "%99[^;];%d;%f;%f\n", vendedor.nome, &vendedor.id, &vendedor.salario, &vendedor.comissao) == 4) {
        
        
        if (vendedor.id == idBusca) {
            encontrado = 1;
            system("cls||clear");
            printf("\n--- Vendedor Encontrado --- \n");
            printf("ID: %d\n", vendedor.id);
            printf("Nome Atual: %s\n", vendedor.nome);
            printf("--------------------------------------\n");
            printf("Insira os novos dados:\n\n");

            printf("Novo nome: ");
            
            fgets(vendedor.nome, 100, stdin);
            
            vendedor.nome[strcspn(vendedor.nome, "\n")] = 0;

            printf("Novo salario fixo: ");
           
            scanf("%f", &vendedor.salario);
            
            limparBuffer();

            printf("\n>> Vendedor atualizado com sucesso! <<\n");
            system("pause"); 
        }

        
        fprintf(arquivoTemp, "%s;%d;%.2f;%.2f\n", vendedor.nome, vendedor.id, vendedor.salario, vendedor.comissao);
    }

    fclose(arquivoOriginal);
    fclose(arquivoTemp);

    
    if (encontrado) {
        remove("vendedores.txt");
        rename("vendedores_temp.txt", "vendedores.txt");
    } else {
       
        remove("vendedores_temp.txt");
        system("cls||clear");
        printf("\nERRO: Vendedor com o ID '%d' nao foi encontrado.\n", idBusca);
        system("pause");
    }
}
     
 


void deletarVendedor() {
    int idParaDeletar;
    int encontrado = 0;
    Vendedor vendedor; 

    system("cls||clear");
    printf("Digite o ID do vendedor que deseja remover: ");
    scanf("%d", &idParaDeletar);
    limparBuffer(); 

    FILE *arquivoOriginal = fopen("vendedores.txt", "r");
    FILE *arquivoTemporario = fopen("temp.txt", "w");

    
    if (arquivoOriginal == NULL || arquivoTemporario == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        system("pause");
        return;
    }

    
    while (fscanf(arquivoOriginal, "%99[^;];%d;%f;%f\n", vendedor.nome, &vendedor.id, &vendedor.salario, &vendedor.comissao) == 4) {
        
        
        if (vendedor.id != idParaDeletar) {
            
            fprintf(arquivoTemporario, "%s;%d;%.2f;%.2f\n", vendedor.nome, vendedor.id, vendedor.salario, vendedor.comissao);
        } else {
            
            encontrado = 1;
        }
    }

   
    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    system("cls||clear");  

    if (encontrado) {
        
        remove("vendedores.txt");
        rename("temp.txt", "vendedores.txt");
        printf("Vendedor removido com sucesso!\n");
    } else {
        
        remove("temp.txt");
        printf("Vendedor com ID %d nao foi encontrado!\n", idParaDeletar);
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}

void consultarVendedor() {

    int idBusca;
    int encontrado = 0;
    Vendedor vendedor;

    system("cls||clear");
    printf("\n--- Consultar Vendedor ---\n");
    printf("Digite o ID do vendedor que deseja consultar: ");
    scanf("%d", &idBusca);
    limparBuffer();

    FILE *arquivo = fopen("vendedores.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Nao ha vendedores cadastrados.\n");
        system("pause");
        return;
    }

    while (fscanf(arquivo, "%99[^;];%d;%f;%f\n", vendedor.nome, &vendedor.id, &vendedor.salario, &vendedor.comissao) == 4) {
        if (vendedor.id == idBusca) {
            encontrado = 1;
            system("cls||clear");
            printf("--- Vendedor Encontrado ---\n\n");
            printf("ID: %d\n", vendedor.id);
            printf("Nome: %s\n", vendedor.nome);
            printf("Salario Fixo: R$ %.2f\n", vendedor.salario);
            printf("Comissao Acumulada: R$ %.2f\n\n", vendedor.comissao);
            break;
        }
    }

    fclose(arquivo);

    if(!encontrado) {
        system("cls||clear");
        printf("\nVendedor com o ID '%d' nao foi encontrado.\n\n", idBusca);
    }
    system("pause");

}

void menuVendedor() {

   int flag=1;
   int select;
    
    while(flag==1) {

        system("cls||clear");
        printf("\n--- Menu Vendedores ---\n\n");
        printf("[1] Cadastrar\n");
        printf("[2] Consultar\n");
        printf("[3] Editar\n");
        printf("[4] Deletar\n\n");
        printf("[0] Voltar ao Menu Principal\n\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d",&select);

        switch(select) {

            case 0: flag=0; return; 
            case 1: cadastrarVendedor(); break;
            case 2: consultarVendedor(); break;
            case 3: editarVendedor(); break;
            case 4: deletarVendedor(); break;
            default: flag=1; break;
        }
    }

}

#endif