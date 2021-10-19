/* Una inmobiliaria tiene una lista de todos los departamentos que tiene en venta. De cada 
// departamento se conoce:
 -su ubicación
 -cantidad de dormitorios
 -piso 
 -cochera si/no,
 -antigüedad 
 -precio 
 -valor de las expensas. 
 Informar cuál es el departamento más caro
 -generar un informe con el total de departamentos según cantidad de dormitorios del 
// mismo, ordenados de mayor a menor por dicho total*/

#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

struct departamento{
    char ubicacion[20];
    int cant_dormitorios;
    int piso;
    int cochera; //0 no, 1 si
    int antiguedad;
    int precio;
    int expensas;
};

struct lista{
    struct departamento dpto;
    struct lista *sig;
};
void insertar_ordenado(struct lista **p);

int main()
{
    int z=1;
    struct lista *p = NULL;
    while(z > 0){
        printf("\ndesea agregar dpto(1), imprimir(2) o finalizar(0)?\n");
        scanf("%d",&z);
        switch
    }
    return 0;
}


void insertar_ordenado(struct lista **p){       //ordenar por cant_dormitorios de mayor a menor
    struct lista *nuevo = malloc(sizeof(struct lista));
    struct lista *pointer = *p;
    struct lista *anterior;
    printf("\n ubicacion: ");
    scanf("%s", nuevo -> dpto.ubicacion);
    printf("\n cant dormitorios: ");
    scanf("%d", &nuevo -> dpto.cant_dormitorios);
    printf("\n piso: ");
    scanf("%d", &nuevo -> dpto.piso);
    printf("\n cochera 1/0: ");
    scanf("%d", &nuevo -> dpto.cochera);
    printf("\n antiguedad: ");
    scanf("%d", &nuevo -> dpto.antiguedad);
    printf("\n precio: ");
    scanf("%d", &nuevo -> dpto.precio);
    printf("\n valor expensas: ");
    scanf("%d", &nuevo -> dpto.expensas);

    if(*p == NULL){
        *p = nuevo;
        nuevo ->sig = NULL;
    }
    else{

        while(nuevo -> dpto.cant_dormitorios < pointer -> dpto.cant_dormitorios){
            anterior = nuevo;
            pointer = pointer -> sig;
        }

        anterior -> sig = nuevo;
        nuevo -> sig = pointer;
    }
}

void informe(struct lista **p){
    struct lista *pointer = *p;
    while(pointer != NULL){
        printf("\n ubicacion %s, ", pointer-> dpto.ubicacion);
        printf("$%d,", pointer-> dpto.precio);
        printf("cant dormi es %d", pointer-> dpto.cant_dormitorios);
        pointer = pointer -> sig;
    }

}