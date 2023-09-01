#include <stdio.h>



int main(){
    float pi=3.14,
    a=(18/3/2-1)*5-4-(2+3+5)/2,
    b=26/6/2-127/7%5,
    c=7%4-8/(3+1);

    int d=((2>=5)&&(1!=0)&&!(6<=2*3))||(10!=10),
    e=(5!=2)|| !((7>4) && (4<=pi));

    printf("o valor de A,B,C,D,e E e respectivamente %.2f,%.2f,%.2f,%d,%d",a,b,c,d,e);
}