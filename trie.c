#include "funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <trie.h>

no* cria_no(){
    int i = 0;
    no* p = NULL;
    p = (no*)malloc(sizeof(no*));
    if(!p){
        printf("ERRO \n");
    }else{
        p->tipo = 0;
        for(i = 0; i < alfabeto; i++){
            p->filhos[i] = NULL;
        }
    }

    return (p);
}

int encontra_indice(char c){
    int chave =  (int)c - (int)'a';
    return chave;
}

void insere(no* raiz, char* str){
    int nivel;
    int indice;
    int tam = strlen(str);

    no* p = raiz;

    for(nivel = 0; nivel < tam; nivel++){
        indice = encontra_indice(str[nivel]);
        if(p->filhos[indice] == NULL){
            p->filhos[indice] = cria_no(); 
        }
        p = p->filhos[indice];
    }
    p->tipo = 1;
}

int busca(no* raiz, char* str){

    int nivel;
    int tam = strlen(str);
    int indice;
    no* p = raiz;

    for(nivel = 0; nivel < tam; nivel++){
        indice = encontra_indice(str);
        if(p->filhos[indice] == NULL){
            return 0;   // não achou
        }else{
            p = p->filhos[indice];
        }

    }

    if(p->tipo == 1){
        return 1;   // achou
    }

}

void destroyTrie(struct no* raiz) {
    int i;
    if (!raiz) {
        return;
    }
    for (i = 0; i < alfabeto; i++) {
        destroyTrie(raiz->filhos[i]);
    }
    free(raiz);
}
