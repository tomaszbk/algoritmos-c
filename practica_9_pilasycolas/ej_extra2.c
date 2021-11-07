/* se toman pedidos de los clientes registrados. 
Al comenzar el sig día, los pedidos fueron pasados al sistema. Cada uno de los pedidos es encolado con los siguientes datos: 

código_producto, cuil_cliente y cantidad (unidades). 

Además, hay lista con los datos de sus productos: 
código_producto, descripción_producto, precio_producto y stock_producto;

y lista de sus clientes: 
cuil_cliente, nombre_y_apellido y domicilio_entrega. 

1) llevar a cabo el proceso de facturación de la distribuidora, generando en una lista los tickets de cada pedido con la siguiente información:
cuil_cliente, nombre_y_apellido, domicilio_entrega, descripción_producto y precio_total. 

2)	Tras haber facturado, se desean imprimir todos los datos de la lista final, recursivamente.

*Aclaración: cada nodo de la cola representa un pedido de un cliente con un solo producto, por lo tanto se generará un ticket para cada pedido independiente.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    //DATOS
struct dato_encolado{       //dato cola
    int codigo_producto, cuil, cantidad;
};

struct productos{           //dato producto
    int codigo_producto, precio_producto, stock_producto;
    char descripcion_producto[40];
};

struct clientes{        //dato cliente
    int cuil;
    char nombre_y_apellido[30];
    char domicilio[30];
};

    //LISTAS
struct lproductos{    //lista de productos
    struct productos dato;
    struct lproductos *sig;
};

struct lcola{        //cola
    struct dato_encolado dato;
    struct lcola *sig;
};

struct lclientes{     //lista de clientes     
    struct clientes dato;
    struct lclientes *sig;
};
struct cola{        //struct punteros de colas
    struct lcola *pini;
    struct lcola *pfin;
};

void agregar_cliente(struct lclientes **l,int cuil, char nombre_y_apellido[30],char domicilio[30]);
void agregar_producto(struct lproductos **l,int codigo_producto, int precio_producto, int stock_producto, char descripcion_producto[40]);
void encolar_productos(struct cola *pcola,int codigo_producto, int cuil, int cantidad);
void imprimir_clientes(struct lclientes *p);
void imprimir_productos(struct lproductos *p);
void imprimir_cola(struct cola *p);
// void crear_facturacion

int main()
{   
    struct cola pcola = {.pini=NULL, .pfin=NULL};  //creo la cola y las listas
    struct lclientes *pclientes = NULL;
    struct lproductos *pproductos = NULL;

    agregar_cliente(&pclientes, 111111,"antonia ascar", "la plata");    //cargo datos "iniciales"
    agregar_cliente(&pclientes, 222222,"beto bayo", "berisso");
    agregar_cliente(&pclientes, 333333,"carlos capro", "oosaka");

    agregar_producto(&pproductos, 1, 450, 6, "manzana");
    agregar_producto(&pproductos, 2, 600, 6, "banana");
    agregar_producto(&pproductos, 3, 250, 6, "durazno");
    agregar_producto(&pproductos, 4, 300, 6, "frutilla");
                                                            //ahora lo nuevo    




    return 0;
}

void agregar_cliente(struct lclientes **l,int cuil, char nombre_y_apellido[30],char domicilio[30]){
    struct lclientes *nuevo = malloc(sizeof(struct lclientes));

    nuevo -> sig = *l;
    *l = nuevo;
    nuevo ->dato.cuil = cuil;
    strcpy(nuevo-> dato.nombre_y_apellido, nombre_y_apellido);
    strcpy(nuevo-> dato.domicilio, domicilio);
    return;
}


void agregar_producto(struct lproductos **l,int codigo_producto, int precio_producto, int stock_producto, char descripcion_producto[40]){
    struct lproductos *nuevo = malloc(sizeof(struct lproductos));

    nuevo -> sig = *l;
    *l = nuevo;
    nuevo ->dato.codigo_producto = codigo_producto;
    nuevo ->dato.precio_producto = precio_producto;
    nuevo ->dato.stock_producto = stock_producto;
    strcpy(nuevo-> dato.descripcion_producto, descripcion_producto);
    return;
}

void encolar_productos(struct cola *pcola,int codigo_producto, int cuil, int cantidad){
    struct lcola *nuevo = malloc(sizeof(struct lcola));
    nuevo -> dato.codigo_producto = codigo_producto;
    nuevo ->dato.cuil = cuil;
    nuevo ->dato.cantidad = cantidad;
    nuevo -> sig == NULL;

    if(pcola->pini == NULL){
        pcola->pini = nuevo;
        pcola->pfin = nuevo;
        return;
    }
    else if(pcola->pini == pcola->pfin){
        pcola->pfin->sig = nuevo;
        pcola->pfin = nuevo;
        return;
    }
    else{
        
    }
}

void imprimir_clientes(struct lclientes *p){
    struct lclientes *point = p;
    printf("\nLista de clientes");
    while(point != NULL){ 
        printf("\nNombre %s, domicilio %s, cuil %d", point->dato.nombre_y_apellido, point->dato.domicilio, point->dato.cuil);
        point = point->sig;
    }
}
void imprimir_productos(struct lproductos *p){
    struct lproductos *point = p;
    printf("\nLista de productos");
    while(point != NULL){ 
        printf("\nCodigo %d, precio %d, stock %d, descripcion %s", point->dato.codigo_producto, point->dato.precio_producto,point->dato.stock_producto,point->dato.descripcion_producto);
        point = point->sig;
    }
}


// void imprimir_cola(struct cola *p){     //OJO
//     struct lcola *point = *p;  
//     printf("\nLista de clientes");
//     while(point != NULL){ 
//         printf("\nNombre %s, precio %d", point->dato.nombre, point->dato.precio);
//         point = point->sig;
//     }
// }