#include <stdio.h>
// En una fabrica de motos se hay 20 modelos de motos diferentes, con código de 1 a 20. De las motos se tienen los siguientes datos:

// modelo, stock, stock_minimo y el precio. 

//Se requiere desarrollar un programa que simule la venta del dia,

// controlando y actualizando el stock por cada venta,

// imprimiendo una factura con código/modelo/ Cantidad vendida /Precio total. Si no existe stock imprimir un mensaje.

// Al finalizar el día se desea:

// a.        Realizar un procedimiento o funcion para calcular el Importe de la Venta total del dia

// b.        Imprimir código y cantidad vendida de  cada  modelo

// c.        Listado de todos los modelos a reponer, con stock menor a stock_minimo, con los siguientes datos de cada producto:
//      	 código,  cantidad a reponer(50 – stock), importe de reposición (cantidad a reponer * precio)

// d.        Importe total de reposición

struct moto{
    //la var codigo no la pongo porque es el index + 1
    char modelo[10];
    int stock;    //stock max es 50
    int stock_min;
    int precio;
    int cant_vendida;
};

int listado[2][3]; 
//columnas: codigo, cant a reponer, importe de reposicion

struct moto motos[2];

int venta(){    // cada vez q se vende producto
    int z;      //el codigo de la moto elegida + 1, porq se elige del 1 al 20 y los index son del 0 al 19
    int control = 0;
    int compradas;  //cant de motos q desea comprar el cliente
    while(control == 0){
        control = 1;
        printf("\nque moto desea comprar? elija un codigo del 1 al 20: ");
        scanf("%d",&z);
        if(motos[z - 1].stock == 0){  //asi, si se elige codigo uno, se checkea index 0
            printf("\nno hay stock de esa moto");
            control = 0;
            }
    }
    printf("\nhay stock. stock disponible: %d", motos[z -1].stock);
    printf("\nprecio: %d", motos[z -1].precio);
    
    printf("\ncuantas desea comprar? ");
    scanf("%d", &compradas);
    while(compradas > motos[z -1].stock){
        printf("\nno hay tanto stock! vuelva a elegir cuanto compra: ");
        scanf("%d", &compradas);
    }
    printf("\nticket: "); //código/modelo/ Cantidad vendida /Precio total
    printf("\n-producto codigo %d,\n-modelo %s,\n-cantidad: %d,\n-precio total = %d.\n Muchas gracias", z + 1, motos[z -1].modelo, compradas, motos[z -1].precio * compradas);
    motos[z -1].stock -= compradas;
    motos[z -1].cant_vendida += compradas;
    return 0;
}

int fin(){  //cndo finaliza dia. venta total, codigo y cant venta de c modelo, listado a reponer
    int venta_total = 0; 
    int reposicion = 0;
    printf("\nha finalizado el dia!");
    for(int i = 0; i<2;i++){
        venta_total += motos[i].cant_vendida * motos[i].precio;
        if(motos[i].stock < motos[i].stock_min){ //código,  cantidad a reponer(50 – stock), importe de reposición (cantidad a reponer * precio)
            listado[i][0] =i + 1;
            listado[i][1] = 50 - motos[i].stock;
            listado[i][2] = motos[i].precio * listado[i][1];
            reposicion += listado[i][2];
        }
        printf("\nel producto de codigo %d vendio %d unidades",i + 1, motos[i].cant_vendida); //Imprimir código y cantidad vendida de  cada  modelo
    }
    printf("\nfueron agregados al listado los productos que requerian restock");
    printf("\n cantidad total recaudada: $%d", venta_total);
    printf("\nel precio de la reposicion es $%d", reposicion);
    return 0;
}

int main(){
        int x = 1;
        for(int i = 0; i<2;i++){    // modelo, stock, stock_minimo y el precio. Inicializo datos
            printf("ingrese modelo de la moto codigo %d : ", i + 1);
            scanf("%s",&motos[i].modelo);
            printf("\ningrese stock actual(no puede ser mayor a 50): "); //no puede ser > a 50 porq stock a pedir = 50 - stock y daria num negativo
            scanf("%d",&motos[i].stock);
            while(motos[i].stock > 50){  //while para asegurarme que stock < a 50
                printf("\ningrese stock actual(no puede ser mayor a 50!): ");
                scanf("%d",&motos[i].stock);
            }
            printf("\ningrese stock minimo: ");
            scanf("%d",&motos[i].stock_min);
            printf("\ningrese precio: ");
            scanf("%d",&motos[i].precio);
            motos[i].cant_vendida = 0;   
        }
        while(x != 0){
            printf("\n 0- terminar dia\n1- Vender una moto ");
            scanf("%d", &x);
            if(x == 1){
                venta();
            }
            else{
                fin();
            }
        }
    return 0;
}