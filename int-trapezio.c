#include <stdio.h>
#include <math.h>

// Requisito 2: Cálculo da Área do Trapézio
float calcularAreaTrapezio(float baseMaior, float baseMenor, float altura)
{
    return (baseMaior + baseMenor) * altura / 2;
}

// Requisito 3: Divisão do Intervalo [a, b] em m Sub-Intervalos
void dividirIntervalo(float matrizDeCordenadas[][2], int a, int b, float m)
{
    //  usa-se uma matriz para armazenar os valores das cordenadas onde a quantidade de linhas dessa matriz e igual a quantidade de sub-intervalos
    float h = (b - a) / m,
          intervaloAtual = a;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrizDeCordenadas[j][i] = intervaloAtual;
            intervaloAtual += h;
        }
        intervaloAtual = a + h;
    }
}

int main()
{
    printf("bora la");
}