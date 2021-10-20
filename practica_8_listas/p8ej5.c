/* Un vivero tiene información de las plantas que en él se venden almacenada en una lista: 
código de planta
nombre planta
precio
stock
identificador es de interior/exterior
es un árbol, arbusto o flor. 

Se desea:
a. Generar e imprimir otra lista con los nombres y precios de las plantas que son 
arbustos de exterior.
b. Calcular el porcentaje de plantas de exterior y de interior que vende el vivero
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct plantas{
    char nombre[20];
    int precio;
    int stock;
    int interior; //1 si, 0 es exterior
    int tipo; // 0 arbol, 1 arbusto, 2 flor
};

struct arbustos_exterior{
    char nombre[20];
    int precio;
};

struct listab{
    struct arbustos_exterior dato;
    struct listab *sig;
};

struct lista{
    struct plantas planta;
    struct lista *sig;
};

void insertar(struct lista **p);
void generar_lista(struct lista **p, struct listab **a);
void porcentaje(struct lista **p, float *porcentaje_interior, float *interior, float *exterior);
void insertarb(struct listab **p, char nombre[20], int precio);
void imprimir_lista(struct listab **p);


int main()
{
    int z=1;
    float porcentaje_interior=0;
    float porcentaje_exterior=0;
    float interior;
    float exterior;
    struct lista *p = NULL;
    struct listab *arbusto = NULL;
    while(z > 0){
        printf("\ndesea agregar planta(1), generar lista e imprimir(2) o porcentaje y finalizar(0)?\n");
        scanf("%d",&z);
        switch (z){
                case 0:
                    porcentaje(&p, &porcentaje_interior, &interior, &exterior);
                    porcentaje_exterior = 1 - porcentaje_interior;
                    printf("por interior %f, por exterior %f", porcentaje_interior, porcentaje_exterior);
                    printf("\nmuchas gracias saludos");
                    break;
                case 1:
                    insertar(&p);
                    break;
                case 2:
                    z = 2;
                    generar_lista(&p, &arbusto);
                    imprimir_lista(&arbusto);
                    break;
                }
    }
    return 0;
}

void insertar(struct lista **p){
    struct lista *nuevo = malloc(sizeof(struct lista));
    struct lista *point = *p;    
    printf("\ningrese  nombre planta: ");
    scanf("%s", nuevo->planta.nombre);
    printf("\ningrese  precio: ");
    scanf("%d", &nuevo->planta.precio);
    printf("\ningrese  stock: ");
    scanf("%d", &nuevo->planta.stock);
    printf("ingrese  interior 1 o exterior 0: ");
    scanf("%d", &nuevo->planta.interior);
    printf("ingrese  tipo 0 arbol, 1 arbusto, 2 flor: ");
    scanf("%d", &nuevo->planta.tipo);

    nuevo ->sig = *p;
    *p = nuevo;
}

void insertarb(struct listab **p, char nombre[20], int precio){
    struct listab *nuevo = malloc(sizeof(struct listab));
    struct listab *point = *p;
    strcpy(nuevo-> dato.nombre, nombre);
    // nuevo-> dato.nombre = nombre; // ACA
    nuevo -> dato.precio = precio;
    nuevo -> sig = *p;
    *p = nuevo;

}

void generar_lista(struct lista **p, struct listab **a){
    struct lista *point = *p;
    while(point != NULL){   //otra lista con nombres, precios, si arbustos, exterior.
        if(point->planta.tipo == 1 && point->planta.interior ==0){
            insertarb(a, point->planta.nombre, point->planta.precio);  
        }
        point = point ->sig;
    }
}

void porcentaje(struct lista **p, float *porcentaje_interior, float *interior, float *exterior){
    struct lista *pointer = *p;
    printf("exterior: %f", *exterior);
    // if(pointer == NULL){
    //     *porcentaje_interior = *interior / (*interior + *exterior);
    //     return;
    // }
    // else{
    //     if(pointer->planta.interior ==0){    //interior 1 si, 0 es exterior
    //         *exterior +=1;
    //     }
    //     else{
    //         *interior +=1;
    //     }
        
    //     porcentaje(pointer->sig, porcentaje_interior, interior,exterior);
    // }
    while(pointer != NULL){
        if(pointer->planta.interior ==0){    //interior 1 si, 0 es exterior
            *exterior +=1;
            printf("\nse suma exterior");
        }
        else if (pointer->planta.interior ==1){
            *interior +=1;
            printf("\nse suma interior");
        }
        pointer = pointer ->sig;
    }
    printf("interior: %f ", *interior);
    printf("\nexterior: %f", *exterior);
    *porcentaje_interior = *interior / (*interior + *exterior);
}

void imprimir_lista(struct listab **p){
    struct listab *point = *p;
    printf("\nLista de arbustos de exterior");
    while(point != NULL){ 
        printf("\nNombre %s, precio %d", point->dato.nombre, point->dato.precio);
        point = point->sig;
    }
}