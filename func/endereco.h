#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Endereco {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char cep[20];
}Endereco;

Endereco cadastro_endereco(int i) {

     int i,flag;
    while(flag){
    Endereco Endereco[i];
    printf("\nInsira o nome da sua rua:\n");
    fgets(Endereco[i].rua,50,stdin);
    printf("\nInsira o nome do seu bairro:\n");
    fgets(Endereco[i].bairro,50,stdin);
    printf("\nInsira a cidade em que você mora:\n");
    fgets(Endereco[i].cidade,50,stdin);
    printf("\nInsira o CEP\n");
    fgets(Endereco[i].cep,50,stdin);
    
    printf("\nAs informações estão corretas?\nSim=1\nNão=0\n");
    scanf("%d",&flag);
    
    }

}