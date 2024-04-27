#include <stdio.h>
#include <stdlib.h>

struct Pessoa
{
    int senha;
    struct Pessoa *prox;    
};

typedef struct Pessoa pessoa;

pessoa *fila;

void add(int senha){
    pessoa *p = (pessoa*) malloc(sizeof(pessoa));
    p->senha = senha;
    p->prox = NULL;

    if (fila == NULL) fila = p;
    else {
        pessoa *aux = fila;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = p;
    }
}


void remover(){

    if (fila == NULL) printf("fila vazia\n");
    else {
        fila = fila->prox;
    }  
}

void imprimir(pessoa *p){
    
    if(p != NULL)
    {
        printf("\nSenha da pessoa: %d", p->senha);
        imprimir(p->prox);
    }
}

int main(){

    add(5);
    add(8);
    add(10);
    add(25);

    pessoa *aux = fila;
    imprimir(aux);

    remover();
    remover();

    aux = fila;
    imprimir(aux);


    
    return 0;
}