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

double calcularIr(float salLiqui)
{
    if (salLiqui > 3743.19)
    {
        return salLiqui * 0.275 - 692.78;
    }
    else if (salLiqui > 2995.70)
    {
        return salLiqui * 0.225 - 505.62;
    }
    else if (salLiqui > 2246.75)
    {
        return salLiqui * 0.15 - 280.94;
    }
    else if (salLiqui > 1499.15)
    {
        return salLiqui * 0.075 - 112.43;
    }
    else
    {
        return salLiqui;
    }
}

int main()
{
    float salarioBruto = 0,
          contribuicao = 0,
          salarioLiquido = 0;
    double ir = 0;

    printf("digite o seu salario bruto:");
    scanf("%f%*c", &salarioBruto);

    contribuicao = calcularContribuicao(salarioBruto);
    salarioLiquido = salarioBruto - contribuicao;
    ir = calcularIr(salarioLiquido);
    salarioLiquido = ir;

    printf("baseado nesse salario bruto havera um desconto de R$%.2f de INSS um desconto de R$%.2f referente ao IR resultando num salario liquido de R$%.2f", contribuicao, ir, salarioLiquido);
}