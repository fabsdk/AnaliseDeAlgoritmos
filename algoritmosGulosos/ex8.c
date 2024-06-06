#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void divisaoNumeros(int numero) {
    int numeroOriginal = numero;
    int numeroDividido[100];
    int indice = 0;

    for (int i = 0; i < 100; i++) {
        numeroDividido[i] = 0;
    }

    while (numero > 0) {
        int raiz = sqrt(numero);
        numeroDividido[indice] = raiz * raiz;
        indice++;

        numero -= raiz * raiz;
    }

    // Imprimir o resultado
    printf("Numero original: %d\n", numeroOriginal);
    printf("Conjunto de numeros divididos: ");
    for (int i = 0; i < 100 && numeroDividido[i] != 0; i++) {
        printf("%d ", numeroDividido[i]);
    }
    printf("\n");
}

int main() {
    int numero = 23;
    divisaoNumeros(numero);

    return 0;
}
