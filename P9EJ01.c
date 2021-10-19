#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo {
   char letra;
   struct _nodo *sig;
} tipoNodo;
 
typedef tipoNodo *Pila;

int esvacia(Pila *pila);

//declaro globalmente las varibales
char le;
char letra;
char palabra[10]="";
char invertida[10]="";
char v;

/* apilar (añadir) un elemento en la pila */
void apilar(Pila **pila, char v){
   Pila nuevo;
   /* Crear un nodo nuevo */
   nuevo = malloc(sizeof(tipoNodo));
   nuevo->letra = v; 
    //printf("Apilo %c\n",v);
   /* Añadimos la pila a continuación del nuevo nodo */
   nuevo->sig = *pila;
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   *pila = nuevo;
}

void desapilar (Pila **pila){
    Pila aux; //Creamos un nuevo nodo
    aux = *pila;
    v = aux->letra; // 
    //printf("Desapilo %c\n",v);
    *pila = aux->sig;
	free(aux); // libera el espacio

}


int esvacia(Pila *pila)
{	 Pila nodo; /* variable auxiliar para manipular nodo */
   nodo = *pila;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   else return 1;
	
}




int main()
{
	//declarar las variables etc
	Pila pila;
	pila = NULL;
	int iguales;
	
	int resp;
	//leer la palabra
	printf("Desea agregar una letra a la pila: (1/0)\n");
	scanf("%d",&resp);
	while(resp==1)
	{
		
		printf("Ingrese la letra\n");
		scanf("%s",&le);
		apilar(&pila,le);
		//concateno la palabra ingresada
		strncat(&palabra,&le,1);

		printf("Desea agregar otra letra a la pila: (1/0)\n");
		scanf("%d",&resp);
	}
	printf("Palabra %s\n",&palabra);

	//validar si es un palindromo
	
	while(esvacia(&pila)==1)
	{
		//desapilo y concateno la palabra invertida
		desapilar (&pila);
		strncat(&invertida,&v,1);
	}
	printf("Palabra Invertida %s\n",&invertida);	
	
	//comparo las palabras y determino si es un palindromo
	if (strcmp(palabra,invertida)==0)
		{		
		//la palabra es un palindromo
		printf("La palabra es un palindromo");
		}
	else
		{
			printf("La palabra no es un palindromo");
		}
		
	
	return 0;
}

