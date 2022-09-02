#include <stdio.h>

void swap(int *q, int *w){
    int aux = *q;
    *q = *w;
    *w = aux;
}

int main() {
    int a=1, b=2;
    printf("a value: %d | b value: %d\n", a, b);
    swap(&a, &b);
    printf("a value: %d | b value: %d\n", a, b);
    return 0;   
}