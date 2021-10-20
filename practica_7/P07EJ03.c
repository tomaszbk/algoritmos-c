#include<stdio.h>
void carga(int *mat[14][50],int fila, int colum);
void orden(int *mat[14][50],int fila, int colum);
int matriz[14][50];
int f, c; i;j;k;
int main(){
	printf("\nIngrese de cuantas filas x cuantas columnas es la matriz: ");
	scanf("%i %i", &f, &c);
	carga(matriz,f,c);	//envio la matriz y la cant de filas y columnas como parametros
	orden(matriz,f,c);
		
	return 0;
}
void carga(int *mat[14][50],int fila, int colum){
	
	for(i=0;i<fila;i++){    //inicializo la matriz en cero
		for(j=0;j<colum;j++){
			mat[i][j]=0;
		}
	}
	
	for( i=0;i<fila;i++){
		for( j=0;j<colum;j++){
			printf("\nIngrese el elemento %i,%i: ",i+1,j+1);
			scanf("%i",&mat[i][j]);		
		}
	}
		printf("\n");
	for( i=0;i<fila;i++){
		for( j=0;j<colum;j++){
	printf("%i\t",mat[i][j]);
		}
		printf("\n");
	}
}
void orden(int *mat[14][50],int fila, int colum){
	int col, i=0;
	
	printf("\nIngrese el numero de columna por la cual quiere ordenar la matriz: ");
	scanf("%i",&col);
	int n=fila;
  	int ordenado=1;
  while ((i<(n-1)) && (ordenado==1)){
      ordenado=0;
      for ( j=0;j<(n-i-1);j++){
	  	if (mat[j][col-1]>mat[j+1][col-1]){
	      ordenado = 1;
	      for( k=0;k<colum;k++){
		  	int aux=mat[j][k];
	      	mat[j][k]=mat[j+1][k];
	      	mat[j+1][k]=aux;
		  }
	    }
	}
     i=i+1;
    }
    printf("\n___MATRIZ ORDENADADA___\n");
	for( i=0;i<fila;i++){
		for( j=0;j<colum;j++){
	printf("%i\t",mat[i][j]);
}printf("\n");}
}


