//Se desea cargar una matriz de 14×50,ordenarla por una columna indicada, y luego imprimir la matriz resultado.
// La ordenación también debe realizarla un procedimiento
#include <stdio.h>
//#include <string.h>
int filas = 4;
int columnas = 50;

int ordenar(int x[4][50], int elec){
    int aux;
    for(int j = 0; j< filas ; j++){
        for(int i = 0 + j; i< filas -1 ; i++){
            if(x[j][elec] < x[i+1][elec]){
                for(int c = 0; c< columnas; c++){
                    aux = x[j][c];
                    x[j][c] = x[i+1][c];
                    x[i+1][c] = aux;
                }
            }
        }
    }
}

int main()
{
    int ww = 2;
    int matriz[4][50];
    for(int fil = 0; fil< filas; fil++){    //poner valores a matriz
        for(int col = 0; col< columnas; col++){
            matriz[fil][col] = fil;
        }     
    }

    for(int fil = 0; fil< filas; fil++){    //imprimir matriz
        for(int col = 0; col< columnas; col++){
            printf("%d", matriz[fil][col]);
        }
        printf("\n");
    }
printf("\n");
    ordenar(matriz, ww);
    for(int fil = 0; fil< filas; fil++){
        for(int col = 0; col< columnas; col++){
            printf("%d", matriz[fil][col]);
        }
        printf("\n");
    }
    return 0;
}