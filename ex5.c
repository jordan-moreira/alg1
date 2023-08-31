#include <stdio.h>
#include <math.h>

int main(){
    float raio=0,
    pi=3.14,
    circunferencia=0,
    area=0;

    printf("digite o valor do raio do circulo:");
    scanf("%f%*c",&raio);

    circunferencia=2*pi*raio;
    area=pi*pow(raio,2);

    printf("a circunferencia e area do circulo de raio %.2f sao respectivamente %.2f,%.2f",raio,circunferencia,area);
}