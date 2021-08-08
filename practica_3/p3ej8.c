
// Implementar un programa que lea tres números A, B, C e imprima las potencias de A
// empezando desde la que está en la posición B hasta la C

#include <stdio.h>

    int a;
    int b;
    int c;
    int res = 1;
int main()
{
    printf("ingrese numero a espacio 1era potencia b ");
    scanf("%d %d", &a, &b);
    printf("\n ahora c ");
    scanf("%d", &c);

    if (b < 2) {
        if (b < 1)
        {
            printf("\n 0");
        }        
        printf("\n 1");
    }  
    for (int i = 0; i < c; i++) 
    {
        res = res * a;
        if (i  >= b)
        {
            printf("\n %d", res);
        }
    }
    return 0;
}