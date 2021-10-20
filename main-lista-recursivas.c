#include <stdio.h>
#include <stdlib.h>
 
typedef struct snodo{ //snodo es el nombre de la estructura
    int valor;
    struct snodo *sig; //El puntero siguiente para recorrer la lista enlazada
}tnodo; //tnodo es el tipo de dato para declarar la estructura
 
typedef tnodo *tpuntero; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros
 
int menu();
void insertarEnLista (tpuntero *cabeza, int e);
void imprimirLista (tpuntero cabeza);
void sumaLista (tpuntero cabeza);
int contarLista (tpuntero cabeza);
int clasificarLista (tpuntero cabeza);
int MayorLista (tpuntero cabeza);
int sumaListaR(tpuntero cabeza);

void borrarLista (tpuntero *cabeza);
 
 // CUERPO PRINCIPAL DEL PROGRAMA
 
int main(){
    int e;
    int t;
    int eleccion=9;
    
    tpuntero cabeza; //Indica la cabeza de la lista enlazada, si la perdemos no podremos acceder a la lista
    cabeza = NULL; //Se inicializa la cabeza como NULL ya que no hay ningun nodo cargado en la lista
     
         
     while (eleccion != 0){


		switch (eleccion){
		
			case 1:
				printf("INGRESAR UN NUMERO : \n");
	    		scanf("%d",&e);
			    insertarEnLista (&cabeza, e);
			        				
				break;
			case 2:
					printf ("\nLISTA CARGADA:\n ");
                    imprimirLista (cabeza);
                    break;
            case 3:
					t= contarLista (cabeza);
					printf ("\n NODOS = %4d\n",t);
					break;
            case 4:
					t= clasificarLista (cabeza);
					printf ("\n NODOS con 0 = %4d\n",t);
					break;
            case 5:
					t= MayorLista (cabeza);
					printf ("\n NRO MAYOR = %4d\n",t);
					break;
			case 6:
					printf ("\n SUMA  %4d\n",t);
   					sumaLista (cabeza);
   					
   					break;
   			case 7:
					t=sumaListaR (cabeza);
					printf ("\n SUMA RECURSIVA: %4d\n",t);
   					
   					break;
			case 8:
			   		printf ("\nBORRAR LISTA\n");
    				borrarLista (&cabeza);
					break;
			}
     
       eleccion=menu();
     
     
 }
   
    printf ("\n");
    system ("PAUSE");
     
return 0;
}
 
 
 
 int menu (){

	int op=0;
	
	printf ("\nOPERACIONES CON LISTA RECURSIVAS - AYED - 2018\n ");
	printf ("\n ");
	printf ("INGRESE 1: CARGAR LISTA \n ");
	printf ("INGRESE 2: LISTAR NODOS \n ");
	printf ("INGRESE 3: CONTAR NODOS\n ");
	printf ("INGRESE 4: CONTAR NODOS CON 0\n ");
	printf ("INGRESE 5: MAYOR \n ");
	printf ("INGRESE 6: SUMA LOS NODOS\n ");
	printf ("INGRESE 7: SUMA RECURSIVA\n ");
	printf ("INGRESE 8: ELIMINAR LISTA\n ");
	printf ("INGRESE 0: SALIR \n ");
	printf ("\n ");
	printf ("INGRESE UNA OPCION:\n ");
		
	scanf ("%d", &op);
	return op;
}
// crear una lista

void insertarEnLista (tpuntero *cabeza, int e){
    tpuntero nuevo; //Creamos un nuevo nodo
    nuevo = malloc(sizeof(tnodo)); //Utilizamos malloc para reservar memoria para ese nodo
    nuevo->valor = e; //Le asignamos el valor ingresado por pantalla a ese nodo
    nuevo->sig = *cabeza; //Le asignamos al siguiente el valor de cabeza
    *cabeza = nuevo; //Cabeza pasa a ser el ultimo nodo agregado
}
 
 // imprimir una lista en con repeticion
 
void imprimirLista(tpuntero cabeza){
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        printf("%4d",cabeza->valor); //Imprimimos el valor del nodo
        cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
}

// sumar el contenimdo de una lista en repeticion

void sumaLista(tpuntero cabeza){
	int sum=0;
	
    while(cabeza != NULL){ //Mientras cabeza no sea NULL
        sum=sum+cabeza->valor;
		cabeza = cabeza->sig; //Pasamos al siguiente nodo
    }
    
    printf("LA SUMA ES %4d",sum); 
}

// sumar el contenido de una lista en forma recursiva

int sumaListaR(tpuntero cabeza){
	
if (cabeza != NULL){
	  
	  return sumaListaR(cabeza->sig)+cabeza->valor;
	  }
else  {
	
	return 0;
	
	}
}


// clasificar en una lista los contenidos con cero, forma recursiva

int clasificarLista(tpuntero cabeza){
			
	if (cabeza != NULL){
	  
	  if (cabeza->valor==0){
	  return clasificarLista(cabeza->sig)+1;
	  }
	  return clasificarLista(cabeza->sig);
}
else  {
	
	return 0;
	
	}
}

// determinar el mayor numero en una lista en forma recursiva

int MayorLista(tpuntero cabeza){
			
	if (cabeza != NULL){
	  
	  if (cabeza->valor>=MayorLista(cabeza->sig)){
	  return cabeza->valor;
	  }
	  return MayorLista(cabeza->sig);
}
else  {
	
	return 0;
	
	}
}

//contar cuantos nodos o elementos hay en una lista , en forma recursiva

int contarLista(tpuntero cabeza){
		
	if (cabeza != NULL){
	  return contarLista(cabeza->sig) + 1;
}
else  {
	
	return 0;
	
	}
}

//eliminar una lista en forma de repeticion

void borrarLista(tpuntero *cabeza){ 
    tpuntero actual; //Puntero auxiliar para eliminar correctamente la lista
  
    while(*cabeza != NULL){ //Mientras cabeza no sea NULL
        actual = *cabeza; //Actual toma el valor de cabeza
        *cabeza = (*cabeza)->sig; //Cabeza avanza 1 posicion en la lista
        free(actual); //Se libera la memoria de la posicion de Actual (el primer nodo), y cabeza queda apuntando al que ahora es el primero
    }
}

