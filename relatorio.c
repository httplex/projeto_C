#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo = fopen("relatorio.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        fprintf(arquivo, "%s", linha);
    }

    fclose(arquivo);
    return 0;
}
