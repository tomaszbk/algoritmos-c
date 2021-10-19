//Programa Pedidos

//Declaracion de librerias a utilizar.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Declaracion de los tipos estructurados a utilizar.
//Cola de pedidos
struct Pedido {
    int codProd;
    int cuil;
    int cant;
};

struct LisCola{
        struct Pedido dato;
        struct LisCola *pSig;
};

struct Cola{
    struct LisCola *pIni;
    struct LisCola *pFin;
};

//Lista de clientes
struct Cliente {
    int cuil;
    char nomYApe[30];
    char domEntrega[20];
};

struct ListaCli {
    struct Cliente dato;
    struct ListaCli *pSig;
};

//Lista de productos
struct Producto {
    int codigo;
    char descripcion[50];
    float precio;
    int stock;
};

struct ListaProd {
    struct Producto dato;
    struct ListaProd *pSig;
};

//Lista final
struct DatoFinal{
    int cuil;
    char nomYApe[30];
    char domEntrega[20];
    char descProd[50];
    float total;
};

struct Lista{
    struct DatoFinal dato;
    struct Lista *pSig;
};

//Declaracion de los procedimientos a utilizar
void cargaInicial(struct Cola *c);
void inicializarCola(struct Cola *c);
void encolar(struct Cola *c, struct Pedido p);
void desencolar(struct Cola *c, struct Pedido *p);
int esVacia(struct Cola c);
int buscarProducto(struct ListaProd *l,int codigoBuscar, struct Producto *p );
int buscarCliente(struct ListaCli *l,int cuilBuscar, struct Cliente *c );
void insertarFinal(struct Lista **l,struct DatoFinal d);
void recorrerRecursivamente(struct Lista *l);

int main(){
	//Variables a utilizar
	struct ListaCli *lisCli=0;
	struct ListaProd *lisProd=0;
	struct Lista *lisFin=0;
	struct Cola colaPedidos;
	struct Producto regProducto;
	struct Cliente regCliente;
	struct DatoFinal regFinal;
	struct Pedido regPedido;
	char rta='s';

	inicializarCola(&colaPedidos);

    //Carga inicial de datos
 	printf("Desea cargar pedidos?s/n\n");
	scanf("%c",&rta);   
	while(rta != 'n'){
		_clrscr();
        cargaInicial(&colaPedidos);
 		_clrscr();
		printf("Desea cargar otro pedido? S/N \n");
		scanf("%c", &rta);
		scanf("%c", &rta);
    }
	if(esVacia(colaPedidos)){
			_clrscr();
			printf("No hay pedidos para procesar\n");
	}else{	 
    //Procesamiento de pedidos
	  	while(!esVacia(colaPedidos)){  
			 	desencolar(&colaPedidos,&regPedido);
				if(buscarProducto(lisProd,regPedido.codProd,&regProducto) && buscarCliente(lisCli,regPedido.cuil,&regCliente)){
					regFinal.cuil = regCliente.cuil;
					strcpy(regFinal.nomYApe,regCliente.nomYApe);
                    strcpy(regFinal.domEntrega,regCliente.domEntrega);
                    strcpy(regFinal.descProd,regProducto.descripcion);
					regFinal.total = (regProducto.precio * regPedido.cant);
					insertarFinal(&lisFin,regFinal);					
				}else{
					printf("Los datos de la venta no corresponden a un producto o a un cliente valido \n");
					printf("Datos ingresados:\n");
					printf("-----------\n");
					printf("Codigo producto: %d\n",regPedido.codProd);
					printf("Cuil cliente: %d\n",regPedido.cuil);
					printf("Cantidad: %d\n",regPedido.cant);
					printf("-----------\n");
				}
		  	    
		}
	}	

	//Recorrido recursivo
	recorrerRecursivamente(lisFin);

    return 0;
}

void inicializarCola(struct Cola *c){

	c->pIni=0;
	c->pFin=0;

}

int esVacia(struct Cola c){

	if (c.pIni==0){
		return 1;
	}
	else{
		return 0;
	}

}

void encolar(struct Cola *c, struct Pedido p){

    struct LisCola *nuevo=malloc(sizeof(struct LisCola));

    nuevo->dato= p;
    nuevo->pSig= 0;
    if(c->pIni == 0){
        c->pIni= nuevo;
    }else{
        c->pFin->pSig= nuevo;
    }
    c->pFin = nuevo;

}

void desencolar(struct Cola *c, struct Pedido *p){

    struct LisCola *nodoAux=malloc(sizeof(struct LisCola));
    
    *p= c->pIni->dato;
    nodoAux = c->pIni;
    c->pIni = nodoAux->pSig; 
    if(c->pIni == 0){
        c->pFin = 0;
    }
    free(nodoAux);

}

void cargaInicial(struct Cola *c){

    struct Pedido ped;

    printf("Ingrese el codigo del producto:\n");
    scanf("%d",&ped.codProd);
    _clrscr();
    printf("Ingrese cantidad:\n");
    scanf("%d",&ped.cant);
    _clrscr();
    printf("Ingrese cuil del cliente:\n");
    scanf("%d",&ped.cuil);
    _clrscr();
    encolar(c,ped);

}

int buscarProducto(struct ListaProd *l,int codigoBuscar, struct Producto *p ){
    struct ListaProd *aux;
    
    aux = l;
    while(aux->pSig != 0 && (aux->dato).codigo != codigoBuscar ){
        aux = aux->pSig;
    }
    if( aux->pSig == 0){
        return 0;
    }else{
        *p = aux->dato;
        return 1;
    }

}

int buscarCliente(struct ListaCli *l,int cuilBuscar, struct Cliente *c ){
    struct ListaCli *aux;

    aux = l;
    while(aux->pSig != 0 && (aux->dato).cuil != cuilBuscar ){
        aux = aux->pSig;
    }
    if( aux->pSig == 0){
        return 0;
    }else{
        *c = aux->dato;
        return 1;
    }
}

void insertarFinal(struct Lista **l, struct DatoFinal r){
    struct Lista *nuevo=malloc(sizeof(struct Lista));
    struct Lista *aux;

    aux = *l;
    nuevo->dato = r;
    nuevo->pSig = 0;

    if(*l == 0){
        *l = nuevo;
    }else{
        while( aux->pSig != 0 ){
            aux = aux->pSig;
        }
        aux->pSig = nuevo;
    }
}

void recorrerRecursivamente(struct Lista *l){
    if(l == 0){
        //Fin de la lista
    }else{
		struct DatoFinal nodoAux;
		nodoAux = l->dato;
        printf("--- Listado de tickets ---");
        printf("-----------------\n");
        printf("Cuil cliente: %d\n",nodoAux.cuil);
        printf("Nombre y apellido: %s\n",nodoAux.nomYApe);
        printf("Domicilio de entrega: %s\n",nodoAux.domEntrega);
        printf("Descripcion del producto: %s\n",nodoAux.descProd);
        printf("Total de la venta: %f\n",nodoAux.total);
        printf("-----------------\n");
		recorrerRecursivamente(l);
    }
}