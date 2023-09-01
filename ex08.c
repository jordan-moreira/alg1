#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int a=0;
void ordenarDecrescente(int vetor[]) {
    for (int i = 0; i < 200 - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < 200; j++) {
            if (vetor[j] > vetor[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            trocar(&vetor[i], &vetor[maxIndex]);
        }
        printf("%d\n",a);
        a++;
    }
}

int main() {
    int vetor[200];
    
    srand(time(NULL));
    
    for (int i = 0; i < 200; i++) {
        vetor[i] = rand() % 1001;
    }
    
    printf("Números aleatórios gerados:\n");
    for (int i = 0; i < 200; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    ordenarDecrescente(vetor);
    
    printf("Números aleatórios em ordem decrescente:\n");
    for (int i = 0; i < 200; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}
