#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h>



//impresion de un vector
void imprimirVector(int vect[], int largo){
	int i;
	
	printf("Vector ordenado:\n");
	for (i = 0; i < largo; i++){
		
		printf("%d\n", vect[i]);
	}
	getch();
}
//--------------------------------------------------------------
//metodo directo
void directo(int vec[], int sentido, int cantidad){
	//variables
	int i,j,aux;
	bool Lsentido;
	
	for (i = 0; i < cantidad; i++){
			
		for (j = i+1; j < cantidad; j++){
					
			//determinacion de sentido
			if (sentido == 1){
					
				Lsentido = (vec[i] > vec[j]);
			}else{
					
				Lsentido = (vec[i] < vec[j]);
			}
			//intecambio
			if (Lsentido){
						
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
						
			}
		}
	}
	//mostrar vector ordenado
	imprimirVector(vec, cantidad);
	
}

//--------------------------------------------------------------------
//metodo por burbuja
void burbuja(int vec[], int sentido, int cantidad){
	//variables	
	int i,j,aux;
	bool Lsentido, sigue;
	
	sigue = true;
	i = 0;
	while(i < cantidad-1 && sigue == true){
		

		//imprimirVector(vecB);
		sigue = false;
		for(j = 0; j < cantidad-i-1; j++){
			//intercambio
					//determinacion de sentido
			if (sentido == 1){
						
				Lsentido = (vec[j] > vec[j+1]);
			}else{
						
				Lsentido = (vec[j] < vec[j+1]);
			}
			if (Lsentido){
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
				sigue = true;
			}
			
		}
		i++;
	}
	//mostrar vector ordenado
	imprimirVector(vec, cantidad);	
}
//--------------------------------------------------------------------
//metodo por insercion
void insercion(int vec[], int sentido, int cantidad){
	//variables
	int i,j,aux;
	bool Lsentido, encontre;
	
	for (i = 1; i < cantidad; i++){
		
		j = i;
		aux = vec[i];
		encontre = false;
		while(j > 0 && !encontre){
			//determinacion de sentido
			if (sentido == 1){
					
				Lsentido = (vec[j-1] > aux);
			}else{
					
				Lsentido = (vec[j-1] < aux);
			}
			//intercambio
			if (Lsentido){
				vec[j] = vec[j-1];
				j--;
				
			}else{
				encontre = true;
			}		
		}
		vec[j] = aux;
	}
	//mostrar vector ordenado
	imprimirVector(vec, cantidad);	
}
//---------------------------------------------------------------------
//menu
void menu(int vector[], int cant){
	//variables
	int metodo, sentido;
	
	//menu seleccion de metodo de ordenamiento
	printf("\n\nSeleccione un metodo de ordenamiento \n");
	printf("1.Metodo directo \n");
	printf("2.Metodo por burbuja \n");
	printf("3.Metodo por insercion \n");
	printf("0.Salir \n");
	scanf("%d", &metodo);
	
	//menu de seleccion de direccion
	if (metodo > 0 && metodo <= 3){
	
		printf("Seleccione una sentido para ordenar \n");
		printf("1.Ascendente \n");
		printf("2.Descendente \n");
		scanf("%d", &sentido);
	}

	//metodos
	switch(metodo){
		//salir
		case 0:
			exit(0);
			break;
		//metodo directo
		case 1:	
			directo(vector, sentido, cant);
			break;
			
		case 2:	
			burbuja(vector, sentido, cant);
			break;
		
		case 3:
			insercion(vector, sentido, cant);
			break;
	}
}

//-------------------------------------------
int main(){
	
	//variables
	int cant = 5;
	int vector[cant];
	int i;
	
	printf("introducir elementos \n");
	
	//cargar vector
	for (i = 0; i < cant; i++){
		
		printf("elemento %d:", i);
		scanf("%d", &vector[i]);	
	}
	
	while (true){
		//abrimos el menu
		menu(vector, cant);
		
	}
	
}

