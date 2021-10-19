#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//estructura del libro
struct libro{
	char nombre[20];
	int codigo;
	char edit[20];
	char autor[20];
	int precio;
	int stock;
};

//Defino la lista (notese que es en el mismo nodo)
//Dato de la lista
//Puntero siguiente, esto es lo que nos permite operar
//el registro como lista
struct lista{
          struct libro dato;
          struct lista *ps;
};

void imprimirA(struct lista *l);
void insertar(struct lista **l, struct libro lb);
void crear (struct lista **l);
void simular(struct lista **l);

//procedimiento que imprime los libros sin stock
void imprimirA(struct lista *l) //imprime los libros con stock
{
	struct lista *aux;
	aux=l;
	while(aux!=0){
		if (aux->dato.stock==0)
		{
			printf("Nombre: %s\n", aux->dato.nombre);
			printf("Editorial: %s\n", aux->dato.edit);
			_getch();
		}
	aux=aux->ps;
	}
}

void crear (struct lista **l){
	*l=0; //Lista en NIL
}

void insertar(struct lista **l,struct libro lb){ //Envio por referencia la lista y por
	struct lista *nuevo = malloc(sizeof *nuevo); //Defino el nuevo nodo
	nuevo->dato=lb; //Asigno el dato al nuevo nodo
	nuevo->ps=(*l); //lo pongo al principio de la lista
	*l=nuevo; //redefinimos el comienzo de la lista
}

void simular(struct lista **l)
{//procedimiento carga el stock si es 0 o carga un nuevo libro si ya exitia.
	//declaracion de variables del procedimiento
	struct lista *actual=0;
	struct libro reg;
	int resp;
	char name[20];
	int stocknue;
	
	printf("Desea reponer los libros: (1/0)\n");
	scanf("%d",&resp);
	
	while(resp==1){
		printf("Ingrese el nombre del libro\n");
		scanf("%s",name);
		actual=l;
		while (actual!=0 && strcmp(name,actual->dato.nombre)!=0)
		{
			actual=actual->ps;
		}
		if (actual!=0)
		{
			printf("Ingrese el stock comprado del libro\n");
			scanf("%d",&stocknue);
			actual->dato.stock=	actual->dato.stock+stocknue;
		}
			else
			{
				printf("Ingrese el nombre del libro\n");
				scanf("%s",reg.nombre);
				printf("Ingrese el codigo del libro\n");
				scanf("%d",&reg.codigo);
				printf("Ingrese el autor del libro\n");
				scanf("%s",reg.autor);
				printf("Ingrese el precio del libro\n");
				scanf("%d",&reg.precio);
				printf("Ingrese la editorial del libro\n");
				scanf("%s",reg.edit);
				printf("Ingrese el stock del libro\n");
				scanf("%d",&reg.stock);
				//llama al procedimiento insertar con los datos cargados en el registro
				insertar(&l,reg);
			}
			printf("Desea reponer mas libros (1/0)\n");
			scanf("%d",&resp);
		}
	}

int main(){
	//Declaro variable del dato
	struct libro reg;
	//Declaro variable de la lista y la hago nil
	struct lista *pi=0;

	int resp;
	
	//llama al procedimiento de inicializar la lista
	//crear(&pi);
	
	printf("Desea ingresar libros: (1/0)\n");
	scanf("%d",&resp);

	while(resp==1)
	{
			printf("Ingrese el nombre del libro\n");
			scanf("%s",reg.nombre);
			printf("Ingrese el codigo del libro\n");
			scanf("%d",&reg.codigo);
			printf("Ingrese el autor del libro\n");
			scanf("%s",reg.autor);
			printf("Ingrese el precio del libro\n");
			scanf("%d",&reg.precio);
			printf("Ingrese la editorial del libro\n");
			scanf("%s",reg.edit);
			printf("Ingrese el stock del libro\n");
			scanf("%d",&reg.stock);
			//llama al procedimiento insertar con los datos cargados en el registro
			insertar(&pi,reg);
			printf("Desea ingresar mas libros (1/0)\n");
			scanf("%d",&resp);
	} //fin repetir mientras
	imprimirA(pi);
	simular(pi);
	return 0;
}





