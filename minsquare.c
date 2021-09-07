#include <stdio.h>
//#include <string.h>

int minsquare(int x, int y){
        if(x> y){
            if(x%y == 0){
                return y; //resultado
            } 
            return minsquare(x % y, y);

        }
        else if(y > x){
            if(y%x == 0){
                return x; //resultado
            } 
            return minsquare(y % x, x);
        }
        else if(x = y){
            return x;
        }
}

int main()
{
   printf("%d", minsquare(1680,640));
    return 0;
}