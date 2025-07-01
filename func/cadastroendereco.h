#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Endereco {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char cep[20];
}Endereco;

Endereco cadastroendereco() {

     int flag;
    while(flag){
    Endereco Endereco;
    printf("\nInsira o nome da sua rua:\n");
    fgets(Endereco.rua,50,stdin);
    getchar();
    printf("\nInsira o nome do seu bairro:\n");
    fgets(Endereco.bairro,50,stdin);
    getchar();
    printf("\nInsira a cidade em que você mora:\n");
    fgets(Endereco.cidade,50,stdin);
    getchar();
    printf("\nInsira o CEP\n");
    fgets(Endereco.cep,50,stdin);
    getchar();
    
    printf("\nAs informações estão corretas?\nSim=1\nNão=0\n");
    scanf("%d",&flag);

    return Endereco;
    }

}