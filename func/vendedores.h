#ifndef VENDEDORES_H
#define VENDEDORES_H

typedef struct Vendedor {
    char nome[100];
    int numero;
    float salario;
    float comissao;
}Vendedor;

Vendedor cadastrovendedor() {

    int vendascom,flag;
    Vendedor vendedor;
    printf("\nInsira o nome do vendedor\n");
    fgets(vendedor.nome,100,stdin);
    getchar();
    printf("\nInsira o numero do vendedor\n");
    scanf("%d",&vendedor.numero);
    printf("\nInsira o salário fixo atual do vendedor\n");
    scanf("%.2f",&vendedor.salario);
    vendascom=vendascom;
    vendedor.comissao=(vendascom/100)*3;
    return vendedor;
}

void salvarVendedor(Vendedor v) {
    FILE *arquivo = fopen("vendedores.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%d;%d;%.2f\n", v.nome, v.numero, v.salario, v.comissao);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

#endif