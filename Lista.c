#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Persona{
	char nombre[15];
	char apellido[15];
	int anioNacimiento;
};

//Defino la lista (nótese que es en el mismo nodo)
//Dato de la lista
//Puntero siguiente, esto es lo que nos permite operar
//el registro como lista
struct Lista{
          struct Persona dato;
          struct Lista *ps;

};


void insertar(struct Lista **l, struct Persona p);
void inicializarLista (struct Lista **l);
void cargarPersona(struct Persona *p);
void listarPersonas(struct Lista *l);

void inicializarLista (struct Lista **l){
	*l=0; //Lista en NIL
}

void insertar(struct Lista **l,struct Persona p){ //Envío por referencia la lista y por
	//copia un registro
	struct Lista *aux; //Defino el aux para moverme por l
	struct Lista *nuevo = malloc(sizeof(struct Lista)); //Defino el nuevo nodo
	nuevo->dato=p;
	//Asigno el dato al nuevo nodo, en este caso una Persona
	nuevo->ps=0;
	//El puntero siguiente es nil
	if (*l==0){
		//Si la lista está vacía, inserto al principio
		*l=nuevo;
	}
	else{
		//Sino, me muevo hasta el final y lo inserto
		aux=*l;
		//Asigno un aux para no modificar a la cabeza l
		while(aux->ps!=0){ //Recorro aux hasta el final de la lista
		aux=aux->ps;
		}
		aux->ps=nuevo;
		//Realizo la inserción
	}
}

void cargarPersona(struct Persona *p){
	printf("Ingrese nombre: ");
	scanf("%s", p->nombre); //String, sin ampersand
	
	printf("Ingrese apellido: ");
	scanf("%s", p->apellido); //String, sin ampersand
	
	
	printf("Ingrese año nacimiento: ");
	scanf("%d", &p->anioNacimiento);

}


void listarPersonas(struct Lista *l){
	if(l==0){
	printf("La lista esta vacia");
	}
	else{
	//Si la lista no está vacía, recorro cada producto
	while(l!=0){
	printf("Apellido: %s\n", l->dato.apellido);
	printf("Nombre: %s\n", l->dato.nombre);
	printf("Año Nacimiento:	%d\n", l->dato.anioNacimiento);
	printf("-------------------\n");
	_getch();
	l=l->ps;
	}
	}
}


int main(){
	//Declaro variable del dato
	struct Persona per;
	//Declaro variable de la lista y la hago nil
	struct Lista *lis=0;
	
	//llama al procedimiento de inicializar la lista
	inicializarLista(&lis);
	
	//llama al procedimiento que carga los datos de la persona en la estrcutura
	cargarPersona(&per);
	
	//Inserta la persona en la lista
	insertar(&lis,per);
	
	//muestra los datos de la lista
	listarPersonas(lis);
	return 0;
}





