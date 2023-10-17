#include <stdio.h> //Para entrada e saída
#include <stdlib.h> //Para funções de alocação de memória
#include <string.h> //Para manipulação de Strings

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s", argv[0]);
        return 1;
    }

    char *nomeArquivo = argv[1];
    FILE *arquivo = fopen(nomeArquivo, "r"); //abre o arquivo para leitura, assume que o segundo arg é o nome do arquivo

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");  //Mensagem de erro
        return 1;
    }

    char linha[256]; //definindo tamanho maximo da linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        //Processar as linhas do arquivo csv
        for (int i = 0; i < strlen(linha); i++) {
            if (linha[i] == ',') {
                linha[i] = ' '; // Substituir ';' por espaço em branco
            }
        }
        printf("%s", linha);
    }

    fclose(arquivo);
    return 0;
}
