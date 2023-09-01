#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    #define TAM 200

int main() {
    int vetor[TAM];
    
    // Inicializa o gerador de números aleatórios com uma semente baseada no horário atual
    srand(time(NULL));
    
    // Preenche o vetor com números aleatórios
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand()% 1001;
    }
    
    // Imprime os números aleatórios gerados
    for (int i = 0; i < TAM; i++) {
        printf("%d,", vetor[i]);
    }
    
    return 0;
}