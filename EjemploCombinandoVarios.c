//librerias a usar
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Pila
typedef struct _nodoP {
   int valor;
   struct _nodoP *siguiente;
} tipoPila;
 
typedef tipoPila *pNodo;

//Cola
typedef struct _nodoC {
   int valor;
   struct _nodoC *siguiente;
} tipoCola;

typedef tipoCola *cNodo;

//lista
typedef struct _nodoL{
          int valor;
          struct _nodoL *siguiente;
} tipoLista;

typedef tipoLista *lNodo;
typedef tipoLista *Lista;


////lista 2
//typedef struct _nodoL2{
//          int valor2;
//          int valor3;
//          struct _nodoL2 *siguiente;
//} tipoLista2;
//
//typedef tipoLista2 *lNodo2;
//typedef tipoLista2 *Lista2;
//
//void insertar2(tipoLista2 **l,int lb,int lb2){ //Envío por referencia la lista y por
//	//tipoLista *nuevo = malloc(sizeof *nuevo); //Defino el nuevo nodo
//	lNodo2 nuevo = malloc(sizeof nuevo); //Defino el nuevo nodo
//	nuevo->valor2=lb; //Asigno el dato al nuevo nodo
//	nuevo->valor3=lb2; //Asigno el dato al nuevo nodo
//	nuevo->siguiente=(l); //lo pongo al principio de la lista
//	l=nuevo; //redefinimos el comienzo de la lista
//}

//procedimientos lista
//crear la lista
void crear (tipoLista **l){
	*l=0; //Lista en NIL
}
//insertar al principio de la lista
void insertar(tipoLista **l,int lb){ //Envío por referencia la lista y por
	//tipoLista *nuevo = malloc(sizeof *nuevo); //Defino el nuevo nodo
	lNodo nuevo = malloc(sizeof nuevo); //Defino el nuevo nodo
	nuevo->valor=lb; //Asigno el dato al nuevo nodo
	nuevo->siguiente=(l); //lo pongo al principio de la lista
	l=nuevo; //redefinimos el comienzo de la lista
	printf("%d -> ", nuevo->valor);
}

//Insertar Ordenado
void Insertar(lNodo *lista, int v) {
   lNodo nuevo, anterior;
 
   /* Crear un nodo nuevo */
   nuevo = (lNodo)malloc(sizeof(tipoLista));
   nuevo->valor = v;
   
   /* Si la lista está vacía */
   if(ListaVacia(*lista) || (*lista)->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista; 
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v */
      while(anterior->siguiente && anterior->siguiente->valor <= v) 
         anterior = anterior->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
   //printf("%d -> ", nuevo->valor);
}
//Borrar un nodo de la lista
void BorrardeLista(tipoLista **lista, int v) {
   lNodo anterior, nodo;
   
   nodo = *lista;
   anterior = NULL;
   while(nodo && nodo->valor < v) {
      anterior = nodo; 
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->valor != v) return;
   else { /* Borrar el nodo */
      if(!anterior) /* Primer elemento */
         *lista = nodo->siguiente;
      else  /* un elemento cualquiera */
         anterior->siguiente = nodo->siguiente;
      free(nodo);
   }   
}
//mostrar los datos de la lista
void MostrarLista(tipoLista *lista) {
   //lNodo nodo = lista;

   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(lista) {
         printf("%d -> ", lista->valor);
         lista = lista->siguiente;
     }
     printf("\n");
   }
}

int ListaVacia(tipoLista *lista) {
   return (lista == NULL);
}


//Pilas
/* apilar (añadir) un elemento en la pila */
void apilar(tipoPila *pila, int v) {
   pNodo nuevo;
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoPila));
   nuevo->valor = v;
   
   /* Añadimos la pila a continuación del nuevo nodo */
   nuevo->siguiente = pila;
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   pila = nuevo;
}

int desapilar(tipoPila *pila) {
   pNodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = pila;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a pila toda la pila menos el primer elemento */
   pila = nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   free(nodo);
   return v;
}

int esvaciaPila(tipoPila *pila)
{	 pNodo nodo; /* variable auxiliar para manipular nodo */
   nodo = pila;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   else return 1;
}

//Colas
void encolar(cNodo *primero, cNodo *ultimo, int v) {
   cNodo nuevo;
   /* Crear un nodo nuevo */
   nuevo = malloc(sizeof(tipoCola));
   nuevo->valor = v;
   /* Este será el último nodo, no debe tener siguiente */
   nuevo->siguiente = NULL;
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(*ultimo) (*ultimo)->siguiente = nuevo;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   *ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!*primero) *primero = nuevo;
}

int desencolar(cNodo *primero, cNodo *ultimo) {
   cNodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   *primero = nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   free(nodo);
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!*primero) *ultimo = NULL;
   return v;
}

//funcion para determinar si la cola es vacia
int esvaciaCola(cNodo *primero)
{	 
	cNodo nodo; /* variable auxiliar para manipular nodo */
    if(!*primero) return 0; /* Si no hay nodos en la cola retornamos 0 */
    else return 1;
}


int main() {
	//Inicialmente la cola esta vacia
   cNodo primero = NULL, ultimo = NULL; 
	//Lista
	lNodo lis = NULL; 
	//Declaro variables locales
	int valor;
	int resp;
	int datoencola;
	int minimo;

	//cargo los datos
	printf("Desea agregar un elemento a la cola: (1/0)\n");
	scanf("%d",&resp);
	while(resp==1)
	{
		printf("Ingrese el valor\n");
		scanf("%d",&valor);
		//agrego elementos en la cola
		encolar(&primero,&ultimo,valor);
		printf("Desea agregar un nuevo elemento a la cola: (1/0)\n");
		scanf("%d",&resp);
	}
	
	
	printf("Desea pasar los datos de la cola a la lista?: (1/0)\n");
	scanf("%d",&resp);
	
	if (resp==1)
	{
	printf("Ingrese el valor minimo a insertar\n");
	scanf("%d",&minimo);
	}
	
		
	while(resp==1 && esvaciaCola(&primero)==1)
	{
		datoencola=desencolar(&primero, &ultimo);
		printf("El dato que voy a desencolar es %d\n ", datoencola);
		//paso la cola a la lista
		//Insertar(&lis, desencolar(&primero, &ultimo));
		
		
		if (datoencola>minimo)
		{
			Insertar(&lis, datoencola*10);
		}
	
	}
	printf("Datos en la lista\n");
	MostrarLista(lis);
   return 0;
}
