//LISTA DOBLE (IDA Y VUELTA)
#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

struct listadoble
{
    int legajo;
    int nota;
    struct listadoble *ant;
    struct listadoble *sig;
};

void insertar_inicio(struct listadoble **l, int leg,int nota);
void insertar_final(struct listadoble **l, int leg,int nota);
void imprimir_lista(struct listadoble **l);
void imprimir_especial(struct listadoble **l);

int main()
{
    struct listadoble *l = NULL;
    l->sig == NULL;
    l->ant == NULL;
    insertar_inicio(&l, 5675, 9);
    insertar_inicio(&l, 33565, 4);
    insertar_inicio(&l, 264455, 6);
    insertar_inicio(&l, 95885, 1);
    insertar_final(&l, 958, 2);
    insertar_final(&l, 4564, 10);
    insertar_final(&l, 27284, 8);
    imprimir_lista(&l);
    imprimir_especial(&l);

    return 0;
}

void insertar_inicio(struct listadoble **l, int leg,int nota){
    struct listadoble *nuevo = malloc(sizeof(struct listadoble));
    struct listadoble *point = *l;    
   
    nuevo->legajo = leg;
    nuevo->nota = nota;

    if(point != NULL){
        point -> ant = nuevo;
    }
    nuevo ->sig = *l;
    *l = nuevo;
}

void insertar_final(struct listadoble **l, int leg,int nota){
    struct listadoble *nuevo = malloc(sizeof(struct listadoble));
    struct listadoble *point = *l;
    // struct listadoble *anterior = *l;

    if (*l == NULL)
    {
       insertar_inicio(l,leg,nota);
       return;
    }

    while(point ->sig != NULL){
        point = point -> sig;
    }

    nuevo->legajo = leg;
    nuevo->nota = nota;

    nuevo ->sig = NULL;
    nuevo -> ant = point; //!!
    point -> sig = nuevo;
}

void imprimir_lista(struct listadoble **l){
    struct listadoble *point = *l;

    while(point != NULL){ 
        printf("\nlegajo %d, nota %d", point->legajo, point->nota);
        point = point->sig;
    }
    printf("\n\n\n");
}

void imprimir_especial(struct listadoble **l){
    //imprimir index 5 y dsp 3
    struct listadoble *point = *l;
    int index = 0;
    while(index < 5){
        point = point ->sig;
        index++;
    }
    printf("\nlegajo %d, nota %d", point->legajo, point->nota);
    // ahora index 3
    while(index >3){
        point = point ->ant;
        index--;
    }
    printf("\nlegajo %d, nota %d", point->legajo, point->nota);
}