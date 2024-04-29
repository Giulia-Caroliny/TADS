#include <stdio.h>
#include <stdlib.h>

struct Prato
{
    char cor;
    struct Prato *prox;    
};

typedef struct Prato prato;

prato *pilha;

void add(char cor){
    prato *p = (prato*) malloc(sizeof(prato));
    p->cor = cor;
    p->prox = pilha;
    pilha = p;
}


void remover(){

    if (pilha == NULL) printf("pilha vazia\n");
    else {
        pilha = pilha->prox;
    }  
}

void imprimir(prato *p){
    
    if(p != NULL)
    {
        printf("\nCor da prato: %c", p->cor);
        imprimir(p->prox);
    }
}

int main(){
    add('a');
    add('b');
    add('c');

    prato *aux = pilha;
    imprimir(aux);

    remover();

    aux = pilha;
    imprimir(aux);

    remover();

    aux = pilha;
    imprimir(aux);

    
    return 0;
}