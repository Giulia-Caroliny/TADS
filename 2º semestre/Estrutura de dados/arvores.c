#include <stdio.h>
#include <stdlib.h>

struct no
{
    int num;
    struct no *dir;
    struct no *esq;
};

typedef struct no no;

no* criar (int valor){

    no *n = malloc(sizeof(no));
    n->num = valor;
    n->dir = NULL;
    n->esq = NULL;

    return n;
}

void add (no *n, int valor){
    if (valor < n->num)
    {
        if(n->esq == NULL) n->esq = criar(valor);
        else add(n->esq, valor);
    } else {
        if(n->dir == NULL) n->dir = criar(valor);
        else add(n->dir, valor);
    }
}

void imprimir (no *n){
    if (n == NULL) return;
    imprimir(n->esq);
    printf("%d\n", n->num);
    imprimir(n->dir);
}

void remover (no *n, int valor){
    no *filho = n;
    no *pai;

    do{
        pai = filho;
        if(valor < filho->num) filho = filho->esq;
        else if(valor > filho->num) filho = filho->dir;
    } while (filho != NULL && filho->num != valor);

    if (filho != NULL)
    {
        if(filho->esq == NULL && filho->dir == NULL) {
            if(pai->esq == filho) pai->esq = NULL;
            if(pai->dir == filho) pai->dir = NULL;
        }

        if (filho->esq != NULL && filho->dir == NULL)
        {
            if(pai->esq == filho) pai->esq = filho->esq;
            if(pai->dir == filho) pai->dir = filho->esq;
        }

        if (filho->dir != NULL && filho->esq == NULL)
        {
            if(pai->esq == filho) pai->esq = filho->dir;
            if(pai->dir == filho) pai->dir = filho->dir;
        }

        if (filho->esq != NULL && filho->dir != NULL)
        {
            if (filho->esq->dir == NULL) {
                filho->num = filho->esq->num;
                filho->esq = NULL;
            }
            else {
                no *p = filho->esq;
                no *aux = p;

                while (p->dir != NULL)
                {
                    aux = p;
                    p = p->dir;
                }

                aux->dir = NULL;
                filho->num = p->num;
            }
        }
    }
}

int main(){

    no *root = criar(5);

    add(root, 9);
    add(root, 2);
    add(root, 3);
    add(root, 17);
    add(root, -5);

    imprimir(root);

    puts("");

    remover(root, 9);
    remover(root, 2);
    remover(root, 3);
    remover(root, 17);
    remover(root, 5);
       
    imprimir(root);
    
    return 0;
}