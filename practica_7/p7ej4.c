//Escribir un programa de consultas telefónicas.
// Leer un conjunto de datos de hasta 1000 nombres y números  telefónicos  que  vienen  dados aleatoriamente.
//Las  consultas  pueden  realizarse  por nombre o por número telefónico.
#include <stdio.h>
//#include <string.h>
struct listas{
    char nombre[10];
    int num;
};

struct listas lista[4];

int busqueda(struct x){ //por nombre
    int aux;
     for(int j =0;j<6;j++){
        for(int i =0;i<6;i++){
            if(x[i].nombre > x[i+1].nombre){              
                    aux = x[i].nombre;
                    x[i].nombre = x[i+1].nombre;
                    x[i+1].nombre = aux;
                    aux = x[i].num;
                    x[i].num = x[i+1].num;
                    x[i+1].num = aux;
                
            }
        }
    }
for(int r =0;r<6;r++){
    printf("\n%s ",x[r][0]);
    printf("\n%d ",x[r][1]);
    }
}

int main()
{


for(int j =0;j<4;j++){
    printf("\ningrese nombre ");
    scanf("%s", &lista[j].nombre);
    printf("\ningrese num ");
    scanf("%d", &lista[j].num);
}

for(int f =0;f<4;f++){
    printf("\n%s ", lista[f].nombre);
    printf("\n%d", lista[f].num);
}
    busqueda(lista);
    return 0;
}