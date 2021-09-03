#include <stdio.h>


int countdown(int x){
    printf("\n%d",x);
    if(x>0){
        countdown(x-1);
    }
    
}
int main()
{
    countdown(3);
    return 0;
}