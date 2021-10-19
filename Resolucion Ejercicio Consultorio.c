/*
===========================================================================================================

                                                    ENUNCIADO
                                                    =========

En un consultorio medico, se atienden personas de distintas obras sociales.
Al momento de registrar un turno se solicita:
Nombre, Apellido, DNI, Obra Social.
Se desea que se realice un programa que resuelva:
    1- Registrar turno para un paciente.
    2- Atender a un paciente en el consultorio.
    3- Listar a todos los pacientes que poseen obra social Ioma. 
    4- Generar una pila con todos los pacientes que no poseen obra social. 
    5- Generar una lista con los pacientes que tienen obra social Osde y contar recursivamente cuantos son.
===========================================================================================================*/

#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

//Definicion del Registro del paciente
struct Paciente {
    char nombre[30];
    char apellido[30];
    int dni;
    char obra[30];
};

//Definicion de la Lista a recorrer recursivamente
struct Lista {
    struct Paciente dato;
    struct Lista *psig;
};

//Definicion de la Pila de los pacientes sin obra social
struct Pila {
    struct Paciente dato;
    struct Pila *psig;
};

//Definicion de la cola de pacientes a atender
struct NodoCola {
    struct Paciente dato;
    struct NodoCola *psig;
};

struct Cola {
    struct NodoCola *pinicial;
    struct NodoCola *pfinal;
};

void encolar(struct Cola *co, struct Paciente reg );

void desencolar(struct Cola *co, struct Paciente *reg);

void esColaVacia(struct Cola *co, int *valor);

void apilar(struct Pila **pi, struct Paciente reg);

void desapilar(struct Pila **pi, struct Paciente *reg);

void esPilaVacia(struct Pila **pi, int *valor);

void insertarFinal(struct Lista **li, struct Paciente reg);

void registrarTurno(struct Cola *cola);

void atenderPaciente(struct Cola *cola);

void listarPorObra(struct Cola *cola);

void generarPila(struct Pila **pila, struct Cola *cola);

void generarLista(struct Lista **lista, struct Cola *cola);

void contarRecursivo(struct Lista *lista, int *total);

void imprimirLista(struct Lista **lista);

void imprimirPila(struct Pila **pila);


int main(void){
struct Cola c;
struct Pila *p=0; //Inicializacion de la pila
struct Lista *l=0; //Inicializacion de la lista
int opcion = 0;
int cantidad, vacio;

//Inicializacion de la cola
c.pinicial = 0;
c.pfinal = 0;

_clrscr();

    while(opcion != 8){
        printf("MENU DE OPCIONES\n");
        printf("==== == =========\n\n");
        printf("1-Registrar turno para un paciente\n");
        printf("2-Atender un paciente\n");
        printf("3-Listar los pacientes con obra social Ioma\n");
        printf("4-Generar una pila con los pacientes sin obra social\n");
        printf("5-Generar una lista con los pacientes de obra social Osde\n");
        printf("6-Imprimir Lista\n");
        printf("7-Imprimir Pila\n");
        printf("8-Salir\n\n");
        printf("OPCION: ");
        scanf("%d", &opcion);
        _clrscr();

        switch(opcion){
            case 1:registrarTurno(&c);
                   break;
            case 2:esColaVacia(&c, &vacio);
                   if(vacio){
                       printf("No hay pacientes para atender...");
                       _getch();
                       _clrscr();
                   } else {
                       atenderPaciente(&c);
                   }
                   break;
            case 3:listarPorObra(&c);
                   break;
            case 4:generarPila(&p, &c);
                   break;
            case 5:generarLista(&l, &c);
                   contarRecursivo(l, &cantidad);
                   printf("El total de pacientes agregados a la lista de obra social Osde es de %d", cantidad);
                   _getch();
                   _clrscr();
                   break;
            case 6:if(l == 0){
                        printf("La lista esta vacia...");
                        _getch();
                    } else {
                        imprimirLista(&l);
                    }
                    _clrscr();
                    break;
            case 7:if(p == 0){
                        printf("La pila esta vacia...");
                        _getch();
                    } else {
                        imprimirPila(&p);
                    }
                    _clrscr();
                    break;
            case 8:printf("Finalizando ejecucion...");
                   _getch();
                   _clrscr();
                   break;
            default:printf("Opcion ingresada incorrecta...");
                    _getch();
                   _clrscr();
                   break;                   
        }
    }
return 0;
}

void encolar(struct Cola *co, struct Paciente reg){
    struct NodoCola *nuevo = malloc(sizeof(struct NodoCola));

    nuevo->dato = reg;
    nuevo->psig = 0;

    if(co->pinicial == 0){
        co->pinicial = nuevo;
    } else {
        co->pfinal->psig = nuevo;
    }

    co->pfinal = nuevo;
}

void desencolar(struct Cola *co, struct Paciente *reg ){
    struct NodoCola *aux;

    aux=co->pinicial;
    *reg = aux->dato;

    co->pinicial = aux->psig;

    if(aux->psig == 0){
        co->pfinal = 0;
    }

    free(aux);
}

void esColaVacia(struct Cola *co, int *valor){
    if(co->pinicial == 0){
        *valor = 1;
    } else {
        *valor = 0;
    }
}

void apilar(struct Pila **pi, struct Paciente reg){
    struct Pila *nuevo=malloc(sizeof(struct Pila));

    nuevo->dato=reg;
    nuevo->psig=*pi;

    *pi=nuevo;
}

void desapilar(struct Pila **pi, struct Paciente *reg){
    struct Pila *aux;

    aux=*pi;
    *reg=aux->dato;

    *pi=aux->psig;

    free(aux);
}

void esPilaVacia(struct Pila **pi, int *valor){
    if(*pi == 0){
        *valor = 1;
    } else {
        *valor = 0;
    }
}

void insertarFinal(struct Lista **li, struct Paciente reg){
    struct Lista *nuevo=malloc(sizeof(struct Lista));
    struct Lista *aux;

    nuevo->dato=reg;
    nuevo->psig=0;
    aux=*li;

    if(*li == 0){
        *li = nuevo;
    } else{
        while(aux->psig!=0){
            aux=aux->psig;
        }
        aux->psig=nuevo;
    }
}

void registrarTurno(struct Cola *cola){
    struct Paciente pac;

    printf("Ingrese el nombre del paciente: ");
    scanf("%s", pac.nombre);
    printf("\n\n");
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", pac.apellido);
    printf("\n\n");
    printf("Ingrese el dni del paciente: ");
    scanf("%d", &pac.dni);
    printf("\n\n");
    printf("Ingrese la obra del paciente: ");
    scanf("%s", pac.obra);
    encolar(cola, pac);
    _clrscr();

}

void atenderPaciente(struct Cola *cola){
    struct Paciente pac;

    desencolar(cola, &pac);

    printf("IMPRESION DE DATOS DEL PACIENTE\n");
    printf("========= == ===== === ========\n\n");
    printf("NOMBRE: %s\n", pac.nombre);
    printf("APELLIDO: %s\n", pac.apellido);
    printf("DNI: %d\n", pac.dni);
    printf("OBRA SOCIAL: %s\n\n", pac.obra);
    _getch();
    _clrscr();

}

void listarPorObra(struct Cola *cola){
    struct Paciente pac;
    struct Cola cola2;

    cola2.pinicial=0;
    cola2.pfinal=0;

    while(cola->pinicial != 0){
        desencolar(cola, &pac);
        if(strcmp(pac.obra, "Ioma") == 0){
            printf("IMPRESION DE DATOS DEL PACIENTE\n");
            printf("========= == ===== === ========\n\n");
            printf("NOMBRE: %s\n", pac.nombre);
            printf("APELLIDO: %s\n", pac.apellido);
            printf("DNI: %d\n", pac.dni);
            printf("OBRA SOCIAL: %s\n\n", pac.obra);
            _getch();
        }
        encolar(&cola2, pac);
    }

    cola->pinicial = cola2.pinicial;
    cola->pfinal = cola2.pfinal;
	_clrscr();
}

void generarPila(struct Pila **pila, struct Cola *cola){
    struct Paciente pac;
    struct Cola cola2;

    cola2.pinicial=0;
    cola2.pfinal=0;

    while(cola->pinicial != 0){
        desencolar(cola, &pac);
        if(strcmp(pac.obra, "ninguna") == 0){
            apilar(pila, pac);
        }
        encolar(&cola2, pac);
    }

    cola->pinicial = cola2.pinicial;
    cola->pfinal = cola2.pfinal;
}

void imprimirPila(struct Pila **pila){
    struct Paciente pac;

    while(*pila != 0){
        desapilar(pila, &pac);
        printf("IMPRESION DE DATOS DEL PACIENTE\n");
        printf("========= == ===== === ========\n\n");
        printf("NOMBRE: %s\n", pac.nombre);
        printf("APELLIDO: %s\n", pac.apellido);
        printf("DNI: %d\n", pac.dni);
        printf("OBRA SOCIAL: %s\n\n", pac.obra);
        _getch();
    }
}

void generarLista(struct Lista **lista, struct Cola *cola){
    struct Paciente pac;
    struct Cola cola2;

    cola2.pinicial=0;
    cola2.pfinal=0;

    while(cola->pinicial != 0){
        desencolar(cola, &pac);
        if(strcmp(pac.obra, "Osde") == 0){
            insertarFinal(lista, pac);
        }
        encolar(&cola2, pac);
    }

    cola->pinicial = cola2.pinicial;
    cola->pfinal = cola2.pfinal;    
}

void imprimirLista(struct Lista **lista){
    struct Lista *aux;

    aux = *lista;

    while(aux != 0){
        printf("IMPRESION DE DATOS DEL PACIENTE\n");
        printf("========= == ===== === ========\n\n");
        printf("NOMBRE: %s\n", aux->dato.nombre);
        printf("APELLIDO: %s\n", aux->dato.apellido);
        printf("DNI: %d\n", aux->dato.dni);
        printf("OBRA SOCIAL: %s\n\n", aux->dato.obra);
        aux = aux->psig;
        _getch();
    }
}

void contarRecursivo(struct Lista *lista, int *total){
    if(lista == 0){
        *total = 0;
    } else {
        contarRecursivo(lista->psig, total);
        *total = *total + 1;
    }
}






