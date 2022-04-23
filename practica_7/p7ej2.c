//Implementar como procedimientos los algoritmos de ordenación por selección y burbuja,
// de modo que uno de ellos trabaje en sentido ascendente y el otro descendente. 
//Utilizarlos en un programa que lea un vector de N posiciones y mostrarlo ordenado en ambos sentidos.

#include <stdio.h>
//#include <string.h>
int len= 5;

int ordenar_burbuja(int x[]){ //ascendente
    int aux;
    int ordenado = 0;

    for(int j=0;j<len ;j++){
        ordenado = 1;
        for(int i =0;i<len-1 - j;i++){
            
            if(x[i]>x[i+1]){ //cambiar desigual para ascen/descen
                aux = x[i+1];
                x[i+1] = x[i];
                x[i] = aux;
                ordenado = 0;
            }
     
        }
        if(ordenado == 1){          //imprime vector
                for(int r =0;r<len;r++){
                    printf("%d", x[r]);
                    
                    }
            return 0;
            }
    }
    for(int r =0;r<len;r++){   //imprime vector
        printf("%d", x[r]);
        }
}



int ordenar_seleccion(int x[] ){ //descendente
    int aux;
    for(int j = 0; j<len; j++){
        for(int i=0 + j;i<len -1; i++){
            if(x[j] < x[i+1]){
                aux = x[j];
                x[j] = x[i+1];
                x[i+1] = aux;
            }
        }
    }
    for(int r =0;r<len;r++){   //imprime vector
        printf("%d", x[r]);
        }
}


int main()
{
    int vector[5] = {6,1,4,9,7};
    // ordenar_burbuja(vector);
    ordenar_seleccion(vector);
    return 0;
}