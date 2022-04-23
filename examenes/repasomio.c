#include <stdio.h>
//restaurante 50 mesas
//c/vez q se ocupa mesa, registrar nombre apellido, dni de un
// cliente y anotar cantidad de clientes por esa mesa
//al llegar, se asigna mesa, se cobra cubierto y 
//se agrega lo gastado
//se imprime el ticket con el total gastado y se libera mesa
//pueden no haber mesas libres
//cndo termina dia: total de ganancias al restoran
//ganancias totales por mesa y porcentaje que representa sobre total
increible
int gasto_total = 0;


struct mesa{
    int estado;
    char nombre[10];
    char apellido[10];
    int dni;
    int gasto_temp; //cubiertos valen 20$
    int gasto_tot;
};

struct mesa mesas[50];

int asignarmesa(){
    int r;
    int i = 0;
    for(i; i < 50; i++){
        if(mesas[i].estado == 0){
            break;
        }
    }
    if(i == 50 && mesas[49].estado == 1){
        printf("no hay mesas disponibles");
        return 0;
        }
    printf("\nla mesa %d esta disponible", i );
    mesas[i].estado = 1;
    printf("\ningrese nombre \n");
    scanf("%s", &mesas[i].nombre);
    printf("\ningrese apellido \n");
    scanf("%s", mesas[i].apellido);
    printf("\ningrese dni \n");
    scanf("%d", &mesas[i].dni);
    printf("\ncuanto desea gastar?");
    scanf("%d", &r);
    mesas[i].gasto_temp += r;
    mesas[i].gasto_tot += mesas[i].gasto_temp;
    gasto_total += mesas[i].gasto_temp;
    return 0;
}

int ticket(int i){
    printf("\nfactura!\n");
    printf("\nmesa n %d", i);
    printf("\nnombre: %s, apellido: %s, dni:%d", mesas[i].nombre,mesas[i].apellido,mesas[i].dni);
    printf("\ntotal a pagar: %d", mesas[i].gasto_temp);
    mesas[i].gasto_temp = 20;
    printf("\nmuchas gracias!");
    mesas[i].estado = 0;
    return 0;
}
int fin(){
    printf("\ntermino el dia. total ganado por mesa y total = \n");
    printf("total: %d ", gasto_total);
    for(int j = 0; j<50; j++){
        printf("\nmesa %d", j);
        printf("\n%d", (mesas[j].gasto_tot * 100) / gasto_total);
    }
    printf("fin");
}


int main(){
    int x = 1;
    for(int i = 0; i < 50; i++){
        mesas[i].estado = 0;
        mesas[i].gasto_temp = 20;
        mesas[i].gasto_tot = 0;
    }

    while(x != 0){
        int m = 0;
        printf("\noperacion? (0-terminar, 1-asignarmesa, 2-ticket y fin mesa\n");
        scanf("%d", &x);
        while(x > 4 && x < -1){
            scanf("%d", &x);
        }
    
    switch(x){
        case 0:{
            fin();
            break;
        }
        case 1:{
            asignarmesa();}
            break;
        case 2:{
            printf("\nlas mesas ocupadas son: \n");
            for(int j = 0; j<50; j++){
                if(mesas[j].estado == 1){
                    printf("%d", j);
                }
            }
            printf("\nelija a q mesa cobrar ");
            scanf("%d", &m);
            ticket(m);
             break;
        }
     }
    }
    return 0;
}

//funciones:
//-ocupar mesa
//-hacer pedido
//-imprimir ticket y liberar mesa
//termina dia; tot ganancias

//var:
//gasto tot
//50 mesas, en cada mesa:
// estado (0 o 1)
// nomb, apell, dni,
// gasto temp. y gasto tot,
// y estado (0 o 1)