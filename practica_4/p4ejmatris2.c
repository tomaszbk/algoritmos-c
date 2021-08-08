//2. Se desea cargar 2 matrices con números enteros y hacer las siguientes operaciones:
// a) Multiplicar los valores de las dos matrices.
// b) Sumar posición por posición de las dos matrices y colocarlos en un matriz resultado.
// c) Comparar posición por posición los valores de las dos matrices y colocar en un matriz
// resultado el menor de ellos, en la misma posición.

#include <stdio.h>

int matriz[3][4];
int matriz2[3][4];
int matriz3[3][4];
int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = 2;
            matriz2[i][j] = 4;
            printf("%d", matriz[i][j]);
        }
    }
printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // matriz[i][j] = matriz[i][j] * matriz2[i][j];
            // printf("%d", matriz[i][j]);
            matriz3[i][j]= matriz[i][j] + matriz2[i][j];
            printf("%d", matriz3[i][j]);
        }
    }
    
    return 0;
}
