#include <stdio.h>
#include <stdlib.h>


float** criarMatriz(int linhas, int colunas) {
    float** matriz = malloc(linhas * sizeof(float*));
    
    if (matriz == NULL) {
        perror("Erro ao alocar a matriz");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(float));

        if (matriz[i] == NULL) {
            perror("Erro ao alocar a matriz");
            exit(EXIT_FAILURE);
        }
    }

    return matriz;
}

float resistenciaEquivalente(float R1, float R2){
    // Evitar a divisão por zero
    if (R1 == 0 || R2 == 0) {
        printf("As resistências não podem ser zero.\n");
        return -1; // Indica erro
    }

    // Calcular a resistência equivalente
    float Re = 1.0 / ((1.0 / R1) + (1.0 / R2));

    return Re;
}


//receber a entrada e criar uma matriz com os dados no formato a seguir
float **receberDados() {
    FILE *arquivo = fopen("entrada.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);  // Encerra o programa em caso de erro
    }

    char caractere;
    int strings = 0;

    char **vetorString = malloc(1 * sizeof(char*));
    vetorString[0] = malloc(1);  // Alocando espaço inicial para a primeira string

    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == ';') {
            strings++;
            vetorString = realloc(vetorString, (strings + 1) * sizeof(char*));
            vetorString[strings] = malloc(1);  // Alocando espaço para a próxima string
            continue;
        }

        // Adicionando o caractere à string
        size_t comprimento = strlen(vetorString[strings]);
        vetorString[strings] = realloc(vetorString[strings], (comprimento + 2) * sizeof(char));
        vetorString[strings][comprimento] = caractere;
        vetorString[strings][comprimento + 1] = '\0';  // Adiciona o terminador nulo
    }
    fclose(arquivo);

    float **matrizPrimaria=criarMatriz(3,strings);
    for(int i=0;i<strings;i++){
        sscanf(vetorString[i],"%d: [%d,%d]",matrizPrimaria[i][0],matrizPrimaria[i][1],matrizPrimaria[i][2]);
    }

    return matrizPrimaria;
}
//resistor    0 | 1| 2|
//posicao0    tn|tn|tn|
//posicao1    tn|tn|tn|
//resistencia n | n| n|

//resolver as paralela 
//criar a matriz com os dados restantes


int main(){
    float **matrizEntrada=receberDados();
    int quantResistores = sizeof(matrizEntrada[0]) / sizeof(matrizEntrada[0][0]),coluna=0,j=0;
    float **matrizListaResistores=criarMatriz(3,quantResistores);
    for(int i=0;i<quantResistores;i++){
        for(;j<quantResistores;j++){
            if(j!=i && matrizEntrada[0][i]==matrizEntrada[0][j] && matrizEntrada[1][i]==matrizEntrada[1][j]){
                matrizListaResistores[0][coluna]=matrizEntrada[0][i];
                matrizListaResistores[1][coluna]=matrizEntrada[1][i];
                matrizListaResistores[2][coluna]=resistenciaEquivalente(matrizEntrada[2][i],matrizEntrada[2][j]);
                coluna++;
            }
        }
        j=i+1;
    }
     for (int i = 0; i < 3; i++) {
        matrizListaResistores[i] = realloc(matrizListaResistores[i], coluna * sizeof(float));

        if (matrizListaResistores[i] == NULL) {
            perror("Erro ao redimensionar a matriz");
            exit(EXIT_FAILURE);
        }
    }

    
    float **matrizPrincipal=criarMatriz(coluna+2,coluna+2);//adicao de pontos extras pra se caso for necessario
    for(int i=0;i<coluna;i++){
        int ponto1=matrizListaResistores[0][i],
        ponto2=matrizListaResistores[1][i];
        float resistencia=matrizListaResistores[2][i];

        matrizPrincipal[ponto1][ponto2]=resistencia;
        matrizPrincipal[ponto2][ponto1]=resistencia;
    }

    
    

}