#include <stdio.h>
#include <conio.h>
void modificarPuntero(int *p);
int main(){
int x=5, *punteroNum;
//Declaro un entero y un puntero a entero
punteroNum=&x;
//Apunto el puntero a la variable entera.
printf("Valor del puntero: %d\n", *punteroNum); //El puntero muestra 5
_getch();
modificarPuntero(punteroNum); //Modifico el valor de x a través del puntero
printf("Valor del puntero modificado: %d", *punteroNum);
_getch();
return 0;
}
void modificarPuntero(int *p){
          *p=0;
}

