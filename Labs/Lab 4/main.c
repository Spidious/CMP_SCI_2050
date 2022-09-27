#include <stdio.h>
#include <stdlib.h>
#include "lab4.c"

int main(void){
    short *array = createArray(10);
    for(int i = 0; i<10; i++) array[i] = i;
    for(int i = 0; i<10; i++) printf("%d ", array[i]);
    printf("\n");

    printf("array size: %d\n", getSize(array));

    printf("greater than 5: %d\n", countGreater(array, 5));

    freeArray(array);
}