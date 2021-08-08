#include <stdio.h>

// Implementar un programa que lea dos números a y b e imprima la suma de las primeras b
// potencias de a, contando desde la potencia 0

int a;
int b;
int res = 1;
int temp = 1;

int main()
{
    printf("ingrese numero a espacio potencia b ");
    scanf("%d %d", &a, &b);
    
        for (int z = 0; z < b; z++)
        {
            temp = temp * a;
            res += temp;
            printf("\n %d", res);
        }

    printf("\n %d", res);
    return 0;
}
