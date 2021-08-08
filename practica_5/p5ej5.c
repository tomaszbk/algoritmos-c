// Definir funciones que permitan convertir:
// a. un número entero binario a base decimal
// b. un número entero decimal a base 2
// c. un número entero en base B a decimal
// d. un número entero decimal a base B
// e. un número entero en base B a base C
#include <stdio.h>
#include <math.h>
int f;
int a;
int g;
int binadec(int x){
    int res = 0;
    int exp = 1;
    while (x != 0)
    {
        if(x % 10 != 0){
            res += exp;
        }
        exp = exp*2;
        x=x/10;
    }
    return res;
}

int baseadec(int x, int b){
    int res = 0;
    int exp = 1;
    while (x != 0)
    {
        if(x % 10 != 0){
            res += (x%10) * exp;
        }
        exp = exp * b;
        x=x/10;
    }
    return res;
}

int decabin(int x){
  int z = 7;
  int vector[8];
    for (int s = 0; s < 8; s++)
    {
        vector[s] = 0;
    }
        while (x > 1)
        {
            vector[z] = x % 2;
            x = x / 2;
            z = z - 1;
        }
        vector[z] = 1;
        for (int i = 0; i < 8; i++)
        {
            printf("%d",vector[i]);
        }  
    return 0;  
}

int decabase(int x, int b){
  int z = 7;
  int vector[8];
    for (int s = 0; s < 8; s++)
    {
        vector[s] = 0;
    }
        while (x > b - 1)
        {
            vector[z] = x % b;
            x = x / b;
            z = z - 1;
        }
        // if(b == 2){
        //     vector[z] = 1;}
        if(x != 0){
            vector[z] = x;
        }
        for (int i = 0; i < 8; i++)
        {
            printf("%d",vector[i]);
}
}

int baseabase(int x, int b, int b2){
    int bin = baseadec(x, b);
    printf("\n%d", bin);
    printf("\n");
    int res = decabase(bin, b2);
    printf("\n%d", res);
    return res;
}
int main()
{
    while (1)
    {
    printf("\nnumero ");
    scanf("%d %d %d", &a, &f, &g);
    //printf("\n%d",decabin(a));
    //printf("\n%d",binadec(a));
    //printf("\n%d",baseadec(a,f));
    //printf("\n%d",decabase(a,f));
    printf("\n%d",baseabase(a,f,g));
    }
    return 0;
}
//int numb = floor(log10(abs(x))) + 1;