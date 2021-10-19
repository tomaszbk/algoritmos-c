#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
struct examen{
    int legajo;
    int nota;
};

struct lista{
    struct examen dato;
    struct lista *sig;
};

void agregar_inicio(struct lista **l);

void imprimir_elementos(struct lista **l);
void insertar_ordenado(struct lista **l, struct examen xdxd, int index);

int main()
{
    struct lista *l =   NULL;
    // struct lista *nuevo=malloc(sizeof(struct lista));
    struct examen al1;
    al1.legajo=1343;
    al1.nota=10;

    imprimir_elementos(&l);

    agregar_inicio(&l);
    agregar_inicio(&l);
    agregar_final(&l,al1);
    imprimir_elementos(&l);

    int z = 1;
    // insertar_ordenado(&l, al1, z);
    // printf("\n\n");
    // imprimir_elementos(&l);
    return 0;
}

void agregar_inicio(struct lista **l){
    struct lista *nuevo=malloc(sizeof(struct lista));
     printf("\ninserte legajo: ");
     scanf("%d",&nuevo -> dato.legajo); 
     printf("\ninserte nota: ");
     scanf("%d",&nuevo -> dato.nota); 
    nuevo -> sig = *l;
    *l = nuevo;
}



void imprimir_elementos(struct lista **l){
    struct lista *point = *l;
    if(point == NULL){
        printf("la lista esta vacia");
        return;
    }
    while(point != NULL){
        printf("\n%d",point-> dato.legajo);
        printf("\n%d",point-> dato.nota);
        point = point -> sig;
    }
    return;
}

void insertar_ordenado(struct lista **l, struct examen xdxd, int index){
    struct lista *nuevo=malloc(sizeof(struct lista));
    struct lista *point = *l;
    nuevo -> dato = xdxd;
    int cont = 0;
   
    while(cont < index -1 ){
        if(point == NULL){
            printf("lista sin elementos");
            return;
        }
        point = point -> sig;
        cont += 1;
    }
    nuevo -> sig = point -> sig;
    point -> sig = nuevo; //ojo aca
    return;
}