//Se ingresan 4 números reales y se quiere determinar si la suma de ellos es positiva,
//negativa o cero. Imprimir un mensaje indicándolo

#include <stdio.h>
int res = 0;
int loc;

int main()
{
    for(int i = 0; i < 4; i++)
    {
        printf("ingrese el numero");
        scanf("%d", &loc);
        res = res+ loc;
    }

    if (res > 0)
    {
        printf("positivo");
    }
    else if (res < 0)
    {
        printf("negativo");
    }
    else{
    printf("neutro o error");
    }
    return 0;
}