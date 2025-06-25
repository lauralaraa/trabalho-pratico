#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<produtovenda.h>

typedef struct Venda {
    char codigovenda[10];
    Produtovenda produto;
    float valortotal;
}Venda;

Venda cadastrovenda() {

    int i,flag2,flag;
    while(flag){
    Venda venda;
    printf("\nInsira o nome do vendedor\n");
    fgets(venda.codigovenda,100,stdin);
    while(flag2){
    Produtovenda produtovenda=cadastroprodutovenda();
    i++;
    printf("\nDeseja cadastrar mais um produto na venda?\nSim=1\nNão=0\n");
    scanf("%d",&flag2);
    }
    printf("\nConfirmar o cadastro?\nSim=1\nNão=0\n");
    scanf("%d",&flag);
    }
}