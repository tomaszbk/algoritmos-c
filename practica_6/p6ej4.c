// La serie de Fibonacci se define de la siguiente manera:
//  F (0) = 0 
//  F (1) = 1
//  F(n) = F (n-1) + F(n-2) con n>1
// Implementar una función recursiva para obtener los números de Fibonacci

#include <stdio.h>
//#include <string.h>

int fibonacci(int x){
    if(x == 0){
        //printf(" %d ", x);
        return 0;
    }
    else if(x == 1){
        //printf(" %d ", x);
        return 1;
    }
    else if(x > 1){      
        return fibonacci(x -1) + fibonacci(x -2);
    }

}
int main()
{
   printf("%d", fibonacci(11));
    return 0;
}