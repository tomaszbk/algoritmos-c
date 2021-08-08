#include <stdio.h>

int vec[3];

int main()
{
    for(int i=0; i<3; i++){
        printf("eyy?");
        printf("ingrese el numero numero %d ", i);
        scanf("%d", &vec[i]);
    }

    if ( (vec[0] + vec[1] == vec[2]) || (vec[0] + vec[2] == vec[1]) || (vec[1] + vec[2] == vec[0]) )
    {
        printf("son iguales!");
    }
    
    return 0;
}

