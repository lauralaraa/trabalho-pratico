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
    Produto produto;
    printf("\nInsira o nome do produto\n");
    fgets(produto.nome,100,stdin);
    getchar();
    printf("\nInsira o codigo do produto\n");
    fgets(produto.codigo,20,stdin);
    getchar();
    printf("\nInira a quantidade em estoque\n");
    scanf("%d",&produto.estoque);
    printf("\nInsira o preço unitário\n");
    scanf("%.2f",&produto.preco);
    
}