#include <stdio.h>

int main(){
    int a=0,
    b=0,
    temp=0;

    printf("digite respectivamente separados os valores inteiros a serem armazenados em a e b: ");
    scanf("%d %d%*c",&a,&b);

    printf("a=%d \nb=%d \n",a,b);
    printf("trocando os valores\n");

    temp=a;
    a=b;
    b=temp;
    printf("a=%d \nb=%d",a,b);
}