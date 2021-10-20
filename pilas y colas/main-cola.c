#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// DECLARACION DE LA COLA

typedef struct ElementoLista{
  char *dato;
  struct ElementoLista *siguiente;
} Elemento;

typedef struct ListaUbicacion{
  Elemento *inicio;
  Elemento *fin;
  int tamano;
} Fila;


// INICIALIZACON DE LA COLA

void inicializacion (Fila * serie){
  serie->inicio = NULL;
  serie->fin = NULL;
  serie->tamano = 0;
}


//AGREGAR UN ELEMENTO A LA PILA 

int insertar (Fila * serie, Elemento * actual, char *dato){
  Elemento *nuevo_elemento;
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_elemento->dato, dato);

  if(actual == NULL){
    if(serie->tamano == 0)
      serie->fin = nuevo_elemento;
    nuevo_elemento->siguiente = serie->inicio;
    serie->inicio = nuevo_elemento;
  }else {
    if(actual->siguiente == NULL)
      serie->fin = nuevo_elemento;
    nuevo_elemento->siguiente = actual->siguiente;
    actual->siguiente = nuevo_elemento;
  }
  serie->tamano++;
  return 0;
}


// SACAR UN ELEMENTO DE LA COLA

int eliminar (Fila * serie){
  Elemento *sup_elemento;
  if (serie->tamano == 0)
    return -1;
  sup_elemento = serie->inicio;
  serie->inicio = serie->inicio->siguiente;
  free (sup_elemento->dato);
  free (sup_elemento);
  serie->tamano--;
  return 0;
}


// LISTA LA COLA 

void muestra(Fila *serie){
  Elemento *actual;
  int i;
  actual = serie->inicio;
 printf("\n********** COLA **********\n");
  for(i=0;i<serie->tamano;++i){
    printf(" %s ", actual->dato);
    actual = actual->siguiente;
  }
  printf("\n********** ----------******\n");
}


//MENU DE OPCIONES DE OPERACIONES CON COLAS

int menu (){

int eleccion;

printf("\n********** MENU - OPERACIONES BASICA CON COLAS - AYED **********\n");

	printf ("1. ENCOLAR\n");
	
	printf ("2. DESENCOLAR\n");
	
	printf ("3. MOSTAR\n");
	
	printf ("0. SALIR\n");


printf ("\n\nElegir: ");

scanf ("%d", &eleccion);

getchar();

return eleccion;

}

int main (int argc, char *argv[])
{
  Fila *serie;
  char *nom;
  char eleccion='o';
  
  if ((serie = (Fila *) malloc (sizeof (Fila))) == NULL)
    return -1;
  if ((nom = (char *) malloc (50 * sizeof (char))) == NULL)
    return -1;
    
inicializacion (serie);

    
 while (eleccion!= 0){

eleccion = menu ();

switch (eleccion){
	
	case 1:
	
	 	printf ("Ingrese una palabra: ");
  		scanf ("%s", nom);
  		insertar (serie, serie->fin, nom);

  		
  		printf("\n********** VISTA DE LA COLA **********\n");
  		  muestra (serie);
		break;
		
	case 2:
	
		eliminar(serie);
  		
  			printf("\n********** VISTA DE LA COLA **********\n");
  		  muestra (serie);
		break;
	
	case 3:
		
			printf("\n********** VISTA DE LA COLA **********\n");
  		  muestra (serie);
		break;
	
	}
	
}
	
 return 0;
}
	
  


