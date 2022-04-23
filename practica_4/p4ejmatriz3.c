//Se cargan 2 matrices con números reales para realizar las siguientes operaciones:
// a) Cargar en un vector la suma de cada columna de la primera matriz.
// b) Cargar un vector con el promedio de cada fila de la segunda matriz.
// c) Calcular el promedio de los valores de ambas matrices.
#include <stdio.h>
int matriz[3][4];
int matriz2[3][4];
int vecsuma[4];
int vectorpromedio[3];
int suma=0;
int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = 2;
            matriz2[i][j] = 4;
            printf("%d", matriz[i][j]);
            suma += matriz2[i][j] = 4;
        }
        vectorpromedio[i] = suma/4; 
        suma = 0;
    }

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            suma += matriz[i][j] ;
        }
        vecsuma[j] = suma;
        suma = 0;
    }
    
    printf("%d", (matriz[0][0] + matriz2[0][0])/2 );
     printf("\n%d", vecsuma[0]);
     printf("\n%d", vectorpromedio[0]);

    return 0;
}