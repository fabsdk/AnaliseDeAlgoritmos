#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma tarefa
struct Tarefa {
    int inicio, fim;
};

// Função para comparar duas tarefas por tempo de término
int comparar(const void *a, const void *b) {
    return ((struct Tarefa*)a)->fim - ((struct Tarefa*)b)->fim;
}

// Função para encontrar o máximo número de tarefas que podem ser realizadas sem sobreposição
void agendarTarefas(struct Tarefa arr[], int n) {
    // Ordenar as tarefas por tempo de término
    qsort(arr, n, sizeof(struct Tarefa), comparar);

    int i = 0;
    printf("Tarefas selecionadas:\n");
    printf("(%d, %d)", arr[i].inicio, arr[i].fim);

    // Iterar sobre as tarefas restantes
    for (int j = 1; j < n; j++) {
        // Se a tarefa atual não se sobrepõe com a tarefa selecionada anteriormente, selecioná-la
        if (arr[j].inicio >= arr[i].fim) {
            printf(", (%d, %d)", arr[j].inicio, arr[j].fim);
            i = j;
        }
    }
}

int main() {
    struct Tarefa arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    agendarTarefas(arr, n);
    return 0;
}
