#include "lab2.h"

/* 
makeArry function
Create an array and dynamically allocate memory
Check if the malloc function worked, if not exit
set each value to 0
return the final array
*/
int * makeArray(int size)
{
    // Initialize array and allocate memory in one step.
    int *array = malloc(size*sizeof(int));

    // Check if malloc worked
    // If not, quit
    if(!array) exit(-1);

    // Initialize each element to 0
    for(int i = 0; i < size; i++) array[i] = 0;

    return array;
}

/*
fillTwos
Fills an array from 0 in multiples of 2
*/
void fillTwos(int *array, int size)
{
    // Create the twos value and itterate through array
    int val = 0;
    for(int i = 0; i < size; i++)
    {
        // Set the i'th element of array to val, increase val by 2
        array[i] = val;
        val+=2;
    }
}

/*
freeArray
free an array and set pointer to null.
*/
void freeArray(int **array)
{
    //Free and set to NULL
    free(*array);
    *array = NULL;
}