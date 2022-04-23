#include <stdio.h>

int x = 0;
int art;
int price;
int arttres = 0;
int matris[4][2] = {0};
int main()
{
    while (1)
    {
        printf("que vendedor? (1/2/3/4) que articulo? 1/2/3 y precio ");
        scanf("%d %d %d", &x, &art, &price);
        switch (x)
        {
        case 1:
            matris[0][0] += 1;
            matris[0][1] += price;
            break;

        case 2:
            matris[1][0] += 1;
            matris[1][1] += price;
            break;

        case 3:
            matris[2][0] += 1;
            matris[2][1] += price;
            if (art == 1){
                arttres +=1;
            }
            break;
        
        case 4:
            matris[3][0] += 1;
            matris[3][1] += price;
            break;

        default:
        printf("\nno valido!");
            break;
        }
        if (x ==5)
        {
            break;
        }
        
    }
    
    printf("cantidad de articulos por vendedor: %d %d %d %d", matris[0][0], matris[1][0],matris[2][0],matris[3][0]);
    printf("\n  El monto de la mayor operación de venta del art 1 realizada por el vendedor 3: %d", arttres);
    for (int i = 1; i < 4; i++)
    {
        printf("\n El importe promedio por vendedor %d : %d", i, matris[i-1][1]/matris[i-1][0]);
    }

    return 0;
}