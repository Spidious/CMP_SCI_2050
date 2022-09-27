#include "lab3.h"

/* Create array of size and initialize each element 1 through 9 inclusive
return the pointer to that array
*/
int * makeArray(int size){
    // Create array of size and check that malloc worked, if not return null.
    int *array = malloc(size*sizeof(int));
    if(!array) return NULL;

    // Initialize each array element
    for(int i = 0; i < size; i++) array[i] = rand()%9;

    // Return pointer
    return array;
}

// Offset the array by the value passed to 'offset'
int * offsetArray(int *array, int offset){
    // return the pointer 'offset' before array
    return array-offset;
}

// Print the index of every value that is equal to 5
void printFives(int *array, int size, int offset){
    // iterate through array and print the index if the value of array[i] is equal to 5
    for(int i = offset; i < (size+offset); i++) if(array[i] == 5) printf("%d, ", i);
    printf("\n");
}

// Free the passed array by using the offset
void freeArray(int *array, int offset){
    // Free array
    free(array+offset);
}