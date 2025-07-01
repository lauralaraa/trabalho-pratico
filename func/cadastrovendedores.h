#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Vendedor {
    char nome[100];
    int numero;
    float salario;
    float comissao;
}Vendedor;

Vendedor cadastrovendedor() {

    int vendascom,flag;
    Vendedor vendedor;
    printf("\nInsira o nome do vendedor\n");
    fgets(vendedor.nome,100,stdin);
    getchar();
    printf("\nInsira o numero do vendedor\n");
    scanf("%d",&vendedor.numero);
    printf("\nInsira o salário fixo atual do vendedor\n");
    scanf("%.2f",&vendedor.salario);
    vendascom=vendascom;
    vendedor.comissao=(vendascom/100)*3;
    return vendedor;
}