#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LISTA ALGORITMOS 2018 */
// DECLARACION DE ESTRUCTURA DE LISTA
	
typedef struct ElementoLista

{
	char *dato;
	struct ElementoLista *siguiente;

} Elemento; // |DATO|SIGUIENTE|--->|DATO|SIGUIENTE|--->.....-->|DATO|SIGUIENTE|--->NULL

typedef struct ListaIdentificar

{
	Elemento *inicio;
	Elemento *fin;
	int tamano;

} Lista; // INICIO--->|DATO|SIGUIENTE|--->|DATO|SIGUIENTE|--->.....FIN-->|DATO|SIGUIENTE|--->NULL


// FIN DE DECLARACION DE ESTRUCTURA DE LISTA

// FUNCIONES Y PROCEDIMIENTOS

// *****INICIALIZACION DE LISTAS

void inicialisacion (Lista * lista)

{

lista ->inicio = NULL;
lista ->fin = NULL;
lista ->tamano = 0;

}

// *****INSERTAR LISTA VACIA

int ins_en_lista_vacia (Lista * lista, char *dato){

Elemento *nuevo_elemento;

if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))== NULL)

return -1;

strcpy(nuevo_elemento->dato, dato);

nuevo_elemento->siguiente = NULL;

lista ->inicio = nuevo_elemento;

lista ->fin = nuevo_elemento;

lista ->tamano++;

return 0;

}

// *****INSERTAR EN UNA LISTA AL INICIO

int ins_inicio_lista (Lista * lista, char *dato){

Elemento *nuevo_elemento;

if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))== NULL)

return -1;

strcpy (nuevo_elemento->dato, dato);

nuevo_elemento->siguiente = lista->inicio;

lista ->inicio = nuevo_elemento;

lista ->tamano++;

return 0;

}

// *****INSERTAR EN UNA LISTA AL FINAL

int ins_fin_lista (Lista *lista, Elemento *actual, char *dato){

Elemento *nuevo_elemento;

if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))== NULL)

return -1;

strcpy (nuevo_elemento->dato, dato);

actual->siguiente = nuevo_elemento;

nuevo_elemento->siguiente = NULL;

lista ->fin = nuevo_elemento;

lista ->tamano++;

return 0;

}


// *****INSERTAR EN UNA LISTA EN UNA POSICION DETERMINADA

int ins_lista (Lista * lista, char *dato, int pos){

if (lista->tamano < 2)

return -1;

if (pos < 1 || pos >= lista ->tamano)

return -1;

Elemento *actual;

Elemento *nuevo_elemento;

int i;

if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)

return -1;

if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))== NULL)

return -1;

actual = lista->inicio;

for (i = 1; i < pos; ++i)

actual = actual->siguiente;

if (actual->siguiente == NULL)

return -1;

strcpy (nuevo_elemento->dato, dato);

nuevo_elemento->siguiente = actual->siguiente;

actual->siguiente = nuevo_elemento;

lista ->tamano++;

return 0;

}


// ELIMINAR UNA LISTA AL INICIO

int sup_inicio (Lista * lista){

if (lista ->tamano == 0)

return -1;

Elemento *sup_elemento;

sup_elemento = lista ->inicio;

lista ->inicio = lista ->inicio->siguiente;

if (lista ->tamano == 1)

lista ->fin = NULL;

free (sup_elemento->dato);

free (sup_elemento);

lista ->tamano--;

return 0;

}

// ELIMINAR UN ELEMENTO DE UNA LISTA 

int sup_en_lista (Lista * lista, int pos){

if (lista->tamano <= 1 || pos< 1 || pos >= lista->tamano)

return -1;

int i;

Elemento *actual;

Elemento *sup_elemento;

actual = lista ->inicio;

for (i = 1; i < pos; ++i)

actual = actual->siguiente;

sup_elemento = actual->siguiente;

actual->siguiente = actual->siguiente->siguiente;

if(actual->siguiente == NULL)

lista ->fin = actual;

free (sup_elemento->dato);

free (sup_elemento);

lista ->tamano--;

return 0;

}


//LISTAR UNA LISTA COMPLETA

void muestra (Lista * lista){

Elemento *actual;

actual = lista ->inicio;

while (actual != NULL){

printf ("%p - %s\n", actual, actual->dato);

actual = actual->siguiente;

}

}

//ELIMINAR LA LISTA COMPLETA

void destruir (Lista * lista){

while (lista->tamano > 0)

sup_inicio (lista);

}


//MENU DE OPCIONES DE OPERACIONES CON LISTAS

int menu (Lista *lista,int *k){

int eleccion;

printf("********** MENU - OPERACIONES BASICA CON LISTAS - AYED **********\n");

if (lista ->tamano == 0){

	printf ("1. Adicion el 1er elemento\n");
	
	printf ("2. Quitar\n");
	
	printf ("8. Listar\n");
	
	printf ("0. Salir\n");

}else if(lista ->tamano == 1 || *k == 1){

	printf ("1. Adicion al inicio de la lista\n");
	
	printf ("2. Adicion al final de la lista\n");
	
	printf ("4. Supresion al inicio de la lista\n");
	
	printf ("6. Destruir la lista\n");
	
	printf ("7. Quitar\n");
	
	printf ("8. Listar\n");
	
	printf ("0. Salir\n");

}else {

	printf ("1. Adicion al inicio de la lista\n");
	
	printf ("2. Adicion al final de la lista\n");
	
	printf ("3. Adicion despu�s de la posici�n indicada\n");
	
	printf ("4. Supresion al inicio de la lista\n");
	
	printf ("5. Supresion despues de la posicion indicada\n");
	
	printf ("6. Destruir la lista\n");
	
	printf ("7. Quitar\n");
	
	printf ("8. Listar\n");
	
	printf ("0. Salir\n");

}

printf ("\n\nElegir: ");

scanf ("%d", &eleccion);

getchar();

if(lista->tamano == 0 && eleccion == 2)

eleccion = 7;

return eleccion;

}


// CUERPO PRINCIPAL DEL PROGRAMA DE LISTAS

int main(int argc, char *argv[]) {
	
// MENU
char eleccion;

char *nom;

Lista *lista;

Elemento *actual;

if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL)

return -1;

if ((nom = (char *) malloc (50)) == NULL)

return -1;

actual = NULL;

eleccion = 'o';

inicialisacion (lista);

int pos, k;

while (eleccion!= 0){

eleccion = menu (lista, &k);

switch (eleccion){

	case 1:
	
		printf ("INGRESE UN ELEMENTO : ");		
		scanf ("%s", nom);
		
		getchar ();
		
		if (lista->tamano == 0)
		
		ins_en_lista_vacia (lista, nom);
		
		else
		
		ins_inicio_lista (lista, nom);
		
		printf ("%d ELEMENTOS:INICIO=%s,FIN=%s\n", lista->tamano,
		
		lista->inicio->dato, lista->fin->dato);
		
		muestra (lista);
		
		break;
	
	case 2:
	
		printf ("INGRESE UN ELEMENTO: ");	
		scanf ("%s", nom);
		
		getchar ();
		
		ins_fin_lista (lista, lista->fin, nom);
		
		printf ("%d ELEMENTO:INICIO=%s,FIN=%s\n", lista->tamano,
		
		lista->inicio->dato, lista->fin->dato);
		
		muestra (lista);
		
		break;
	
	case 3:
	
		printf ("INGRESE UN ELEMENTO: ");		
		scanf ("%s", nom);
		
		getchar ();
		
		do{
		
		printf ("INGRESE UNA POSICION: ");	
		scanf ("%d", &pos);
		
		}
		
		while (pos < 1 || pos > lista->tamano);
		
		getchar ();
		
		if (lista->tamano == 1 || pos == lista->tamano){
		
		k = 1;
		
		printf("-----------------------------------------------\n");		
		printf("/!\\ERROR DE INSERCION DE ELEMENTOS EN LA LISTA/!\\\n");		
		printf("-----------------------------------------------\n");
		
		break;
	
		}
		
		ins_lista (lista, nom, pos);
		
		printf ("%d ELEMENTOS:INICIO=%s,FIN=%s\n", lista->tamano,
		
		lista->inicio->dato, lista->fin->dato);
		
		muestra (lista);
		
		break;
	
	case 4:
	
		sup_inicio (lista);
		
		if (lista->tamano != 0)
		
		printf ("%d ELEMENTOS:INICIO=%s,FIN=%s\n", lista->tamano,
		
		lista->inicio->dato, lista->fin->dato);
		
		else
		
		printf ("LISTA VACIA\n");
		
		muestra (lista);
		
		break;
	
	case 5:
	
		do{
		
		printf ("INGRESE LA POSICION : ");
		
		scanf ("%d", &pos);
		
		}
		
		while (pos < 1 || pos > lista->tamano);
		
		getchar ();
		
		sup_en_lista (lista, pos);
		
		if (lista->tamano != 0)
		
		printf ("%d ELEMENTOS:INICIO=%s,FIN=%s\n", lista->tamano,
		
		lista->inicio->dato, lista->fin->dato);
		
		else
		
		printf ("LISTA VACIA\n");
		
		muestra (lista);
		
		break;
	
	case 6:
	
		destruir (lista);
		
		printf ("SE VACIO LA LISTA: %d ELEMENTOS\n", lista->tamano);
		
		break;
		
	case 8:
		
		printf ("LISTADO !!!!\n");
		muestra (lista);
		
	
	}

}

//FIN MENU

	return 0;
}