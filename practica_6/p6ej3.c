// Escribir una función recursiva para contar la cantidad de vocales que posee una cadena de 
// caracteres S.
//  Ejemplo si S = 'Práctica de Algoritmos’ la función retorna 8

#include <stdio.h>
#include <string.h>
int l = 0;
int res = 0;

int contarvocal(char x[], int i){
    char lo = x[i];
    if(lo == 'a'){
        res += 1;
    }
    if(i <= l-1){
        contarvocal(x, i+1);
    }
    return res;
}

int main()
{
    char s[] = "Practica de algoritmos";
    int i = 0;
    l = strlen(s);
    printf("%d", contarvocal(s, i));
    
    return 0;
}