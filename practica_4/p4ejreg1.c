#include <stdio.h>
// Un hotel tiene 100 habitaciones de distintos comodidades, la información la manejan con:
// Nro. Habitación, piso, tipo, precioXdia, confort, estado
// Se quiere realizar las siguientes operaciones:
// a) Buscar habitaciones disponibles y listar sus datos
// b) Imprimir el estado de las habitaciones, ordenadas por tipo
// c) Liquidar una habitación, ingresando la cantidad de días que estuvo ocupada

struct room
{
    int numhab;
    int piso;
    char tipo[10];
    int preciodia;
    int confort;
    int estado;
};

struct room vector[100];
int x = 1;
int i =0;
struct room room1; //?

int main(){
    while (x != 0)
    {
        printf("\ningrese num hab ");
        scanf("%d", &x);
        if (x != 0)
        {
           vector[i].numhab = x;
           printf("\ningrese piso ");
           scanf("%d", &x);
           vector[i].piso = x;

           printf("\ningrese preciodia ");
           scanf("%d", &x);
           vector[i].preciodia = x;

           printf("\ningrese estado ");
           scanf("%d", &x);
           vector[i].estado = x;
           x =1;
        }    
    }
    for (int j = 0; j < 100; j++)
    {
        if(vector[j].estado == 0){
            printf("\nLa habitacion %d esta disponible! ", vector[j].numhab);
            printf("\nprecio: %d", vector[j].preciodia);
        }
    }
}