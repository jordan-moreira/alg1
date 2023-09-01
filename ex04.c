#include <stdio.h>

int main(){
    float R=2,
    S=5,
    T=-1,
    X=3,
    Y=1,
    Z=0;

    int A=(R >= 5) || ((T > Z) && (X - Y + R > 3 * Z)),
    B = (T * -1 + 3 >= 4) && !(3 * R/2 < S * 3),
    C = (X == 2) || ((Y=1) && ((Z == 0))) || (((R > 3)) && (S < 10)),
    D = (R != S) || (!(R/2 < (float)X/2) && (4327 * X * S * Z == 0));

    printf(" os valores de A,B,C e D sao respectivamente %d,%d,%d,%d",A,B,C,D);


}