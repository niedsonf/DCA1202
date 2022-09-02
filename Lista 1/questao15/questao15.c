#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortArray(float *p, int n)
{
    float aux;
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            if (p[j] > p[i])
            {
                aux = p[j];
                p[j] = p[i];
                p[i] = aux;
            }
        }
    }
}



int main()
{
    clock_t begin = clock();
    void (*pFunc)(float *, int) = sortArray;
    int n = 0;
    float *p;
    printf("Insira a quantidade de numeros a serem armazenados:\n");
    scanf("%d", &n);
    p = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        printf("\nInsira o %d numero:\n", i + 1);
        scanf("%f", &p[i]);
    }
    pFunc(p, n);
    printf("\nArray ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", p[i]);
    }
    printf("\n");
    free(p);
    clock_t end = clock();
    double runTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos", runTime);
    printf("\n");
    return 0;
}
