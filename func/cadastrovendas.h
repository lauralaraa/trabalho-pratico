#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cadastroprodutovenda.h"

typedef struct Venda {
    char codigovenda[10];
    char vendedor[10];
    Produtovenda produtodavenda[10000];
    float valortotal;
}Venda;

Venda cadastrovenda() {

    int i=1,flag,flag2;
    while(flag){
    Venda venda;
    printf("\nInsira o codigo da venda\n");
    fgets(venda.codigovenda,10,stdin);
    printf("\nInsira o codigo da venda\n");
    fgets(venda.vendedor,10,stdin);
    while(flag2){
    venda.produtodavenda[i]=cadastroprodutovenda();
    i++;
    printf("\nDeseja cadastrar mais um produto na venda?\nSim=1\nNão=0\n");
    scanf("%d",&flag2);
    }
    printf("\nConfirmar o cadastro?\nSim=1\nNão=0\n");
    scanf("%d",&flag);
    }
}