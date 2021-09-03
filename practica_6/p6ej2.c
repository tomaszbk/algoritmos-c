#include <stdio.h>
#include <string.h>
// Implementar una solución recursiva para los siguientes casos y verificar usando el método 
// de las cajas:
// a) Imprimir en forma invertida una palabra.
// b) Retornar la cantidad de palabras de una frase terminada en ‘.’ (las palabras vienen 
// separadas por un espacio en blanco)

int invertir(char x[], int y){
    int len = strlen(x);
    if(y < len){
        invertir(x, y + 1);
    }
    printf("%c", x[y]);
}

int palab = 1;
int palabras(char s[],int y){
    char c = s[y];
    if(c == ' '){
        palab += 1;
    }
    else if(c == '.'){
        return palab;
    }
    palabras(s,y+1);

}

int main()
{
    // invertir("tomasaso", 0);
    printf("%d", palabras("hola como andas amigo.", 0));
    return 0;
}