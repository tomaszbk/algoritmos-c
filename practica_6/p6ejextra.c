//funcion promedio de listas

#include <stdio.h>
//#include <string.h>
float vector[10];

float promedio(float x[], int index, int *suma, float *promedy, int *arriba){
    if(index >9){
        *promedy = *suma/10.0;
        return 0;
    }
    *suma += x[index];
    promedio(x,index+1,suma,promedy, arriba);
    if(x[index] >= *promedy){
        *arriba += 1;
    }
    return *promedy;
}


int main()
{
    int suma = 0;
    float promedy = 0;
    int arriba = 0;
    for(int j=0;j<10;j++){
        vector[j] = j+1; 
    }
    printf("%f", promedio(vector, 0, &suma, &promedy, &arriba));
    return 0;
}