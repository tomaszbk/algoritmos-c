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

struct dato_factura{
    int cuil;
    char nombre_y_apellido[30];
    char domicilio[30];
    char descripcion_producto[30];
    int precio_total;

};

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
struct lfactura{
    struct dato_factura dato;
    struct lfactura *sig;
};

//FUNCIONES!

void agregar_cliente(struct lclientes **l,int cuil, char nombre_y_apellido[30],char domicilio[30]);
void agregar_producto(struct lproductos **l,int codigo_producto, int precio_producto, int stock_producto, char descripcion_producto[40]);
void encolar_productos(struct cola *pcola,int codigo_producto, int cuil, int cantidad);
void imprimir_clientes(struct lclientes *p);
void imprimir_productos(struct lproductos *p);
void imprimir_cola(struct cola p);
struct lfactura * crear_factura(struct lfactura *p, struct lcola *pini, struct lclientes *clientes, struct lproductos *productos);
struct lclientes * busqueda_cliente(struct lclientes *p, int cuil); //dado cuil
struct lproductos * busqueda_producto(struct lproductos *p, int codigo_producto); //dado codigo
void print_factura(struct lfactura *p);

int main()
{   
    struct cola pcola = {.pini=NULL, .pfin=NULL};  //creo la cola y las listas
    struct lclientes *pclientes = NULL;
    struct lproductos *pproductos = NULL;

    agregar_cliente(&pclientes, 111,"antonia ascar", "la plata");    //cargo datos "iniciales"
    agregar_cliente(&pclientes, 222,"beto bayo", "berisso");
    agregar_cliente(&pclientes, 333,"carlos capro", "oosaka");

    agregar_producto(&pproductos, 1, 450, 6, "manzana");
    agregar_producto(&pproductos, 2, 600, 6, "banana");
    agregar_producto(&pproductos, 3, 250, 6, "durazno");
    agregar_producto(&pproductos, 4, 300, 6, "frutilla");
                                                            //ahora lo nuevo    
    encolar_productos(&pcola, 2, 111, 2);
    encolar_productos(&pcola, 2, 222, 3);
    encolar_productos(&pcola, 1, 111, 2);
    encolar_productos(&pcola, 3, 333, 1);

    imprimir_clientes(pclientes);
    printf("\n\n");
    imprimir_productos(pproductos);
    printf("\n\n");
    imprimir_cola(pcola);
    printf("\nlo basic");
    struct lfactura *pfactura = crear_factura(NULL, pcola.pini, pclientes, pproductos);
    printf("\nACAA\n");
    print_factura(pfactura);
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

    nuevo -> sig = NULL;

    if(pcola->pini == NULL){
        pcola->pini = nuevo;
    }
    else{
        pcola->pfin->sig = nuevo;
    }
    pcola->pfin = nuevo;
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

void imprimir_cola(struct cola p){     //OJO
    struct lcola *point = p.pini;  
    printf("\nContenido cola");
    while(point != NULL){ 
        printf("\nCodigo producto %d, cuil comprador %d, cantidad %d", point->dato.codigo_producto, point->dato.cuil,point->dato.cantidad);
        point = point->sig;
    }
    return;
}

struct lfactura * crear_factura(struct lfactura *p, struct lcola *pini, struct lclientes *clientes, struct lproductos *productos){ //lo mas dificil
    struct lfactura *nuevo = malloc(sizeof(struct lfactura));
    struct lcola *cola_actual = pini;  

    if(cola_actual != NULL){
        nuevo ->dato.cuil = pini->dato.cuil;
        p = nuevo;
        struct lproductos *producto_actual = busqueda_producto(productos, cola_actual->dato.codigo_producto); //dado codigo OJO
        struct lclientes *cliente_actual = busqueda_cliente(clientes, cola_actual->dato.cuil);
        nuevo ->dato.precio_total = producto_actual->dato.precio_producto * cola_actual->dato.cantidad;
        strcpy(nuevo-> dato.descripcion_producto, producto_actual->dato.descripcion_producto);     
        strcpy(nuevo-> dato.nombre_y_apellido, cliente_actual->dato.nombre_y_apellido);
        strcpy(nuevo-> dato.domicilio, cliente_actual->dato.domicilio);
        printf("aca bn");
        nuevo -> sig = crear_factura(p, pini->sig, clientes, productos);

        printf("\nCuil del comprador: %d\nnombre y apellido: %s\ndomicilio:%s\ndescripcion del producto:%s\nprecio total:%d\n\n",nuevo->dato.cuil,nuevo->dato.nombre_y_apellido,nuevo->dato.domicilio,nuevo->dato.descripcion_producto,nuevo->dato.precio_total);
        return p;
    }
    else{
        return NULL;
    }

}
    //en factura: int cuil; char nombre_y_apellido[30]; char domicilio[30]; char descripcion_producto[30];  int precio_total;
    //en cola: int codigo_producto, cuil, cantidad;

struct lclientes * busqueda_cliente(struct lclientes *p, int cuil){ //dado cuil
    struct lclientes *point = p;
     while( point->dato.cuil != cuil){
        point = point->sig;
    }
    return point;
}

struct lproductos * busqueda_producto(struct lproductos *p, int codigo_producto){ //dado codigo
    struct lproductos *point = p;
    while( point->dato.codigo_producto != codigo_producto){
        point = point->sig;
    }
    
    return point;
}

void print_factura(struct lfactura *p){
    struct lfactura *point = p;
    while(point != NULL){
        printf("\n%s",point->dato.nombre_y_apellido);
        point = point->sig;
    }
}