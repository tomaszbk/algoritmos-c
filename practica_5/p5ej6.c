#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Definir las siguientes funciones: 
// a. signo, que decide si un número es positivo, negativo o cero (devuelve 1, -1, 0 
// respectivamente)
// b. esMayus, que decide si una letra dada es mayúscula o no lo es
// c. esVocal, si una letra dada es vocal o no lo es
// d. esMultiplo, que decide si el primer parámetro es múltiplo del segundo

char y = 'U';
int signo(int x){
    if(x > 0){
        return 1;
    }
    else if(x == 0){
        return 0;
    }
    return -1;
};
int esMayus(char x){
    char z = x;
    x = tolower(x);
        if(x == z){
            return 1;
        }
    printf("es mayus");
    return 2;
}
int esVocal(char x){
    if((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u')){
        return 1;
    }  
    return 0;
}
int esMultiplo(int x,int b){
    if(x % b == 0 ){
        printf("multiplos!");
    }
    else{
        printf("no son multiplos");
    }
    return 0;
}

int main()
{
    //printf("%d", signo(8)) ;
    esMultiplo(16,5);
    //printf("\n%d", esMayus(y));
   //printf("%d", esVocal(y));
    return 0;
}