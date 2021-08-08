#include <stdio.h>

int peso;
int distancia;
int tiempo; 

int main()
{
    int peso_perdido;
    printf("ingrese peso ");
    scanf("%d", &peso);
    printf("ingrese distancia ");
    scanf("%d", &distancia);
    printf("ingrese tiempo ");
    scanf("%d", &tiempo);

    peso = peso * 1000;
    peso_perdido = distancia * 2; 
    printf("peso perdido %d gramos y peso final %d  gramos ", peso_perdido, peso - peso_perdido);
    if (peso_perdido > 300)
    {
        printf("\nnecesita vit a");
        if (peso_perdido > 450)
        {
           printf("necesita vit c");
        }
    }
    if (tiempo < 25)
    {
        printf("superado circuito olimpico");
        if(tiempo < 15)
        {
            printf("superado circuito panamericano");           
        }
        
    }
    

    return 0;
}