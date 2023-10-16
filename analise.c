#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *codVendedor;
    char *nome;
    char *cargo;
    char *codEquipe;
    char *codVenda;
    double valVenda;
} Pessoa;

void processarDados(Pessoa *vendedor);

int main() {
    Pessoa vendedor;
    char linha[256];

    while (fgets(linha, sizeof(linha), stdin)) {
        sscanf(linha, "%m[^,], %m[^,], %m[^,], %m[^,], %m[^,], %lf", &vendedor.codVendedor, &vendedor.nome, &vendedor.cargo, &vendedor.codEquipe, &vendedor.codVenda, &vendedor.valVenda);
        processarDados(&vendedor);
        free(vendedor.codVendedor);
        free(vendedor.nome);
        free(vendedor.cargo);
        free(vendedor.codEquipe);
        free(vendedor.codVenda);
    }

    return 0;
}

void processarDados(Pessoa *vendedor) {
    // Implemente a lógica de processamento dos dados aqui.
    // Por exemplo, você pode somar 2% ao valor da venda.
    vendedor->valVenda *= 1.02;
    // E, em seguida, imprimir os dados processados.
    printf("%s, %s, %s, %s, %s, %.2lf\n", vendedor->codVendedor, vendedor->nome, vendedor->cargo, vendedor->codEquipe, vendedor->codVenda, vendedor->valVenda);
}
