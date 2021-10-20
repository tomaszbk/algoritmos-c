/* Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
Es posible que el codigo generado no sea completamente correcto. Si encuentra
errores por favor reportelos en el foro (http://pseint.sourceforge.net). */

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define cant_elem 5

// Declaraciones adelantadas de las funciones
void ordena_int(int v[], int dim, char sentido);
void ver_ord(int v[], int dim);
void cargarv(int v[], int dim);

void ordena_int(int v[], int dim, char sentido) {
	int aux;
	bool debo_intercambiar;
	int i;
	int n;
	for (n=0;n<dim-1;n+=1) {
		for (i=(n+1);i<dim;i+=1) {

			if (sentido = "D") {
				debo_intercambiar = (v[n]<v[i]);
			}
			if (sentido = "A") {
				debo_intercambiar = (v[n]>v[i]);
			}
			if (debo_intercambiar) {
				//ver_ord(v,dim); //muestro el vector antes del ordenamiento
				aux=v[n];
				v[n]=v[i];
				v[i]=aux;
				ver_ord(v,dim); //muestro el vector despues del ordenamiento
			}
		}
	}
}

void ver_ord(int v[], int dim) {
	int i;
	printf("Impresión del Vector ordenado\n");
	for (i=0;i<dim;i+=1) {
		printf("Vector(%i):=%d\n",i,v[i]);
	}
}

/* Procedimiento para cargar el vector  */
void cargarv(int v[], int dim) {
	int i;
	printf("Carga de los datos del Vector\n");
	for (i=0;i<dim;i+=1) {
		printf("Vector(%i):=",i);
		scanf("%d",&v[i]);
		printf("Valor =%i\n",v[i]);
	}
}

/* Programa principal  */
int main() {
	int i;
	char opcion[1];
	int v[cant_elem-1];
	printf("Cargar el vector con datos\n");
	/* llama al procedimiento para cargar el vector  */
	cargarv(v,cant_elem);
	printf("Como quiere ordenar el vector D:Descendente o A:Ascendente?\n");
	scanf("%s",opcion);
	/* llama al  procedimiento para ordenar el vector  */
	ordena_int(v,cant_elem,opcion);
	/* muestra el vector en forma ordenada */
	ver_ord(v,cant_elem);
	return 0;
}

