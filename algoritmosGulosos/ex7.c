#include <stdio.h>
#include <stdlib.h>

// Definição de uma aula
typedef struct {
    int inicio;
    int fim;
} Aula;

// Função de comparação para usar com qsort
int comparaAulas(const void *a, const void *b) {
    return ((Aula *)a)->fim - ((Aula *)b)->fim;
}

// Função para encontrar o maior número possível de aulas sem sobreposição
void escolherAulas(Aula aulas[], int n) {
    // Ordenar as aulas de acordo com o horário de término
    qsort(aulas, n, sizeof(Aula), comparaAulas);

    // Inicializar a contagem de aulas selecionadas
    int selecionadas = 0;

    // Inicializar o horário do último término de aula selecionada
    int ultimaFim = -1;

    // Iterar sobre as aulas
    for (int i = 0; i < n; i++) {
        // Se a aula não se sobrepõe com a última aula selecionada
        if (aulas[i].inicio >= ultimaFim) {
            // Incrementar o número de aulas selecionadas
            selecionadas++;
            // Atualizar o horário do último término de aula selecionada
            ultimaFim = aulas[i].fim;
            // Imprimir a aula selecionada
            printf("Aula (%d - %d)\n", aulas[i].inicio, aulas[i].fim);
        }
    }

    // Imprimir o total de aulas selecionadas
    printf("Total de aulas selecionadas: %d\n", selecionadas);
}

int main() {
    // Exemplo de conjunto de aulas
    Aula aulas[] = {{1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}, {7, 9}};
    int n = sizeof(aulas) / sizeof(aulas[0]);

    printf("Aulas disponiveis:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d - %d)\n", aulas[i].inicio, aulas[i].fim);
    }

    printf("\nSelecionando aulas:\n");
    escolherAulas(aulas, n);

    return 0;
}
