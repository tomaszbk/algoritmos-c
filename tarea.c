// ENUNCIADO DEL PROBLEMA:
// Se determina una aplicación que permite realizar una gestión de datos, sobre una población con un máximo nunca superable de 10.000 personas, durante 70 días, sobre la emergencia sanitaria por el COVID-19. Se definen los siguientes estados de una persona:
//  1-Sin contagio, 2-Contagiado, 3- Fallecido.
//  Una misma persona puede ser testeada en varias ocasiones y se recupera cuando tenía un testeo previo de contagiado y se ingresa un testeo de la persona sin contagio. Se supone que una persona que se recupera no vuelve a contagiarse. Durante 70 días se reciben datos de cada testeo informando:

//  DNI del testeado y estado actual (código 1 a 3), actualizando el seguimiento de personas. 

// Se debe generar un informe diario, incluyendo: 
//el número de día, cantidad total de personas testeadas hasta la fecha, cantidad de nuevas persona testeadas en la fecha, cantidad de contagiados activos actuales a la fecha, cantidad de contagiados recuperados a la fecha, porcentaje de cantidad testeados con contagio sobre testeados en el día, cantidad total de fallecidos hasta la fecha y cantidad de nuevos fallecidos en la fecha.

// Desarrollar los siguientes módulos:
// Módulo principal: Control de proceso diario con la impresión del informe
// Procedimiento INICIAL: Inicialización de datos en las estructuras compuestas
// Procedimiento CONTROLDIA: Proceso de los datos de cada día individual
// Función PORCECONDIA: Calcula el porcentaje de contagios diarios

#include <stdio.h>
// INFORME en controldia
int testeos_totales = 0;
int dia = 1;
int testeos_nuevos= 0;
int contagios_activos = 0;
int contagios_recuperados = 0;
int muertes_tot = 0;
int nuevas_muertes = 0;
int x = 1;
int temp = 0;
int cont;
int r = 0;
//porcentaje de testeados con contagio sobre testeados total en el día, en porcecondia

// struct persona{
//     int dni;
//     int estado;};
int personas[10000][2];
int controldia(){
    printf("dia %d", dia);
    dia +=1;
    printf("muertes nuevas %d", nuevas_muertes);
    nuevas_muertes = 0;
    printf("muertes totales %d", muertes_tot);
    printf("testeos nuevos %d", testeos_nuevos);
    testeos_nuevos = 0;
    printf("testeos totales %d", testeos_totales);
}
int inicial(z){
        for ( r; r < 10000; r++)
        {
            if (personas[r][0] = z)
            {
                if (personas[r][1] = 3)
                {
                    return -1;
                }
                if (personas[r][1] = 2)
                {
                    temp = 2;
                }
                if (personas[r][1] = 1)
                {
                    temp = 1;
                }
                return r;
            }
            if(personas[r][0] = 0){
                return r;
            }
        }
}
int main(){
    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 10000; b++)
        {
            personas[b][a] = 0;
        }
    }  
    for (int i = 0; i < 70; i++)
    {
        while (x != -2)
        {
            printf("ingrese dni o -2 para terminar dia");
            scanf("%d", &x);
            if (x = -2)
            {
                break;
            }
                x = inicial(x);
                printf("ingrese su estado, 1 sin nada , 2 contagio, 3 muerte");
                scanf("%d", &cont);
                personas[x][1] = cont;
                if (cont = 2)
                {
                    contagios_activos+=1;
                }
                if (cont = 3)
                {

                    muertes_tot +=1;
                    nuevas_muertes+=1;
                }
                if (cont = 1)
                {
                    if (temp = 2)
                    {
                        contagios_recuperados +=1;
                    }
                }
                testeos_totales +=1;
                testeos_nuevos +=1;
        }
        controldia();
    }
    return 0;
}
// int controldia(){
//     printf("dia %d", dia);
//     dia +=1;
//     printf("muertes nuevas %d", nuevas_muertes);
//     nuevas_muertes = 0;
//     printf("muertes totales %d", muertes_tot);
//     printf("testeos nuevos %d", testeos_nuevos);
//     testeos_nuevos = 0;
//     printf("testeos totales %d", testeos_totales);
// }
// int porcecondia(){

// }
// int inicial(z){
//         for ( r; r < 10000; r++)
//         {
//             if (personas[r][0] = z)
//             {
//                 if (personas[r][1] = 3)
//                 {
//                     return -1;
//                 }
//                 if (personas[r][1] = 2)
//                 {
//                     temp = 2;
//                 }
//                 if (personas[r][1] = 1)
//                 {
//                     temp = 1;
//                 }
//                 return r;
//             }
//             if(personas[r][0] = 0){
//                 return r;
//             }
//         }
// }