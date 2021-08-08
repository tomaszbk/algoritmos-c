#include <stdio.h>

int main()
{
    for (int i = 1; i < 6; i++)
    {
      for (int z = 0; z < i; z++)
      {
        printf("*");
      }
      printf("\n");
    }
    return 0;
}