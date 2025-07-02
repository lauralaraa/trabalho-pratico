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
    int select;
    while (1) { 
        system("cls||clear");
        printf("\n--- SISTEMA DE E-COMMERCE ---\n\n");
        printf("[1] Modulo de Produtos\n");
        printf("[2] Modulo de Vendedores\n");
        printf("[3] Modulo de Compradores\n");
        printf("[4] Realizar Venda\n");
        printf("[5] Emitir Nota Fiscal\n\n");
        printf("[0] Sair do Programa\n\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &select) != 1) {
            select = -1; 
        }
        
        switch (select) {
            case 0:
                printf("\nSaindo do sistema... Ate mais!\n");
                return 0; 
            case 1: menuProduto(); break;
            case 2: menuVendedor(); break;
            case 3: menuComprador(); break;
            case 4: cadastrarVenda(); break;
            case 5: emitirNotaFiscal(); break;
            default:
                printf("\nOpcao invalida! Pressione Enter para tentar novamente.");
                limparBuffer();
                getchar();
                break;
        }
    }
    return 0;
}

