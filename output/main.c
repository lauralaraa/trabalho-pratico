#include<stdio.h>
#include<stdlib.h>
#include"compradores.h"
#include"vendas.h"
#include"vendedores.h"
#include"endereco.h"
#include"produtos.h"

void Menu( void ) {

    system(" cls || clear ");

    int input;
    
    printf("\nMenu Principal\n\n");

    printf("[1] Produtos\n");
    printf("[2] Vendedores\n");
    printf("[3] Clientes\n");
    printf("[4] Vendas\n\n");
    printf("[0] Sair\n\n: ");

    scanf("%d", &input);

    switch ( input ) {

        case 0: break;

        case 1: MenuProdutos(); break;

        case 2: MenuVendedores(); break;

        case 3: MenuClientes(); break;

        case 4: MenuVendas(); break;

        default: MenuPrincipal(); break;
        
    }
    
}

int main()
{
    Menu();
}