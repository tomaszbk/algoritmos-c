// Se tiene una lista de precios de productos vendidos en Carrefour y otra lista con los precios de 
// los mismos productos vendidos en Disco. Se desea obtener una tercera lista con los nombres de 
// cada uno de los productos y el nombre del supermercado donde me conviene comprarlos.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct productos{
    char nombre[10]; //ACA ESPECIFICAR CANTIDAD DE CHAR
    int precio;
};

struct lista{
    struct productos producto;
    struct lista *sig;
};



void insertar(struct lista **p, char *name, int price);
void imprimir(struct lista **p);
void lista_def(struct lista **c,struct lista **d,struct lista **def);
void imprimir_def(struct lista **p);

int main()
{
    struct lista *carrefour = NULL;
    struct lista *disco = NULL;
    struct lista *conviene = NULL;

    insertar(&carrefour,"mila", 500);   //carga de datos
    insertar(&carrefour,"pollo", 300);
    insertar(&carrefour,"chori", 900);
    insertar(&carrefour,"cerdo", 100);

    insertar(&disco,"mila", 1250);
    insertar(&disco,"pollo", 50);
    insertar(&disco,"chori", 400);
    insertar(&disco,"cerdo", 100);

    imprimir(&carrefour);
    imprimir(&disco);

    lista_def(&carrefour,&disco,&conviene);
    printf("justo antes de ult imprimir");
    imprimir_def(&conviene);
    return 0;
}


void insertar(struct lista **p, char *name, int price){
    struct lista *nuevo = malloc(sizeof(struct lista));
    struct lista *point = *p;
    strcpy(nuevo -> producto.nombre, name);
    nuevo -> producto.precio = price;
    nuevo -> sig = NULL;
    if(*p == NULL){
        *p = nuevo;
        return;
    }
    else{
        while(point ->sig != NULL){
            point = point ->sig;
        }
        point-> sig = nuevo;
    }
}


void imprimir(struct lista **p){
    struct lista *point = *p;
    printf("\nempezo a imprimir");
    if(point == NULL){
        printf("lista vacia");
    }
    else{
    
        while(point != NULL){
            printf("\nproducto %s ,", point -> producto.nombre);
            printf("precio %d ", point -> producto.precio);   
            point = point ->sig;
        }
    }
    printf("\n\n");
}

void lista_def(struct lista **c,struct lista **d,struct lista **def){
    struct lista *pointerc = *c;    
    struct lista *pointerd = *d;
    char nombre [10];
    int numero;
    int cont = 0;
    while(pointerc != NULL){         
            
        printf("\nempieza vuelta ");           //CARREFOUR 0, DISCO 1, IGUAL 2
        strcpy(nombre, pointerc->producto.nombre);
        printf("%s",nombre);
        if(pointerc->producto.precio < pointerd->producto.precio){
            numero = 0;
        }
        else if(pointerc->producto.precio > pointerd->producto.precio){
            numero = 1;
        }
        else{
            numero = 2;
        }
        printf("\nhasta aca bien");
        insertar(def,nombre,numero);
        printf("\nse inserto");
        printf("%d", pointerc);
        pointerc = pointerc -> sig;  
        pointerd = pointerd -> sig;      
        printf("hola");
        cont++;
    }   
}
void imprimir_def(struct lista **p){
    struct lista *point = *p;
    printf("\nempezo a imprimir");
    if(point == NULL){
        printf("lista vacia");
    }
    else{
    
        while(point != NULL){
            printf("\nproducto %s ,", point -> producto.nombre);
            printf("conviene comprar en ");   
            switch (point -> producto.precio){
                case 0:
                    printf("carrefour");
                    break;
                case 1:
                    printf("disco");
                    break;
                case 2:
                    printf("cualquiera de los dos");
                    break;
                }
            point = point ->sig;
        }
    }
}