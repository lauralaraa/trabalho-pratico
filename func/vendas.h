#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<produtovenda.h>

typedef struct Venda {
    char codigovenda[10];
    float valortotal;
}Venda;

Venda cadastrovenda() {

    int i,i2,flag2,flag;
    while(flag){
    Venda venda[i];
    printf("\nInsira o nome do vendedor\n");
    fgets(venda[i].codigovenda,100,stdin);
    while(flag2){
    Produtovenda produtovenda=cadastroprodutovenda(i2);
    i2++;
    printf("\nDeseja cadastrar mais um produto na venda?\nSim=1\nNão=0\n");
    scanf("%d",&flag2);
    }
    i++;
    printf("\nDeseja cadastrar mais uma venda?\nSim=1\nNão=0\n");
    scanf("%d",&flag);
    }
}