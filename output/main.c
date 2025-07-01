#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../func/produtos.h"
#include "../func/vendedores.h"
#include "../func/compradores.h"
#include "../func/vendas.h"
#include "../func/endereco.h"
#include "../func/notas.h"

    int main() {

    system("cls||clear");

    int select;
    
    printf("\nMenu Principal\n\n");

    printf("[1] Produtos\n");
    printf("[2] Vendedores\n");
    printf("[3] Compradores\n");
    printf("[4] Vendas\n\n");
    printf("[0] Sair\n\n: ");

    scanf("%d",&select);

    switch (select) {

        case 0: break;

        case 1: menuProduto(); break;

        case 2: menuVendedor(); break;

        case 3: menuComprador(); break;

        case 4: menuVenda(); break;

        default: main(); break;
        
    }
    
}
