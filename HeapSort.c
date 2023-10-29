#include <stdio.h>
#define max 10

void peneira(int *vet, int raiz, int fundo) {
  int pronto, filhoMax, tmp;

  pronto = 0;
  while ((raiz * 2 <= fundo) && (!pronto)) {
    if (raiz * 2 == fundo) {
      filhoMax = raiz * 2;
    } else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
      filhoMax = raiz * 2;
    } else {
      filhoMax = raiz * 2 + 1;
    }

    if (vet[raiz] < vet[filhoMax]) {
      tmp = vet[raiz];
      vet[raiz] = vet[filhoMax];
      vet[filhoMax] = tmp;
      raiz = filhoMax;

      printf("Vetor após troca: ");
      for (int i = 0; i < max; i++) {
        printf("%d ", vet[i]);
      }
      printf("\n");
    } else {
      pronto = 1;
    }
  }
}

void heapsort(int *vet, int n) {
  int i, tmp;

  for (i = (n / 2); i >= 0; i--) {
    peneira(vet, i, n - 1);
  }

  for (i = n - 1; i >= 1; i--) {
    tmp = vet[0];
    vet[0] = vet[i];
    vet[i] = tmp;
    peneira(vet, 0, i - 1);

    printf("Vetor após troca: ");
    for (int j = 0; j < max; j++) {
      printf("%d ", vet[j]);
    }
    printf("\n");
  }
}

int main() {
  int vetor[max] = {5, 2, 7, 8, 10, 6, 1, 4, 9, 3};
  int i;
  heapsort(vetor, max);

  printf("Vetor ordenado: ");
  for (i = 0; i < max; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  return 0;
}
