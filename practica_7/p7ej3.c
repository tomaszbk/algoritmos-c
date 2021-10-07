//Se desea cargar una matriz de 14×50,ordenarla por una columna indicada, y luego imprimir la matriz resultado.
// La ordenación también debe realizarla un procedimiento
#include <stdio.h>
//#include <string.h>
int filas = 4;
int columnas = 50;

int ordenar(int x[][], int elec){
    int aux;
    for(int i = 0; i< filas; i++){
        if(x[i][elec] > x[i+1][elec]){
            for(int c = 0; c< columnas; c++){
                aux = x[i][c];
                x[i][c] = x[i+1][c];
                x[i+1][c] = aux;
        }
    }
}

int main()
{
    int ww = 2;
    int matriz[4][50];
    for(int fil = 0; fil< filas; fil++){
        for(int col = 0; col< columnas; col++){
            matriz[fil][col] = fil;
        }
    }
    for(int fil = 0; fil< filas; fil++){
        for(int col = 0; col< columnas; col++){
            printf("%d", matriz[fil][col]);
        }
    }

    ordenar(matriz, ww);
    return 0;
}