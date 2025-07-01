#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct Produto {
    char nome[100];
    char codigo[20];
    int estoque;
    float preco;
}Produto;

Produto cadastroproduto() {
    Produto produto;
    printf("\nInsira o nome do produto\n");
    fgets(produto.nome,100,stdin);
    getchar();
    printf("\nInsira o codigo do produto\n");
    fgets(produto.codigo,20,stdin);
    getchar();
    printf("\nInira a quantidade em estoque\n");
    scanf("%d",&produto.estoque);
    printf("\nInsira o preço unitário\n");
    scanf("%.2f",&produto.preco);
    
}

void salvarProduto(Produto p) {
    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%d;%.2f\n", p.nome, p.codigo, p.estoque, p.preco);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

#endif