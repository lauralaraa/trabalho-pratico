#ifndef COMPRADORES_H
#define COMPRADORES_H
#include"endereco.h"

typedef struct Comprador {
    char nome[100];
    char cpf[15];
    char email[50];
    Endereco endereco;
}Comprador;

void proximoIDcomprador() {

}

void buscarComprador() {

}

Comprador cadastroComprador () {

    Comprador comprador;

    printf("\nInsira o nome do comprador: ");
    fgets(comprador.nome,100,stdin);
    getchar();
    printf("\nInsira o codigo do produto: ");
    fgets(comprador.cpf,15,stdin);
    getchar();
    printf("\nInsira o email do comprador: ");
    fgets(comprador.cpf,15,stdin);
    getchar();
    comprador.endereco=cadastroEndereco();

    FILE *arquivo = fopen("compradores.txt", "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s;%s;%s;%s,%s,%s\n", comprador.nome, comprador.cpf, comprador.email, comprador.endereco.bairro, comprador.endereco.rua, comprador.endereco.cidade, comprador.endereco.cep);
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
    
}

void editarComprador() {

}

void deletarComprador() {
    
}

void consultarCOmprador() {

}

void menuComprador() {

    system("cls||clear");

    int select;

    printf("\nCompradores\n\n");

    printf("[1] Cadastrar\n");
    printf("[2] Consultar\n");
    printf("[3] Editar\n");
    printf("[4] Excluir\n\n");
    printf("[0] Voltar\n\n: ");
    
    scanf("%d",&select);

    switch(select) {

        case 0: Menu(); break;

        case 1: cadastrarComprador(1); break;
        
        case 2: consultarComprador(); break;

        case 3: editarComprador(); break;

        case 4: excluirComprador(); break;

        default: menuComprador(); break;

    }
}

#endif