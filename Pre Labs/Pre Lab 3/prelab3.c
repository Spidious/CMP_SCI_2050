#include <stdio.h>
#include <stdlib.h>

double * createDoubleArray(int minIndex, int maxIndex);
void freeArray(double ** array, int minIndex);

int main(void){
    int min = 1900;
    int max = 2000;

    double *array = createDoubleArray(min, max);

    
    double count = 0;
    for(int i = 0; i <= 100; i++){
        array[i] = count;
        count+= 0.5;
    }   

    printf("test\n");
    //for(int i = 0; i <= 100; i++) printf("val %d: %f\n", i, array[i]);

    freeArray(&array, 0);
    printf("%f\n", array[50]);
}

/*
    Create a double array with indexes minIndex to maxIndex
    Set array of size and return the address minIndex before array[0]
*/
double * createDoubleArray(int minIndex, int maxIndex){
    // Initialize array variable and size variable (the difference of max and min index)
    // Allocate memory to the array
    double *array;
    int size = (maxIndex-minIndex);

    //printf("size = %d\n", (int)size);
    array = malloc(((int)size*sizeof(double))+sizeof(int));
    if(!array) return NULL;
    //printf("test\n");

    // Set size variable and iterate array, return the address minus minIndex
    array[0] = size;
    array++; //array-=minIndex;
    return array;
}

void freeArray(double ** array, int minIndex){
    free(*array+(minIndex-1));
    array = NULL;
}