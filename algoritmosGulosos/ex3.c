#include <stdio.h>

typedef struct {
    int valor;
    int peso;
} Item;

void ordenar(Item *itens, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)itens[j].valor / itens[j].peso > (float)itens[i].valor / itens[i].peso) {
                Item temp = itens[i];
                itens[i] = itens[j];
                itens[j] = temp;
            }
        }
    }
}

void empacotamento(Item *itens, int n, int capacidade) {
    ordenar(itens, n);

    int pesoAtual = 0;
    for (int i = 0; i < n; i++) {
        if (pesoAtual + itens[i].peso <= capacidade) {
            printf("Item %d foi adicionado ao pacote.\n", i);
            pesoAtual += itens[i].peso;
        }
    }
}

int main() {
    Item itens[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(itens) / sizeof(itens[0]);
    int capacidade = 50;

    empacotamento(itens, n, capacidade);

    return 0;
}
