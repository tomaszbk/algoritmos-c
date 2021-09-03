#include <stdio.h>
// Plantear la estrategia de resolución explicando las estructuras de datos y la lógica principal de resolución.

// Un negocio tiene un catalogo de productos. No tiene mas de 5000 productos distintos. 
// De cada producto se tiene código de identificación numérica, stock de reposición, stock actual, stock máximo, 
// precio de compra, precio de venta y cantidad de ventas diarias. El catalogo se implementa con un arreglo 
// bidimensional de 5000 posiciones desordenados. Debe simular un día de trabajo teniendo en cuenta:

// 1) Realizar una función de carga inicial.

// 2) En el cuerpo del programa principal implementar un menú para realizar las siguientes acciones:
// a) Anotar un nuevo producto.
// b) Actualizar el precio (de compra o venta) de un producto.
// c) Vender un producto.
// d) Finalizar el día.

// 3) para anotar un producto se debe ocupar la primera posición vacía del catalogo ("recordar" algorítmicamente cual es esa posición)

// 4) Al fin día se debe realizar un listado (en arreglo 500 posiciones) que contenga los id de los productos cuyo stock llego al valor de reposición, y la cantidad a pedir (stock máximo - stock actual).

//var:
//vector 5000 productos
//por producto: codigo id, stock de reposicion, stock actual, stock max, precio compra, precio venta, cant ventas diarias
//pos vacia
//
//funciones:
//anotar un nuevo producto
//actualizar precio de compra o venta
//vender un producto
//fin dia
int x = 1;
int sin_producto=0;


int listado[500][2]; //1ero: id. 2do:

   //colum 0  id;
   //colum 1  stock_repo;
   //colum 2  stock_actual;
   //colum 3  stock_max;
   //colum 4  precio_venta;
   //colum 5  precio_compra;
   //colum 6  ventas_diarias;
int productos[5000][7]; 


int fin(){
    int j =0;
    for(int i = 0;i<5000;i++){
        if(productos[i][2] < productos[i][1]){
            listado[j][0] = productos[i][0];
            listado[j][1] = productos[i][3] - productos[i][2];
            printf("\nel producto de id %d ha sido restockeado!", productos[i][0]);
        }
        j +=1;
    }
}

int nuevo_product(){
    printf("\ningrese el id del producto ");
    scanf("%d",&productos[sin_producto][0]);
     printf("\ningrese stock para reposicion ");
    scanf("%d",&productos[sin_producto][1]);
     printf("\ningrese el stock actual ");
    scanf("%d",&productos[sin_producto][2]);
     printf("\ningrese el stock maximo ");
    scanf("%d",&productos[sin_producto][3]);
     printf("\ningrese el precio de venta ");
    scanf("%d",&productos[sin_producto][4]);
     printf("\ningrese el precio de compra ");
    scanf("%d",&productos[sin_producto][5]);
    printf("\nproducto agregado con exito ");
    sin_producto +=1;
}

int act_precio(){
    int prod;
    int choice;
    printf("de que producto desea actualizar el precio?\n las opciones son: ");
    for(int i = 0; i< sin_producto; i++){
        printf("%d",i);
    }
    scanf("%d", &prod);
    printf("\ncambiar precio compra o venta?\n compra: 0\nventa: 1 ");
    scanf("%d", &choice);
    if(choice==0){
        printf("\nseleccione nuevo precio de compra: $");
        scanf("%d",&productos[prod][5]);
    }
    else{
        printf("\nseleccione nuevo precio de venta: $");
        scanf("%d",&productos[prod][4]);
    }
    printf("\nel precio ha sido actualizado correctamente! ");
}

int vender_producto(){
    int r;
    printf("\nque producto se va a vender? las opciones son:");
     for(int i = 0; i< sin_producto; i++){
        printf("\n%d a $%d",i, productos[i][4]);
    }
    scanf("%d",&r);
    productos[r][6] += productos[r][4];
    printf("\ncompra realizada con exito");
}



int main()
{
    while(x != 0){
        printf("\nque desea hacer?\n0-fin dia \n1-anotar un nuevo producto\n 2-actualizar precio de compra o venta\n 3-vender un producto\n");
        scanf("%d",&x);
        switch(x){
            case 0:{
                fin();
                break;
            }
            case 1:{
                nuevo_product();
                break;
            }
            case 2:{
                act_precio();
                break;
            }
            case 3:{
                vender_producto();
                break;
            }
        }
    }

    return 0;
}