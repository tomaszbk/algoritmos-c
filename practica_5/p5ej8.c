// Hacer un programa que imprima todos los números naturales primos menores que un 
// número dado. Recordar que los números naturales primos son los que sólo admiten 2 
// divisores: 1 y sí mismos, y que los divisores de un número distintos de él mismo son menores 
// que la mitad.
#include <stdio.h>

int primos(int x){
    int i = 2;
    while(i < x/2){
        if(x%i == 0){
            printf("no es primo");
            return 0;
        }
   i +=1;     
    }
    printf("es primo!");
    return 0;
}

int main()
{
    primos(101);
    return 0;
}

