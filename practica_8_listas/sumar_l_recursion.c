#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

struct lista{
    int num;
    struct lista *sig;
};

void insertar(struct lista **p, int x);
int sumar_recursion(struct lista *p);

int main()
{
    
    struct lista *l = NULL;
    insertar(&l, 50);
    insertar(&l, 75);
    insertar(&l, 4);
    insertar(&l, 110);
    insertar(&l, 20);
    printf("%d", sumar_recursion(l));
    return 0;
}

void insertar(struct lista **p, int x){
    struct lista *nuevo = malloc(sizeof(struct lista));
    struct lista *point = *p;

     nuevo -> num = x;
     nuevo -> sig = *p;
     *p = nuevo;
}

int sumar_recursion(struct lista *p){
    
    if(p == NULL){
        return 0;
    }
    else{
        return sumar_recursion(p->sig) + p->num;
    }
}

