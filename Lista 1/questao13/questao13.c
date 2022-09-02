#include <stdio.h>
#include <stdlib.h>

void sortArray(float *p, int *n) {
    float aux;
    for(int j=0; j<*n-1; j++){
        for(int i=j+1; i<*n; i++){
            if(p[j] > p[i]){
                aux = p[j];
                p[j] = p[i];
                p[i] = aux;
            }
        }
    }
}

int main()
{
    int *n;
    float *p;
    printf("Insira a quantidade de numeros a serem armazenados:\n");
    scanf("%d", n);
    p = malloc(*n*sizeof(float));
    for(int i=0; i<*n; i++){
        printf("\nInsira o %d numero:\n", i+1);
        scanf("%f", &p[i]);
    }
    sortArray(p, n);
    printf("\nArray ordenado:\n");
    for(int i=0; i<*n; i++) {
        printf("%.2f ", p[i]);
    }
    printf("\n\n");
    free(p);
    return 0;
}
