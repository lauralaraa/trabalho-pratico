#ifndef LIMPARBUFFER_H
#define LIMPARBUFFER_H 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#endif