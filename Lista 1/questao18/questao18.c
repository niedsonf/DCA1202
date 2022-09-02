#include <stdio.h>
#include <stdlib.h>

void multiply(int **a, int **b, int **c, int nla, int nca, int ncb)
{
    int counter = 0;
    for(int i=0; i<nla; i++){
        for(int j=0; j<ncb; j++){
            for(int k=0; k<nca; k++){
                counter += a[i][j+k] * b[j+k][i];
            }
            c[i][j] = counter;
            counter = 0;
        }
    }
}

void fillArray(int **a, int nl, int nc){
    for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            a[i][j] = rand() % 101;
        }
    }
}

void printArray(int **a, int nl, int nc){
    for(int i=0; i<nl; i++){
        for(int j=0; j<nc; j++){
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **a, **b, **c, nla, nca, ncb;

    printf("\nInsira o numero de linhas da primeira matriz:\n");
    scanf("%d", &nla);
    printf("\nInsira o numero de colunas da primeira matriz:\n");
    scanf("%d", &nca);
    printf("\nInsira o numero de colunas da segunda matriz:\n");
    scanf("%d", &ncb);

    a = malloc(nla * sizeof(int *));
    b = malloc(nca * sizeof(int *));
    c = malloc(nla * sizeof(int *));
    a[0] = malloc(nla * nca * sizeof(int));
    b[0] = malloc(nca * ncb * sizeof(int));
    c[0] = malloc(nla * ncb * sizeof(int));

    for (int i = 1; i < nla; i++)
    {
        a[i] = a[i - 1] + nca;
        c[i] = c[i - 1] + ncb;
    }
    for (int i = 1; i < nca; i++)
    {
        b[i] = b[i - 1] + ncb;
    }

    fillArray(a, nla, nca);
    fillArray(b, nca, ncb);

    multiply(a,b,c,nla,nca,ncb);

    printf("\n");
    printf("A =\n");
    printArray(a,nla,nca);

    printf("\n");
    printf("B =\n");
    printArray(b,nca,ncb);

    printf("\n");
    printf("C =\n");
    printArray(a,nla,ncb);

    printf("\n");
    return 0;
}