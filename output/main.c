#include<stdio.h>
#include<stdlib.h>
#include"cadastrocomprador.h"
#include"cadastrovendas.h"
#include"cadastroprodutos.h"
#include"cadastrovendedores.h"
#include"salvarvenda.h"
#include"salvarproduto.h"
#include"salvarcomprador.h"
#include"salvarvendedor.h"

int main()
{
    int verificador1,verificador2,verificador3;
    printf("Qual operação deseja realizar?\nCadastro=0\nExibição=1\n");
    scanf("%d",&verificador1);
    if(verificador1){
    printf("\nOque deseja cadastrar?\nComprador=1\nVendedor=2\nProduto=3\nVenda=4\n");
    scanf("%d",&verificador2);
    if(verificador2==1){
        Comprador vendedor=cadastrocomprador();
        salvarComprador();
    }else if(verificador2==2){
        Vendedor vendedor=cadastrovendedor();
        salvarVendedor();
    }else if(verificador2==3){
        Produto vendedor=cadastroproduto();
        salvarProduto();
    }else if(verificador2==4){
        Venda vendedor=cadastrovenda();
        salvarVenda();
    }
    }
    
}