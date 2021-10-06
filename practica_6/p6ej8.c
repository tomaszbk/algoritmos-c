// Aplicando Recursión en estructura de Arreglos
// a) Sumar los elementos de un vector.
// b) Contar la cantidad de elementos múltiplos de 3 que existen en un vector
// c) Dado un vector de números enteros, escribir un planteo recursivo para determinar 
// cuántos elementos pares ocupan posiciones impares (de izquierda a derecha)

#include <stdio.h>
int size = 11;
int vector[11];
int z = 0;
int j =0;
int length = 11;

int sumar(int x[]){
    z += x[j];
    j +=1;
    if(j <= length-1){
        sumar(x);
        return z;
    }
}

int multidos(int x[],int i){
    if(i > size -1){
        return 0;
    }
    if(x[i] % 2 == 0){
        return x[i] + multidos(x,i+1);
    }
    return multidos(x,i+1);
}

int main()
{
    for(int i = 0; i<11; i++){
        vector[i] = i + 1;
    }
    // printf("%d",sumar(vector));
    printf("%d", multidos(vector,0));
    return 0;
}