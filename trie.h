#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alfabeto 26

typedef struct no{

    struct no* filhos[alfabeto];
    int tipo = 0;   // indica se é estado de aceitação

}no;

no* cria_no();

int encontra_indice(char c);

void insere(no* raiz, char* str);

int busca(no* raiz, char* str); //a raiz e a string que busca