#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *codVendedor;
    char *nome;
    char *cargo;
    char *codEquipe;
    char *codVenda;
    double valVenda;
} Pessoa;

void obterVendedor(char *linha, Pessoa *vendedor);
void liberarMemoria(Pessoa *vendedor);

void obterVendedor(char *linha, Pessoa *vendedor) {
    char *token = strtok(linha, ";");
    if (token != NULL) {
        vendedor->codVendedor = strdup(token);
        printf("%s, ", vendedor->codVendedor);
    }
    token = strtok(NULL, ";");
    if (token != NULL) {
        vendedor->nome = strdup(token);
        printf("%s, ", vendedor->nome);
    }
    token = strtok(NULL, ";");
    if (token != NULL) {
        vendedor->cargo = strdup(token);
        printf("%s, ", vendedor->cargo);
    }
    token = strtok(NULL, ";");
    if (token != NULL) {
        vendedor->codEquipe = strdup(token);
        printf("%s, ", vendedor->codEquipe);
    }
    token = strtok(NULL, ";");
    if (token != NULL) {
        vendedor->codVenda = strdup(token);
        printf("%s", vendedor->codVenda);
    }
    token = strtok(NULL, ";");
    if (token != NULL) {
        vendedor->valVenda = atof(token);
        printf(", %.2lf\n", vendedor->valVenda);
    }
}

void lerArquivoCSV(char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[256]; 
    Pessoa *vendedor = (Pessoa *)malloc(sizeof(Pessoa));

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        obterVendedor(linha, vendedor);
    }

    fclose(arquivo);
    liberarMemoria(vendedor);
}

void liberarMemoria(Pessoa *vendedor) {
    free(vendedor->codVendedor);
    free(vendedor->nome);
    free(vendedor->cargo);
    free(vendedor->codEquipe);
    free(vendedor->codVenda);
    free(vendedor);
}

int main() {
    char nomeArquivo[] = "vendas.csv";
    lerArquivoCSV(nomeArquivo);
    return 0;
}