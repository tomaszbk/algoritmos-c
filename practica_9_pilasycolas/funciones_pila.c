#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

struct pila{
    int num;
    struct pila *sig;
};


void desapilar(struct pila **l);
void apilar(struct pila **l);
void imprimir(struct pila **l); //y esta falta

int main()
{
    struct pila *pilas;
    

    return 0;
}

void desapilar(struct pila **l){
    struct pila *actual = *l;
    // struct lista *aux= *l;
    if(actual==NULL){
        printf("no se puede desapilar lista vacia");
        return;
    }
    *l = actual->sig;
    free(actual);
}

void apilar(struct pila **l){
    struct pila *nuevo = malloc(sizeof(struct pila));
    printf("\ningrese num");
    scanf("%d", nuevo ->num);
    nuevo -> sig = *l;
    *l = nuevo;
}