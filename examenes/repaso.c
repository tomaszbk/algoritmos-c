#include <stdio.h>
// Clase práctica 4/8. Repaso para examen. (ppt Clase 10)

int main(){
    
    //Declaración de un registro en el que se almacenarán los datos de cada una de las mesas
    struct datosMesa{
        //Como estos tres primeros datos no se utilizan ni en la lógica del programa ni como datos de salida, es necesario guardarlos? -> Consultar
        char nombre[20]; 
        char apellido[30];
        int dni;

        int comensales;
        int subtotal;
        int total;
    };
    
    //Declaración de un arreglo de 50 elementos del tipo datoMesa, que representa cada una de las mesas del restaurante
    struct datosMesa mesas[49];

    //Inicialización del arreglo anterior
    for (int i = 0; i < 49; i++){
        mesas[i].comensales = 0;
        mesas[i].subtotal = 0;
        mesas[i].total = 0;
    }
    
    //Var aux
    int cubierto;
    int op;

    printf("\nIngrese el valor de cubierto: $");
    scanf("%d", &cubierto);

    //Mientras no se decida finalizar el día, el bloque se ejecutará en bucle
    do{
        //Menú de opciones
        printf("\nOcupar una mesa ..................1");
        printf("\nActualizar una mesa...............2");
        printf("\nCobrar una mesa...................3");
        printf("\nFinalizar día.....................4");
        printf("\n>");
        scanf("%d", &op);
        
        //De acuerdo a la opción seleccionada...
        switch (op){
            //De haberse seleccionado ocupar una mesa... (opción 1)
            case 1:{
                int mesaDisp;
                int valorPedido;

                //Se recorren todas las mesas buscando alguna sin comensales, y de existir alguna se almacena sú número. De no existir mesa vacía se indica con -1
                for (int i = 0; i < 49; i++){
                    if(mesas[i].comensales == 0){
                        mesaDisp = i;
                        break;
                    } else {
                        mesaDisp = -1;
                    }
                }

                //Si la mesa está vacía se informa, y si no se procede a pedir los datos requeridos
                if (mesaDisp == -1){
                    printf("\nTodas las mesas están ocupadas.");
                } else {
                    printf("\n====== Se asignó la mesa %d =======\n", mesaDisp);
                    printf("\nIngrese la cantidad de comensales: ");
                    scanf("%d", &mesas[mesaDisp].comensales);
                    printf("\nIngrese el nombre de uno de los comensales: ");
                    scanf("%s", &mesas[mesaDisp].nombre);
                    printf("\nIngrese el apellido de %s: ", mesas[mesaDisp].nombre);
                    scanf("%s", &mesas[mesaDisp].apellido);
                    printf("\nIngrese el DNI de %s %s: ", mesas[mesaDisp].nombre, mesas[mesaDisp].apellido);
                    scanf("%d", &mesas[mesaDisp].dni);
                    printf("\nIngese el valor del pedido: $");
                    scanf("%d", &valorPedido);

                    //Se acumula el valor del pedido en el subtotal de la mesa
                    mesas[mesaDisp].subtotal += valorPedido;
                    //Se le acumula al subtotal calculado anteriormente el valor de cubierto para cada uno de los comensales de la mesa en cuestión
                    mesas[mesaDisp].subtotal += mesas[mesaDisp].comensales * cubierto;
                }
                break;
            }

            //En caso de querer actualizar una mesa ya ocupada
            case 2:{
                int mesa;
                int valorPedido;

                printf("\nIngrese el número de la mesa a actualizar: ");
                scanf("%d", &mesa);

                //Si la mesa que se quiere actualizar está desocupada se informa. Caso contrario se indica el precio del nuevo pedido
                if (mesas[mesa].comensales == 0){
                    printf("\nLa mesa %d está desocupada. Seleccione otra mesa o ocupe una nueva.", mesa);
                } 
                else {
                    printf("\nIngese el valor del nuevo pedido: ");
                    scanf("%d", &valorPedido);
                    mesas[mesa].subtotal += valorPedido;
                }
                break;
            } 

            //En caso de querer cobrar una mesa
            case 3:{
                int mesa;

                printf("\nIngrese el número de la mesa a cobrar: ");
                scanf("%d", &mesa);

                //Se valida que la mesa en cuestión tenga comensales, de no ser así es informado
                if (mesas[mesa].comensales == 0){
                    printf("\nLa mesa %d está desocupada, por lo que no puede cobrarse.", mesa);
                } else {
                    printf("\nLa mesa %d debe abonar $%d", mesa, mesas[mesa].subtotal);
                    //Se adiciona lo que gastaron éstos clientes al total acumulado de la mesa
                    mesas[mesa].total += mesas[mesa].subtotal;
                    //Se resetean los valores de la mesa
                    mesas[mesa].comensales = 0;
                    mesas[mesa].dni = 0;
                    mesas[mesa].subtotal = 0;
                }

                break;
            }

            //Finalizar dia
            case 4: {
                int totDia = 0; //Acumulador que contendrá lo ganado en todas las mesas

                //Recorre cada mesa y acumula su total en la variable anterior
                for (int i = 0; i < 49; i++){
                    totDia += mesas[i].total;
                }

                printf("\n========================= Día finalizado ==========================");
                
                //Se valida que la ganancia no sea cero para evitar un error al momento realizar el cálculo del porcentaje (división por 0)
                if (totDia != 0){
                    //Recorro cada mesa e informo el total de c/u y lo que representa en el total de ganancias
                    for (int i = 0; i < 49; i++){
                        //Por una cuestión de orden solamente se muestra qué mesas obtuvieron ganancias, y se informa que para el resto fue de $0. Caso contrario se impirmirían 50 líneas en la consola haciendo engorrosa la lectura
                        if (mesas[i].total * 100 / totDia != 0){
                            printf("\nLa mesa %d obtuvo $%d totales, que representan el %d%% del total", i, mesas[i].total, mesas[i].total * 100 / totDia);
                        } else{
                            printf("\nEl resto de mesas obtuvieron $0, que representan el 0%% del total");
                            break;
                        }
                    }
                    printf("\n_____________________");
                    printf("\nEl total de ganancias del día es de $%d", totDia);
                } else {
                    printf("\nNinguna mesa obtuvo ganancias, por lo que la ganancia total del día es de $0.");
                }
                break;
            }

            default:{
                printf("\nOpción inválida. Ingrese '1', '2', '3' ó '4'");
                break;
            }
        }
    } while (op != 4);
return 0;
}