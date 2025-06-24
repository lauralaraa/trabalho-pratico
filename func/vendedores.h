#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Vendedor {
    char nome[100];
    int numero;
    float salario;
    float comissao;
}Vendedor;

int main() {

    int i,vendascom,flag;
    while(flag){
    Vendedor vendedor[i];
    printf("\nInsira o nome do vendedor\n");
    fgets(vendedor[i].nome,100,stdin);
    printf("\nInsira o numero do vendedor\n");
    scanf("%d",&vendedor[i].numero);
    printf("\nInsira o salário fixo atual do vendedor\n");
    scanf("%.2f",&vendedor[i].salario);
    printf("\nInsira as vendas a serem comicionadas\n");
    scanf("%d",&vendascom);
    vendedor[i].comissao=(vendascom/100)*3;
    i++;
    printf("\nDeseja cadastrar mais um vendedor?\nSim=1\nNão=0\n");
    scanf("%d",&flag);
    }
}