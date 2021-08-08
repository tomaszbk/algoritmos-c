#include <stdio.h>
int mesas[50] = {0};
int ind;
int plata;
int main()
{
    while (1)
    {
        printf("\ningrese mesa ");
        scanf("%d", &ind);
        if(ind == 100){
            break;
        }
        printf("\ningrese gasto ");
        scanf("%d",&plata);
        mesas[ind - 1] += plata + 20;  
    }
    
    return 0;
}