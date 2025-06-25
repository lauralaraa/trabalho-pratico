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

Produtovenda cadastroprodutovenda(int i) {
    Produtovenda produtovenda[i];
    printf("\nInsira o nome do produto\n");
    fgets(produtovenda[i].nome,100,stdin);
    printf("\nInsira o codigo do produto\n");
    fgets(produtovenda[i].codigo,100,stdin);
    printf("\nInsira o quantidade vendida\n");
    scanf("%d",&produtovenda[i].quantidade);
    printf("\nInsira o preço unitário\n");
    scanf("%.2f",&produtovenda[i].precounidade);
    produtovenda[i].precototal=produtovenda[i].quantidade*produtovenda[i].precounidade;
    return produtovenda[i];
}