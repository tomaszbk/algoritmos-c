//lista de productos.   
//nombre, proveedor, codigo, precio.
/*-cargar productos
-eliminar producto dado codigo
-modify product w/ given code
-imprimir lista
-cantidad de productos
*/
#include <stdio.h>
//#include <string.h>
#include <stdlib.h>

struct producto{
 char nombre[20];
 char proveedor[20];
 int codigo, precio;
};

struct lista{
    struct producto dato;
    struct lista *sig;
};

void insertar(struct lista **l);
void eliminar(struct lista **l, int code);
void modificar(struct lista **l, int code);
void imprimir(struct lista *l);
int contar(struct lista *l); //aca ojo puntero

int main()
{
    struct lista *l = NULL;
    int x =1;
    int code =0;
    while(x!=0){
        printf("\nque desea hacer? \n1 insertar \n2 eliminar \n3 modificar \n4 imprimir \n5 contar elementos \n0 terminar\n");
        scanf("%d",&x);

        switch(x){
                case 0:
                    printf("muchas gracias");
                    break;
                case 1:
                    insertar(&l);
                    break;
                case 2:
                    printf("codigo para busqueda: ");
                    scanf("%d",&code);
                    eliminar(&l,code);
                    break;
                
                case 3:
                    printf("codigo para busqueda: ");
                    scanf("%d",&code);
                    modificar(&l,code);
                    break;
                case 4:
                    imprimir(l);
                    break;
                case 5:
                    contar(l);
                    break;
        }

    }
    return 0;
}


void insertar(struct lista **l){    //inserta al principio
    struct lista *nuevo = malloc(sizeof(struct lista));

    printf("\ningrese nombre producto: ");
    scanf("%s", nuevo->dato.nombre);
    printf("\ningrese nombre proveedor: ");
    scanf("%s", nuevo->dato.proveedor);
    printf("\ningrese  codigo: ");
    scanf("%d", &nuevo->dato.codigo);
    printf("\ningrese precio: ");
    scanf("%d", &nuevo->dato.precio);

    nuevo -> sig = *l;
    *l = nuevo;
}

void eliminar(struct lista **l, int code){
    struct lista *actual = *l;
    struct lista *anterior = *l;
    if(*l == NULL){
        printf("lista vacia");
        return;
    }
    while(actual -> sig != NULL){
        if(actual ->dato.codigo == code){
            if(actual == anterior){ //si es 1er elemento
                *l = actual -> sig;
                free(actual);
            }
            else{
                anterior->sig= actual ->sig;
                free(actual);
            }
        }
        anterior = actual;
        actual = actual ->sig;
    }

}
void modificar(struct lista **l, int code){
    struct lista *actual = *l;
    if(*l == NULL){
        printf("lista vacia");
        return;
    }
     while(actual != NULL){
        if(actual ->dato.codigo == code){   //aca menu para modificar
            printf("\ningrese nuevo precio: ");
            scanf("%d", &actual ->dato.precio);
            return;
        }
        actual = actual ->sig;
     }
     printf("no existe ese prod. con codigo ");
}

void imprimir(struct lista *l){         //cambiar nuevo por NULL
    struct lista *actual = l;
    printf("\nempezando a imprimir");
    while(actual != NULL){
        printf("\n%s, ", actual->dato.nombre);
        printf("%s, ", actual->dato.proveedor);
        printf("%d, ", actual->dato.codigo);
        printf("%d", actual->dato.precio);
        actual = actual ->sig;
    }
    printf("\nfin imprimir\n\n");
}

int contar(struct lista *l){
    struct lista *actual = l;
    int x = 0;
    while(actual != NULL){
            x++;
        actual = actual ->sig;
    }
    return x;
}