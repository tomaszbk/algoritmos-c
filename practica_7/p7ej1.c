// 1. Realizar un algoritmo que permita buscar en un vector de 1500 posiciones la ocurrencia de una clave 
// de tipo carácter introducida por el usuario

#include <stdio.h>
//#include <string.h>
int length = 1000;
int vector[1500];
int clave = 8;


int ocurrencia(int x[]){
for(int i =0; i<length;i++){
    if(x[i] == clave){
        return i;
    }
}
return -1;
}


int main()
{
    for(int i =0; i<length;i++){
        vector[i] = i;
    }

    printf("%d", ocurrencia(vector));
    return 0;
}