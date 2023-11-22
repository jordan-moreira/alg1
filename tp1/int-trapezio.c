// feito por victor, thiago, jordan

#include <stdio.h>
#include <math.h>

typedef struct
{
    long double a,
        b;

} Intervalo;

typedef struct
{
    int opcao,
        nTrapezios;
    double valorReal;

} Entrada;

// Requisito 1: Funções Numéricas Pré-Definidas
long double chamada(int funcaoSelecionada, long double x)
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
        return 0;
        break;
    }
}

// Requisito 2: Cálculo da Área do Trapézio
long double calcularAreaTrapezio(long double baseMaior, long double baseMenor, long double altura)
{
    return (baseMaior + baseMenor) * altura / 2;
}

// Requisito 3: Divisão do Intervalo [a, b] em m Sub-Intervalos
// void dividirIntervalo(int funcaoSelecionada, long double matrizDeCordenadas[][2], Intervalo intervalo, long double m)
// {
//     //  usa-se uma matriz para armazenar os valores das cordenadas(ja calculados pela funcao selecionada) onde a quantidade de linhas dessa matriz e igual a quantidade de sub-intervalos
//     long double h = (intervalo.b - intervalo.a) / m,
//           intervaloAtual = intervalo.a;

//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             matrizDeCordenadas[j][i] = chamada(funcaoSelecionada, intervaloAtual);
//             intervaloAtual += h;
//         }
//         intervaloAtual = intervalo.a + h;
//     }
// }

// Requisito 4: Cálculo da Integral pelo Método do Trapézio
long double calcularIntegral(int funcaoSelecionada, int m, Intervalo intervalo)
{ // essa funcao calcula a are de todos os trapezios formados usando os seus pares de coordenadas passados pela matriz e retorna a somatoria dos mesmos

    long double h = (intervalo.b - intervalo.a) / m,
          intervaloAtual = intervalo.a,
          somatoriaArea=0;

    for (int i = 0; i < m; i++)
    {
        long double a=chamada(funcaoSelecionada, intervaloAtual),
        b=chamada(funcaoSelecionada, intervaloAtual+h);

        somatoriaArea += calcularAreaTrapezio(a,b, h);
        intervaloAtual += h;
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

        if (!(entrada.opcao == 1 || entrada.opcao == 2 || entrada.opcao == 3))
        {
            printf("Opcao invalida!!");
        }
    }
    printf("Digite o numero de trapezios a usar na aproximacao:\n");
    scanf("%d%*c", &entrada.nTrapezios);
    return entrada;
}

// Requisito 6: Saída de Dados
// Função para calcular o erro absoluto
long double ErroAbsoluto(long double valorReal, long double valorAprox)
{
    return fabs(valorReal - valorAprox);
}
// Função pra calcular o erro relativo
long double ErroRelativo(long double valorReal, long double valorAprox)
{
    return ErroAbsoluto(valorReal, valorAprox) / fabs(valorReal);
}
// Função saída
void Saida(long double valorReal, long double valorAprox, int nTrapezios)
{
    long double erroAbsoluto = ErroAbsoluto(valorReal, valorAprox);
    long double erroRelativo = ErroRelativo(valorReal, valorAprox);

    // Imprimir os resultados
    printf("Resultado para %d trapézios: %f\n", nTrapezios, valorAprox);
    printf("Erro Absoluto: %f\n", erroAbsoluto);
    printf("Erro Relativo (%%): %f\n", erroRelativo);
}

// Requisito 7: Função Principal
int main()
{
    Entrada dadosEntrada = capturarDados();
    Intervalo intervalo;

    switch (dadosEntrada.opcao)
    {
    case 1:
        intervalo.a = 1;
        intervalo.b = 7;
        dadosEntrada.valorReal = 1.94591;
        break;
    case 2:
        intervalo.a = 0.4;
        intervalo.b = 2;
        dadosEntrada.valorReal = 12.48287;
        break;
    case 3:
        intervalo.a = 1;
        intervalo.b = 3;
        dadosEntrada.valorReal = 17.2469;
        break;
    default:
        printf("erro na selecao de intervalo!!");
        break;
    }

    long double resultado = calcularIntegral(dadosEntrada.opcao, dadosEntrada.nTrapezios, intervalo);

    Saida(dadosEntrada.valorReal, resultado, dadosEntrada.nTrapezios);
}
