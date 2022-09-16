#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Percorre a matriz item a item e imprime o valor de cada elemento
void printArray(unsigned int **a) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf(" %d", a[i][j]);
    }
    printf("\n");
  }
}

//Percorre a matriz item a item e define randomicamente o valor de 0 ou 1 a cada elemento
void fillArray(unsigned int **a) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      a[i][j] = rand() % 2;
    }
  }
}


void printArrayInBits(unsigned int **pa, unsigned long long int *py) {
  //Cria um ponteiro auxiliar para analisar byte a byte o array uint
  unsigned char *pAux = (unsigned char *)py;
  int counter = 7;

  //A conversão binário-decimal de cada linha da matriz é calculada a partir de um contador que reseta a cada byte
  printf("Matriz no formato linear:\n");
  for (int i = 0; i < 64; i++) {
    if (counter < 0) {
      printf(" ");
      counter = 7;
    }
    if (pa[0][i] & 1) {
      printf("1");
      pAux[(int)i / 8] += pow(2, counter);
      //*py += pow(2, 63 - i);
    } else
      printf("0");
    counter--;
  }
  printf("\n\nLinha 1 %d \n", pAux[0]);
  printf("\nLinha 2 %d \n", pAux[1]);
  printf("\nLinha 3 %d \n", pAux[2]);
  printf("\nLinha 4 %d \n", pAux[3]);
  printf("\nLinha 5 %d \n", pAux[4]);
  printf("\nLinha 6 %d \n", pAux[5]);
  printf("\nLinha 7 %d \n", pAux[6]);
  printf("\nLinha 8 %d \n", pAux[7]);
}

int main() {
  unsigned int **a;
  unsigned long long int y = 0;

  //Aloca o bloco auxiliar e o tamanho necessário para todos os elementos da matriz
  a = malloc(8 * sizeof(unsigned int *));
  a[0] = malloc(64 * sizeof(unsigned int));

  //Redefine os endereços de cada posição do ponteiro, tomando como referencia o endereço anterior e somando 8 elementos a frente
  for (int i = 1; i < 8; i++) {
    a[i] = a[i - 1] + 8;
  }

  fillArray(a);
  printf("\n");
  printf("Matriz Original: \n");
  printArray(a);
  printf("\n");
  printArrayInBits(&a[0], &y);
  printf("\n");
  printf("Valor decimal de Y: %llu", y);
  printf("\n\n");

  //Liberação da memória alocada
  free(a[0]);
  free(a);
  return 0;
}