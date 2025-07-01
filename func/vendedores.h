#ifndef VENDEDORES_H
#define VENDEDORES_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Vendedor {
    char nome[100];
    int codigo;
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
    while (fscanf(arquivo, "%49[^,],%d,%f,%f\n",&v.nome,&v.codigo,&v.salario,&v.comissao) == 4) {
        if (v.codigo > id) {
            id = v.codigo;
        }
    }
    fclose(arquivo);
    return id+1;
    
    main();

}

void buscarVendedor() {

}

void cadastrarVendedor() {

    int vendascom;
    Vendedor vendedor;
    getchar();
    system("cls||clear");
    printf("\nInsira o nome do vendedor\n");
    fgets(vendedor.nome,100,stdin);
    system("cls||clear");
    printf("\nInsira o salario fixo atual do vendedor\n");
    scanf("%f",&vendedor.salario);
    getchar();
    system("cls||clear");

    vendedor.comissao=(vendascom/100)*3;

       FILE *arquivo = fopen("vendedores.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%d;%f;%f\n", vendedor.nome, proximoIDvendedor(), vendedor.salario, vendedor.comissao);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

void editarVendedor() {
 
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
    printf("[4] Excluir\n\n");
    printf("[0] Voltar\n\n: ");
    
    scanf("%d",&select);

    switch(select) {

        case 0: main(); break;
        case 1: cadastrarVendedor(); break;
        case 2: consultarVendedor(); break;
        case 3: editarVendedor(); break;
        case 4: deletarVendedor(); break;
        default: menuVendedor(); break;

    }

}

#endif