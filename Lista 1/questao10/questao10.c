#include <stdio.h>

int main(){
    char charType[4] = {'1234'};
    int intType[4] = {1,2,3,4};
    float floatType[4] = {1,2,3,4};
    double doubleType[4] = {1,2,3,4};
    for(int i = 0; i < 4; i++) {
        printf("char type position %d = %d\n", i, charType+i);
        printf("int type position %d = %d\n", i, intType+i);
        printf("float type position %d = %d\n", i, floatType+i);
        printf("double type position %d = %d\n", i, doubleType+i);
    }
    return 0;
}