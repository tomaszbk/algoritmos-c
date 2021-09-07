// Realizar un procedimiento recursivo que reciba un valor entero e imprima su equivalente en 
// sistema binario. Vale recordar que para pasar un número decimal a sistema binario hay que 
// dividirlo sucesivamente por 2 hasta que el resultado sea 1. Luego tomar ese 1 y los restos 
// en forma inversa para representarlo. 
// Ejemplo: 47 en binario es 101111.
// 1. 47 / 2 = 23 resto 1
// 2. 23 / 2 = 11 resto 1
// 3. 11 / 2 = 5 resto 1
// 4. 5 / 2 = 2 resto 1
// 5. 2 / 2 = 1 resto 0
//  Nota: para resolver el ejercicio debe usar la función parte entera (para calcular el resultado 
// entero de la división y obtener el resto)

#include <stdio.h>
//#include <string.h>

//int numb = floor(log10(abs(x))) + 1;
int decabin(int x){
    if(x ==1){
        printf("%d", 1);
        return;
    }
    int numb = floor(x/2);
    decabin(numb);
    printf("%d", x%2);

}

int main()
{
    decabin(9);
    return 0;
}