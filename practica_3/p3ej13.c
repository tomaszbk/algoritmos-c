#include <stdio.h>

int cant;
int choice;
int res;
int abajo;
int a;
int b;
int c;
int main()
{
for (int j = 0; j < 3; j++)
    {
    printf("\nciudad %d", j+1);

    printf("\ningrese cantidad a entrevistar ");
    scanf("%d", &cant);
    abajo = cant;  
    a = 0;
    b= 0 ;
    c= 0 ;

    for (int i = 0; i < cant; i++)
    {       
                                             
        printf("\nindicar 1-bueno 2-maso 3-malo 4-nose ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            a += 1;
            break;

        case 2:
            b += 1;
            break;

        case 3:
            c = c + 1;
            break;
        
        case 4:
            abajo -= 1;
            break;
            
        default:
        printf("\nno valido!");
        i -= 1;
            break;
        }
    }
    printf("\nel porcentaje de que les gusto es %.2f", (a* 100.0) /abajo);
    printf("\nel porcentaje de que les gusto maso es %.2f", (b * 100.0)/abajo);
    printf("\nel porcentaje de que no les gusto es %.2f", (c * 100.0)/abajo);
     }
    return 0;
}