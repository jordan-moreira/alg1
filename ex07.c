#include <stdio.h>

int main(){
    float nota1=0,
    nota2=0,
    nota3=0,
    media=0;

    printf("digite respectivamente as tres notas a serem calculadas a media separdas por espaco: ");
    scanf("%f %f %f%*c",&nota1,&nota2,&nota3);

    media=(nota1+nota2+nota3)/3;

    printf("a media das notas e %.2f",media);

}