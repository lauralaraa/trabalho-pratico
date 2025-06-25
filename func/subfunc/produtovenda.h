#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Produtovenda {
    char nome[100];
    char codigo[20];
    int quantidade;
    float precounidade;
    float precototal;
}Produtovenda;

Produtovenda cadastroprodutovenda() {
    Produtovenda produtovenda;
    printf("\nInsira o nome do produto\n");
    fgets(produtovenda.nome,100,stdin);
    printf("\nInsira o codigo do produto\n");
    fgets(produtovenda.codigo,100,stdin);
    printf("\nInsira o quantidade vendida\n");
    scanf("%d",&produtovenda.quantidade);
    printf("\nInsira o preço unitário\n");
    scanf("%.2f",&produtovenda.precounidade);
    produtovenda.precototal=produtovenda.quantidade*produtovenda.precounidade;
    return produtovenda;
}