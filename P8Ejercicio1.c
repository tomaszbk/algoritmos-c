//librerias a usar
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//estrucutra de la lista
struct lista{
          int dato;
          struct lista *ps;
};

void crear (struct lista **l);
void insertar(struct lista **l,int lb);
void cuantasveces(struct lista *l,int numero);

//procedimientos
//crear la lista
void crear (struct lista **l){
	*l=0; //Lista en NIL
}

void insertar(struct lista **l,int lb){ //Envio por referencia la lista y por
	struct lista *nuevo = malloc(sizeof *nuevo); //Defino el nuevo nodo
	nuevo->dato=lb; //Asigno el dato al nuevo nodo
	nuevo->ps=(*l); //lo pongo al principio de la lista
	*l=nuevo; //redefinimos el comienzo de la lista
}

//procedimiento para recorrer la lista y ver cuantas veces aparece el numero
void cuantasveces(struct lista *l,int numero){
	int cantidad=0;
	if(l==0){
		printf("La lista esta vacia");
	}
	else{
	//Si la lista no esta vacia la recorro y comparo el valor
	while(l!=0){
		if (l->dato==numero) {
			cantidad=cantidad+1;
		}
		l=l->ps; //se mueve al siguiente nodo (si existe)
	}
	printf("El numero aparece %d veces\n", cantidad);
	_getch();
	}
}
//procedimiento principal

int main(){
	//Declaro variable del dato
	int valor;
	int resp;
	//Declaro variable de la lista y la hago nil
	struct lista *lis=0;
	
	//llama al procedimiento de inicializar la lista
	crear(&lis);
	
	printf("Desea ingresar un valor: (1/0)\n");
	scanf("%d",&resp);
	
		while(resp==1){
				//pido que ingrese el valor
				printf("Ingrese el valor:\n");
				scanf("%d",&valor);
				//Inserta el dato en la lista
				insertar(&lis,valor);
				printf("Desea ingresar otro valor: (1/0)\n");
				scanf("%d",&resp);
		}
	//muestra los datos de la lista
	printf("Ingrese el numero a verificar las veces que esta en la lista:\n");
	scanf("%d",&valor);
	cuantasveces(lis,valor);
	return 0;
}

