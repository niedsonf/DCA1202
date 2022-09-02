#include <stdio.h>
#include <stdlib.h>

void vectorSum(int *a, int *b, int *c, int n){
    for(int i=0; i<n; i++){
        c[i] = a[i] + b[i];
    }
}

void printVector(int *a, int n){
    printf("[");
    for(int i=0; i<n; i++){
        printf(" %d", a[i]);
    }
    printf(" ]\n");
}

int main(){
    int n=0;
    int *a, *b, *c;
    printf("\nInsira o tamanho dos vetores:\n");
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    b = malloc(n * sizeof(int));
    c = malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        a[i] = rand();
        b[i] = rand();
    }
    vectorSum(a,b,c,n);
    printf("\nResultado da soma: C = A+B\n");
    printf("A = ");
    printVector(a,n);
    printf("B = ");
    printVector(b,n);
    printf("C = ");
    printVector(c,n);
    printf("\n");
    free(a);
    free(b);
    free(c);
    return 0;
}