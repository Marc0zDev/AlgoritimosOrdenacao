#include <stdio.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[(baixo + alto) / 2]; // Pivô no meio
    int i = baixo - 1;
    int j = alto + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivo);

        do {
            j--;
        } while (arr[j] > pivo);

        if (i >= j) {
            return j;
        }

        trocar(&arr[i], &arr[j]);
    }
}

void ordenacaoRapida(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        ordenacaoRapida(arr, baixo, pi);
        ordenacaoRapida(arr, pi + 1, alto);
    }
}

int main() {
    int arr[10] = {64, 25, 12, 22, 11, 8, 6, 34, 18, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    ordenacaoRapida(arr, 0, n - 1);

    printf("Arranjo ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
