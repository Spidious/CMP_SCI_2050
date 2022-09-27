#include <stdio.h>
#include <stdlib.h>

void * createArray(int n, int elemsize);
int getArraySize(void *array); 
void freeArray(void *array);

int main(void){
    double *array = createArray(22, sizeof(double));
    printf("%d\n", getArraySize(array));

    for(int i = 0; i < getArraySize(array); i++) array[i]=(double)(i+1);

    for(int i = 0; i < getArraySize(array); i++) printf("%f ", array[i]);
    printf("\n");
    freeArray(array);
}

void * createArray(int n, int elemsize){
    int * array = malloc(n*elemsize+sizeof(int));
    if(!array) return NULL;
    array[0] = n;
    return (void *)array+1;
}

int getArraySize(void *array){
    return *((int *)(array-1));
}

void freeArray(void *array){
    free(array-1);
}