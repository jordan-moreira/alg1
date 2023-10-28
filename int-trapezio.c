#include <stdio.h>
#include <math.h>

typedef struct
{
    float a,
        b;

} Intervalo;

typedef struct
{
    float opcao,
        nTrapezios;

} Entrada;

// Requisito 1: Funções Numéricas Pré-Definidas
float chamada(int funcaoSelecionada, float x)
{ // a funcao em questao recebe como parametro um inteiro indicando qual funcao abaixo sera executada e o valor de x retornando o resultado da mesma

    switch (funcaoSelecionada)
    {
    case 1:
        return 1 / x; //=1.94591
        break;

    case 2:
        return exp(x) * sin(10 * x) + 8; //=12.48287
        break;

    case 3:
        return pow(x, 3) * log(x); //=17.2469
        break;

    default:
        printf("erro ao executar a funcao");
        break;
    }
}

// Requisito 2: Cálculo da Área do Trapézio
float calcularAreaTrapezio(float baseMaior, float baseMenor, float altura)
{
    return (baseMaior + baseMenor) * altura / 2;
}

// Requisito 3: Divisão do Intervalo [a, b] em m Sub-Intervalos
void dividirIntervalo(int funcaoSelecionada, float matrizDeCordenadas[][2], Intervalo intervalo, float m)
{
    //  usa-se uma matriz para armazenar os valores das cordenadas(ja calculados pela funcao selecionada) onde a quantidade de linhas dessa matriz e igual a quantidade de sub-intervalos
    float h = (intervalo.b - intervalo.a) / m,
          intervaloAtual = intervalo.a;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrizDeCordenadas[j][i] = chamada(funcaoSelecionada, intervaloAtual);
            intervaloAtual += h;
        }
        intervaloAtual = intervalo.a + h;
    }
}

// Requisito 4: Cálculo da Integral pelo Método do Trapézio
float calcularIntegral(int funcaoSelecionada, float matrizDeCordenadas[][2], int m, Intervalo intervalo)
{ // essa funcao calcula a are de todos os trapezios formados usando os seus pares de coordenadas passados pela matriz e retorna a somatoria dos mesmos

    float h = (intervalo.b - intervalo.a) / m,
          somatoriaArea = 0;

    for (int i = 0; i < m; i++)
    {
        somatoriaArea += calcularAreaTrapezio(matrizDeCordenadas[i][1], matrizDeCordenadas[i][0], h);
    }

    return somatoriaArea;
}

//  Requisito 5: Entrada de Dados
Entrada capturarDados()
{ // essa funcao e responsavel por receber todas as entradas de informacao do usuario e retorna uma struct contendo essa informacoes

    Entrada entrada;
    while (!(entrada.opcao == 1 || entrada.opcao == 2 || entrada.opcao == 3))
    {
        printf("Integracao pela Regra do Trapezio\n");
        printf("========== ==== ===== == ========\n");
        printf("Funcoes:\n");
        printf("1) Integral [1.0, 7.0] de f(x) = 1/x\n");
        printf("2) Integral [0.4, 2.0] de f(x) = e^x sen(10x) + 8\n");
        printf("3) Integral [1.0, 3.0] de f(x) = x^3 ln(x)\n");
        printf("Escolha a funcao a integrar:\n");
        scanf("%d%*c", &entrada.opcao);
    }
    printf("Digite o numero de trapezios a usar na aproximacao:(entre 1 e 1000)\n");
    scanf("%d%*c", &entrada.nTrapezios);
    return entrada;
}

// Requisito 6: Saída de Dados

// Requisito 7: Função Principal
int main()
{
    printf("bora la");
}

// falta criar a funcao de saida, emplementar tudo no main e testar pra ver se ta rodando