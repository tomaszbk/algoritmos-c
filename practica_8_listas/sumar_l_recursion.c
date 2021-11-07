#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

struct lista{
    int num;
    struct lista *sig;
};

void insertar(struct lista **p, int x);
void sumar_recursion(struct lista **p, int *resultado);

int main()
{
    int resultado=0;
    struct lista *l = NULL;
    insertar(&l, 50);
    insertar(&l, 75);
    insertar(&l, 4);
    insertar(&l, 110);
    insertar(&l, 20);
    return 0;
}

void insertar(struct lista **p, int x){
    struct lista *nuevo = malloc(sizeof(struct lista));
    struct lista *point = *p;

     nuevo -> num = x;
     nuevo -> sig = *p;
     *p = nuevo;
}

void sumar_recursion(struct lista **p, int *resultado){
    struct lista *pointer = *p;
    if(pointer -> sig == NULL){
        return;
    }
    else{
        *resultado = sumar_recursion(&pointer->sig,resultado) + pointer->num;
    }
}

