#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Produto {
    char nome[100];
    char codigo[20];
    int estoque;
    float preco;
}Produto;

Produto cadastroproduto() {
    Produto produto[i];
    printf("\nInsira o nome do produto\n");
    fgets(produto[i].nome,100,stdin);
    printf("\nInsira o codigo do produto\n");
    fgets(produto[i].codigo,20,stdin);
    printf("\nInira a quantidade em estoque\n");
    scanf("%d",&produto[i].estoque);
    printf("\nInsira o preço unitário\n");
    scanf("%.2f",&produto[i].preco);
    
}