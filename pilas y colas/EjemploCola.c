#include <stdio.h>

//Declaro las estructuras
typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;

/* Funciones y procedimientos con colas: */
void encolar(pNodo *primero, pNodo *ultimo, int v);
int desencolar(pNodo *primero, pNodo *ultimo);
int esvacia(pNodo *primero);

void encolar(pNodo *primero, pNodo *ultimo, int v) {
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
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

int desencolar(pNodo *primero, pNodo *ultimo) {
   pNodo nodo; /* variable auxiliar para manipular nodo */
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
int esvacia(pNodo *primero)
{	 
	pNodo nodo; /* variable auxiliar para manipular nodo */
    if(!*primero) return 0; /* Si no hay nodos en la cola retornamos 0 */
    else return 1;
	
}
 
int main() {
	//Inicialmente la cola esta vacia
   pNodo primero = NULL, ultimo = NULL; 
	//Declaro variables locales
	int valor;
	int resp;

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
	
	
	printf("Desea mostrar los datos de la cola: (1/0)\n");
	scanf("%d",&resp);
	while(resp==1 && esvacia(&primero)==1)
	{
		//muestro los datos de la cola en el orden que fueron ingresados
 		printf("%d\n", desencolar(&primero, &ultimo));
	}
	
   return 0;
}


