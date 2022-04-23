#include <stdlib.h>
#include <stdio.h>


typedef struct _nodo {
   int valor;
   struct _nodo *sig;
} tipoNodo;
 
typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;



void apilar (Pila *pila, int v);
int desapilar (Pila *pila);
int esvacia(Pila *pila);


/* apilar (añadir) un elemento en la pila */
void apilar(Pila *pila, int v) {
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   
   /* Añadimos la pila a continuación del nuevo nodo */
   nuevo->sig = *pila;
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   *pila = nuevo;
}

int desapilar(Pila *pila) {
   pNodo nodo; /* variable auxiliar para manipular nodo */
   int v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *pila;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a pila toda la pila menos el primer elemento */
   *pila = nodo->sig;
   /* Guardamos el valor de retorno */
   v = nodo->valor; 
   /* Borrar el nodo */
   free(nodo);
   return v;
}

int esvacia(Pila *pila)
{	 pNodo nodo; /* variable auxiliar para manipular nodo */
   nodo = *pila;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   else return 1;
	
}


int main()
{
	//declaro las variables
	Pila pila = NULL;
	int valor;
	int resp;
	//inicializo la pila
	//inicializacion(&pila);
	//cargo los datos
	printf("Desea agregar un elemento a la pila: (1/0)\n");
	scanf("%d",&resp);
	while(resp==1)
	{
		printf("Ingrese el valor\n");
		scanf("%d",&valor);
		apilar(&pila,valor);
		printf("Desea agregar un nuevo elemento a la pila: (1/0)\n");
		scanf("%d",&resp);
	}
	
	
	printf("Desea mostrar los datos de la pila: (1/0)\n");
	scanf("%d",&resp);
	while(resp==1 && esvacia(&pila)==1)
	{
 		printf("%d\n", desapilar(&pila));
	}
	return 0;
}
