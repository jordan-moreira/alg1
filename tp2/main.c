#include <stdio.h>
#include <stdlib.h>


int** criarMatriz(int linhas, int colunas) {
    int** matriz = malloc(linhas * sizeof(int*));
    
    if (matriz == NULL) {
        perror("Erro ao alocar a matriz");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * sizeof(int));

        if (matriz[i] == NULL) {
            perror("Erro ao alocar a matriz");
            exit(EXIT_FAILURE);
        }
    }

    return matriz;
}




//receber a entrada e criar uma matriz com os dados no formato a seguir
int **receberDados() {
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

    int **matrizPrimaria=criarMatriz(3,strings)
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
    int **matrizPrimaria=receberDados(),
    colunas = sizeof(matrizPrimaria[0]) / sizeof(matrizPrimaria[0][0]);
    for(int i=0;i<colunas;i++){
        for(int j=0;j<colunas;j++){
            if(j!=i && matrizPrimaria[0][i]==matrizPrimaria[0][j] && matrizPrimaria[1][i]==matrizPrimaria[1][j]){
                
            }
        }
    }



    int **matrizSecundaria=criarMatriz();

    
    

}