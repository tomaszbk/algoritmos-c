// Escribir una función recursiva para ver si una palabra es un palíndromo. Ej: ananá es 
// un palíndromo

#include <stdio.h>
#include <string.h>
int l; // indice
int x = 1;
int i = 0;
int palindromo(char s[], int r, int i){
    char undig = s[i];
    char lasdig = s[r];
    printf("%c", lasdig);
    printf("%c", undig);
    if(i <= r){
        palindromo(s,r-1,i+1);
        return x;
    }
    if(undig != lasdig){
        printf("%c", undig);
        printf("%c", lasdig);
        x = 0;
    }
    return x;
}

int main()
{
   char s[] = "banab";
   l = strlen(s);
   printf("%d", palindromo(s, l -1, 0));
    return 0;
}