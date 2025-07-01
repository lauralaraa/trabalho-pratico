#ifndef VENDAS_H
#define VENDAS_H

typedef struct Venda {
    char codigovenda[10];
    char vendedor[10];
    
    float valortotal;
}Venda;

Venda cadastrovenda() {

    int i=0,flag=1,flag2=1;
    while(flag){
    Venda venda;
    printf("\nInsira o codigo da venda\n");
    fgets(venda.codigovenda,10,stdin);
    getchar();
    printf("\nInsira o codigo do vendedor\n");
    fgets(venda.vendedor,10,stdin);
    getchar();
    while(flag2){
    venda.produtodavenda[i]=cadastroprodutovenda();
    i++;
    printf("\nDeseja cadastrar mais um produto na venda?\nSim=1\nNão=0\n");
    scanf("%d",&flag2);
    }
    printf("\nConfirmar o cadastro?\nSim=1\nNão=0\n");
    scanf("%d",&flag);

    if (flag==1){
        salvarvenda(venda);
    }
    }

    
}

void salvarProduto(Venda v) {
    FILE *arquivo = fopen("vendas.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s;%.2f;%.2f\n", v.codigovenda, v.produtodavenda->codigo, v.produtodavenda->nome, v.produtodavenda->precounidade, v.produtodavenda->precototal);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

#endif