#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int num, *puntero;
int main(){
printf("Ejemplo de uso de punteros\n");
printf("Ingrese un numero: ");
scanf("%d", &num);
//Lectura normal de un valor
system("cls");
puntero=&num;
//Asigno a la variable puntero la dirección de num. Nótese el
//uso del ampersand
printf("Ingreso: %d\nLa variable puntero contiene: %d", num, *puntero); //Muestro el contenido
_getch();
//de num y del puntero
system("cls");
//El puntero se accede con asterisco (*)
*puntero=40;
//Modificamos la información de num a través del puntero a su
//dirección de memoria
printf("Ahora la variable 'num' tiene valor: %d", num); //Verificamos que efectivamente se
_getch();
//modificó el valor
system("cls");
return 0;
}

