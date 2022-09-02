#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printArray(unsigned int **a) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf(" %d", a[i][j]);
    }
    printf("\n");
  }
}

void fillArray(unsigned int **a) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      a[i][j] = rand() % 2;
    }
  }
}

void printArrayInBits(unsigned int *pa, unsigned long *py) {
  unsigned char *pAux = (unsigned char *)py;
  int counter = 7;

  for (int i = 0; i < 64; i++) {
    if (counter < 0)
      counter = 7;
    if (pa[i] & 1) {
      printf("1");
      pAux[(int)i / 8] += pow(2, counter);
      //*py += pow(2, 63 - i);
    } else
      printf("0");
    counter--;
  }
  printf("\n Linha 1 %d \n", pAux[0]);
  printf("\n Linha 2 %d \n", pAux[1]);
  printf("\n Linha 3 %d \n", pAux[2]);
  printf("\n Linha 4 %d \n", pAux[3]);
  printf("\n Linha 5 %d \n", pAux[4]);
  printf("\n Linha 6 %d \n", pAux[5]);
  printf("\n Linha 7 %d \n", pAux[6]);
  printf("\n Linha 8 %d \n", pAux[7]);
}

int main() {
  unsigned int **a;
  unsigned long y = 0;

  a = malloc(8 * sizeof(unsigned int *));
  a[0] = malloc(64 * sizeof(unsigned int));

  for (int i = 1; i < 8; i++) {
    a[i] = a[i - 1] + 8;
  }

  fillArray(a);
  printf("\n");
  printf("Matriz Original: \n");
  printArray(a);
  printf("\n");
  printArrayInBits(&a[0][0], &y);
  printf("\n");
  printf("%u", y);
  printf("\n");
}
