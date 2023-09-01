#include <stdio.h>

float calcularContribuicao(float salBruto)
{
    if (salBruto <= 1040.22)
    {
        return salBruto * 0.08;
    }
    else if (salBruto > 1040.22 && salBruto <= 1733.70)
    {
        return salBruto * 0.09;
    }
    else if (salBruto > 1733.70 && salBruto <= 3467.40)
    {
        return salBruto * 0.11;
    }
    else
    {
        return 381.41;
    }
}

int main()
{
    float salarioBruto = 0,
          contribuicao = 0,
          salarioLiquido = 0;

    printf("digite o seu salario bruto:");
    scanf("%f%*c", &salarioBruto);

    contribuicao = calcularContribuicao(salarioBruto);
    salarioLiquido = salarioBruto - contribuicao;

    printf("a contribuicao sera de R$%.2f e o salario liquido de R$%.2f", contribuicao, salarioLiquido);
}