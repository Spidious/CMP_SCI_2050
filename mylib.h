#include <stdio.h>
#include <stdlib.h>

#define pass (void)0    // null argument to do nothing, nicer than just a ";".



/*Create an array of size 'arraySize' with the size of the array stored in the -1 position.
'dataTypeSize' must be the size of the desired datatype.

"int arraySize":
Desired number of values for the array
Stored in [-1]

"int dataTypeSize":
Size of the data type to be allocated
Stored in [-2]
*/
void * createArray(int arraySize, int dataTypeSize){ 
    int *array;
    array = (int *)malloc(arraySize*dataTypeSize+(2*sizeof(int))); // create array of size array, type data type.
    if(!array) return NULL;

    array[0] = dataTypeSize;
    array[1] = arraySize;   // save both size and type size
    return (void *)(array+2); // return pointer 
}


/*Return the size of an array
Same as using { array[-1] } or { *((int *)array-1) }
*/
int getArraySize(void * array){
    int arraySize = *(((int *)array)-1);
    return arraySize;
}


/*Free an array created by createArray(), or any array with an int offset of +2.

"void *array":
An array of any type to be passed into the free function.
*/
void freeArray(void * array){
    free((int*)array-2);
}


/*
void * initArray(void *array){
    int *tempArray = (int *)array; // Turn array into an int for handling
    int arraySize = *((int *)array-1), dataSize = *((int *)array-2);
    //printf("%p  %p\n%p  %p\n", tempArray, ((void *)tempArray+1), &(tempArray[0]), &(tempArray[1]));
    return NULL;
    for(int i = 0; i<arraySize; i++) *(tempArray+i) = 8;
    return (void *)tempArray;
}


void * printArray(void * array){
    int *tempArray = (int *)array; // Turn array into an int for handling
    
    printf("%d\n", tempArray[-1]);
    
    for(int i = 0; i<tempArray[-1]; i++) printf("%d, ",tempArray[i]);
    printf("\n");
}
*/
