#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../func/produtos.h"
#include "../func/vendedores.h"
#include "../func/compradores.h"
#include "../func/vendas.h"
#include "../func/endereco.h"
#include "../func/notas.h"

void menuProduto();
void menuVendedor();
void menuComprador();
void menuVenda();

    int main() {

    int select;
    int flag=1;
    
    while (flag == 1){
    system("cls||clear");
    printf("\nMenu Principal\n\n");

    printf("[1] Produtos\n");
    printf("[2] Vendedores\n");
    printf("[3] Compradores\n");
    printf("[4] Vendas\n\n");
    printf("[0] Sair\n\n:");
    printf("Escolha uma opcao:\n");

    scanf("%d",&select);

    switch (select) {

        case 0: 
        flag = 0;
        break;
        case 1: menuProduto(); break;
        case 2: menuVendedor(); break;
        case 3: menuComprador(); break;
        case 4: menuVenda(); break;

    default: printf("\nOpcao invalida! Pressione Enter para tentar novamente.");
    while(getchar() != '\n');
    getchar();
    break;
        
}

}
    
}


