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
        
        printf(", %.2lf\n", vendedor->valVenda);
    }
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
    return 0;
}