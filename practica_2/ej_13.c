#include <stdio.h>

int num;
int fin = 0;

int main()
{
    for (int i = 0; i < 3; i++)
    {
    printf("ingrese numero ");
    scanf("%d", &num);
        if (num>fin)
        {
            fin = num;
        }
    }
    printf("el numero mas grande es %d", fin);
    return 0;
}