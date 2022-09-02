#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    clock_t begin = clock();
    int n;
    float *p;
    printf("Insira a quantidade de numeros a serem armazenados:\n");
    scanf("%d", &n);
    p = malloc(n*sizeof(float));
    for(int i=0; i<n; i++){
        printf("\nInsira o %d numero:\n", i+1);
        scanf("%f", &p[i]);
    }
    qsort(p, n, sizeof(float), compare);
    printf("\nArray ordenado:\n");
    for(int i=0; i<n; i++) {
        printf("%.2f ", p[i]);
    }
    printf("\n\n");
    free(p);
    clock_t end = clock();
    double runTime = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos", runTime);
    printf("\n\n");
    return 0;
}
