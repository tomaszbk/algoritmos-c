/* Se lee una secuencia de números que se almacena en una lista encadenada. Además se lee otro 
número por teclado. Se desea:
a. Determinar cuántas veces aparece ese número en la lista
b. Eliminarlo si aparece una sola vez, si no existe imprimir un mensaje indicando este 
hecho */
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
struct lista{
    int num;
    struct lista *sig;
};

struct lista *plista = NULL;
void agregar_inicio(struct lista **l);
void imprimir_lista(struct lista **l);
void busqueda(struct lista **l,int num);
void eliminar(struct lista **l,int num);

int main()
{
    int z;
    agregar_inicio(&plista);
    agregar_inicio(&plista);
    agregar_inicio(&plista);
    agregar_inicio(&plista);
    imprimir_lista(&plista);
    printf("\ningrese su num ");
    scanf("%d", &z);
    busqueda(&plista,z);
    imprimir_lista(&plista);
    return 0;
}

void agregar_inicio(struct lista **l){
    struct lista *nuevo=malloc(sizeof(struct lista));
    nuevo ->sig = *l;
    printf("\ninserte num: ");
     scanf("%d",&nuevo -> num); 
    *l = nuevo;
}

void imprimir_lista(struct lista **l){
    struct lista *point = *l;
    while(point != NULL){
        printf("\n%d", point->num);
        point = point->sig;
    }
}

void busqueda(struct lista **l,int num){
    struct lista *point = *l;
    int aparece =0;
    while(point != NULL){
        if(point->num ==num){
            aparece++;
            struct lista *index = point;
        }
        point = point->sig;
    }
    if(aparece==0){
        printf("\nel num no aparece");
    }
    else if(aparece >1){
        printf("\nel num aparece %d veces!", aparece);
    }
    else{
        printf("\nel num aparece 1 vez y va a ser eliminado");
        eliminar(l,num);

    }
}

void eliminar(struct lista **l,int num){
    struct lista *point = *l;
    point = point -> sig;
    struct lista *anterior = *l;

    if(point == NULL){
        free(anterior);
        *l = NULL;
    }
    while(1){
        if(point->num==num){
            anterior ->sig = point ->sig;
            free(point);
            return;
        }
        point = point->sig;
        anterior = anterior->sig;
    }
}