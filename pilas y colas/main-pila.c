#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// DECLARACION DE LA PILA
typedef struct ElementoLista{
  char *dato;
  struct ElementoLista *siguiente;
} Elemento;

typedef struct ListaUbicacion{
  Elemento *inicio;
  int tamano;
} Pila;

// FIN DE DECLARACION DE LA PILA

void inicializacion (Pila * tas){
  tas->inicio = NULL;
  tas->tamano = 0;
}

// APILAR ELEMENTOS

int apilar (Pila * tas, char *dato){
  Elemento *nuevo_elemento;
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    return -1;
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nuevo_elemento->dato, dato);
  nuevo_elemento->siguiente = tas->inicio;
  tas->inicio = nuevo_elemento;
  tas->tamano++;
}

//DESAPILAR ELEMENTOS

int desapilar (Pila * tas){
  Elemento *sup_elemento;
  if (tas->tamano == 0)
    return -1;
  sup_elemento = tas->inicio;
  tas->inicio = tas->inicio->siguiente;
  free (sup_elemento->dato);
  free (sup_elemento);
  tas->tamano--;
  return 0;
}

// LISTA ELEMENTOS DE LA PILA

void muestra (Pila * tas){
  Elemento *actual;
  int i;
  actual = tas->inicio;
printf("\n********** PILA **********\n");
  for(i=0;i<tas->tamano;++i){
    printf("\t\t%s\n", actual->dato);
    actual = actual->siguiente;
  }
  printf("\n********** -------------- **********\n");
}

//MENU DE OPCIONES DE OPERACIONES CON PILAS

int menu (){

int eleccion;

printf("\n********** MENU - OPERACIONES BASICA CON PILAS - AYED **********\n");

	printf ("1. APILAR\n");
	
	printf ("2. DESAPILAR\n");
	
	printf ("3. MOSTAR\n");
	
	printf ("0. SALIR\n");


printf ("\n\nElegir: ");

scanf ("%d", &eleccion);

getchar();

return eleccion;

}

int main (int argc, char *argv[])
{
  Pila *tas;
  char *nom;
  char eleccion='o';
  
  if ((tas = (Pila *) malloc (sizeof (Pila))) == NULL)
    return -1;
  if ((nom = (char *) malloc (50 * sizeof (char))) == NULL)
    return -1;
    
  inicializacion (tas);


while (eleccion!= 0){

eleccion = menu ();

switch (eleccion){
	
	case 1:
	
		printf ("Ingrese una palabra: ");
 	    scanf ("%s", nom);
  		apilar (tas, nom);
  		
  		printf("\n********** VISTA DE LA PILA **********\n");
  		muestra(tas);
		break;
		
	case 2:
	
		desapilar (tas);
  		
  		printf("\n********** VISTA DE LA PILA **********\n");
  		muestra(tas);
		break;
	
	case 3:
		
		printf("\n********** VISTA DE LA PILA **********\n");
  		muestra(tas);
		break;
	
	}
	
}
	
 return 0;
}
	
  

