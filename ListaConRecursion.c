#include <stdlib.h>
#include <stdio.h>
 
typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;
 

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

//Insertar Ordenado
void Insertar(Lista *lista, int v) {
   pNodo nuevo, anterior;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
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
}

int ListaVacia(Lista lista) {
   return (lista == NULL);
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {
         printf("%d -> ", nodo->valor);
         nodo = nodo->siguiente;
     }
     printf("\n");
   }
}

int ContarRecursivo(Lista lista) {
   pNodo nodo = lista;
 
   if(!ListaVacia(lista)) //Si a lista no esta vacia
   {
   	 	//llamo nuevamente a la funcion con el nodo siguiente y sumo 1 al retorno
   		//return ContarRecursivo(nodo->siguiente)+1; 
   		return ContarRecursivo(nodo->siguiente)+nodo->valor;
   }
   else //si la lista esta vacia (caso base)
   {
   	return 0;
   }
}

int Contar(Lista lista) {
   pNodo nodo = lista;
   int suma=0;

   if(ListaVacia(lista)) return 0;
   else {
      while(nodo) {
         suma=suma+nodo->valor;
         nodo = nodo->siguiente;
     }
     
   }
   return suma;
}

int main() {
   Lista lista = NULL;
   pNodo p;
   int CantidadNodos;
 
   Insertar(&lista, 20);
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);
   Insertar(&lista, 32);
  Insertar(&lista, 39);
Insertar(&lista, 79);

   MostrarLista(lista);
   //Con recursion
   //CantidadNodos = ContarRecursivo(lista);
   
   //sin recursion
   CantidadNodos = Contar(lista);
   //printf("La lista tiene %d nodos ", CantidadNodos);
   printf("La lista suma en total %d ", CantidadNodos);

   return 0;
}
