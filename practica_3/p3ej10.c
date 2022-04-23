#include <stdio.h>

int num; 
int a;
int main()
{
     scanf("%d", &num);
     a = num/2;

     for (int i = 1; i <= a; i++)
     {
         if (num%i == 0)
         {
             printf("\n%d", i);
         }
         
     }
    printf("\n%d", num);
    return 0;
}