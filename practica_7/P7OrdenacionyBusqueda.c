/* Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
Es posible que el codigo generado no sea completamente correcto. Si encuentra
errores por favor reportelos en el foro (http://pseint.sourceforge.net). */

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define cant_elem 5

// Declaraciones adelantadas de las funciones
void ordena_int(int v[], int dim, char sentido, int metodo);
void ver_ord(int v[], int dim);
void cargarv(int v[], int dim);
int buscarelemento(int v[], int ele);

void ordena_int(int v[], int dim, char sentido,int metodo) {
	int aux;
	bool debo_intercambiar;
	int i;
	int n;
	int h;
	int j;
	int k;
	switch (metodo) {
		case 1:
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
		break;
		/* metodo dicotomico  (solo ordena ascendente) Tarea: ver como ordena en ambos sentidos tambien */ 
		case 2:
			i = 0;
			n = dim-1;
			debo_intercambiar = true;
			while (((i<n) && (debo_intercambiar))) {
				debo_intercambiar = false;
				for (j=1;j<=n-i;j+=1) {
					if (v[j-1]>v[j]) {
						aux = v[j-1];
						v[j-1] = v[j];
						v[j] = aux;
						debo_intercambiar = true;
						/* ver_ord(V,dim); //llamo a procedimiento para ver como va quedando el vector  */
					}
				}
				i = i+1;
			}
			break;
		/* metodo insercion  (solo ordena ascendente) Tarea: ver como ordena en ambos sentidos tambien */ 
		case 3:
			n = dim-1;
			for (k=2;k<=n;k+=1) {
				debo_intercambiar = false;
				aux = v[k-1];
				h = k;
				while (((!debo_intercambiar) && (h>1))) {
					if ((v[h-2]>aux)) {
						v[h-1] = v[h-2];
						h = h-1;
					} else {
						debo_intercambiar = true;
					}
				}
				v[h-1] = aux;
				/* llamo a procedimiento para ver como va quedando el vector  */
				ver_ord(v,dim);
			}
			break;
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
/* Procedimiento para buscar un elemento */
int buscarelemento(int v[], int ele) {
	int busca;
	int i;
	int pos;
	pos = 0;
	i = 1;
	while (((i<=ele) && (pos==0))) {
		if ((v[i-1]==ele)) {
			pos = i;
		} else {
			i = i+1;
		}
		busca = pos;
	}
	return busca;
}
/* Programa principal  */
int main() {
	int i;
	char opcion[1];
	int v[cant_elem-1];
	int elemento;
	printf("Cargar el vector con datos\n");
	/* llama al procedimiento para cargar el vector  */
	cargarv(v,cant_elem);
	printf("Como quiere ordenar el vector D:Descendente o A:Ascendente?\n");
	scanf("%s",opcion);
	/* llama al  procedimiento para ordenar el vector  */
	ordena_int(v,cant_elem,opcion,2);
	/* muestra el vector en forma ordenada */
	ver_ord(v,cant_elem);
	
	/*Busqueda*/
	printf("Buscar un elemento en el vector\n");
	printf("Ingrese el valor del elemento a buscar\n");
	scanf("%i",&elemento);
	if (buscarelemento(v,elemento)>0) {
		printf("El elemento existe\n");
	}
	return 0;
}

