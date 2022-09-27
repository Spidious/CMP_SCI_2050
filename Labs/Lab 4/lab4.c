#include <stdio.h>
#include <stdlib.h>


/* Create a short type array of size
Takes an integer value to determine how much memory to allocate
Returns a short integer array of size with size located in array[-1]
*/
short * createArray(int size){
    // Create an array with malloc and check it worked
    int *array;
    array = (int *)malloc(size*sizeof(short)+sizeof(int));
    if(!array) return NULL;

    // store the size of hte array and return the 2nd position as the first
    array[0] = size;
    return (short *)(array+1);
}

/* Return the size of a passed short array
Takes a short integer array and accesses its integer '-1' position
Returns the stored integer as an int
*/
int getSize(short * array){
    int arraySize = *(((int *)array)-1);
    return arraySize;
}

/* Count how many values in a short array are greater than the query value
takes a short int array with a stored size in '-1' position
takes an integer value for each value of array to be checked against
returns the count of how many values are greater than array
*/
int countGreater(short *array, int query){
    // Create a count variable
    int count = 0;
    // iterate and check each value, if greater add to count
    for(int i = 0; i < *((int *)array-1); i++){
        if(array[i]>query) count++;
    }
    // return count
    return count;
}

/* Frees a passed short array
takes a short int array that was declared by malloc and has offset of '-1'
*/
void freeArray(short *array){
    // Free array adjusted for integer offset
    free((int *)array-1);
}

