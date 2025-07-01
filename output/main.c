#include<stdio.h>
#include<stdlib.h>
#include"compradores.h"
#include"vendas.h"
#include"vendedores.h"
#include"endereco.h"
#include"produtos.h"


int main()
{
    int verificador1,verificador2,verificador3;
    printf("Qual operação deseja realizar?\nCadastro=0\nExibição=1\n");
    scanf("%d",&verificador1);
    if(verificador1){
    printf("\nOque deseja cadastrar?\nComprador=1\nVendedor=2\nProduto=3\nVenda=4\n");
    scanf("%d",&verificador2);
    if(verificador2==1){
        cadastrocomprador();
        salvarComprador();
    }else if(verificador2==2){
        cadastrovendedor();
        salvarVendedor();
    }else if(verificador2==3){
        cadastroproduto();
        salvarProduto();
    }else if(verificador2==4){
        cadastrovenda();
        salvarVenda();
    }
    }
    
}