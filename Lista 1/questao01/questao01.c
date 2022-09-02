#include <stdio.h>

int main(void)
{
    int i = 3, j = 5;
    int *p, *q;
    p = &i;
    q = &j;
    printf("valor = %d", 3 - *p/(*q) +7);
    return 0;
}
