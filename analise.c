#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
char* formatarMoeda(double valor);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pessoa vendedor;
    char linha[256];

    while (fgets(linha, sizeof(linha), stdin)) {
        obterVendedor(linha, &vendedor);
        liberarMemoria(&vendedor);
    }

    return 0;
}

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
        printf("%s, ", vendedor->codVenda);
    }
    token = strtok(NULL, ";");
    if (token != NULL) {
        vendedor->valVenda = atof(token);
        
        // Realizar cálculos com base no cargo
        if (strcmp(vendedor->cargo, "junior") == 0) {
            vendedor->valVenda += vendedor->valVenda * 0.01;
        } else if (strcmp(vendedor->cargo, "pleno") == 0) {
            vendedor->valVenda += vendedor->valVenda * 0.02;
        } else if (strcmp(vendedor->cargo, "senior") == 0) {
            vendedor->valVenda += vendedor->valVenda * 0.04;
        } else if (strcmp(vendedor->cargo, "gerente") == 0) {
            vendedor->valVenda += vendedor->valVenda * 0.05;
        }

        // Formatando o valor como moeda
        char *valorFormatado = formatarMoeda(vendedor->valVenda);
        printf("%s\n", valorFormatado);

        // Libere a memória alocada para o valor formatado
        free(valorFormatado);
    }
}

void liberarMemoria(Pessoa *vendedor) {
    free(vendedor->codVendedor);
    free(vendedor->nome);
    free(vendedor->cargo);
    free(vendedor->codEquipe);
    free(vendedor->codVenda);
}

// Função para formatar um valor double como moeda
char* formatarMoeda(double valor) {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "R$ %.2lf", valor);
    return strdup(buffer);
}
