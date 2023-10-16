#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s", argv[0]);
        return 1;
    }

    char *nomeArquivo = argv[1];
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Processar cada linha do arquivo CSV aqui
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
