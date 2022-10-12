#include "lab5.h"

int main(void){
    // create and test array
    int * array = createArray(20);
    if(!array) printf("fail\n");
    else printf("pass\n");

    // print array size to test getSize
    printf("size: %d\n", getSize(array));

    // fill array randomly
    for(int i = 0; i < getSize(array); i++) array[i] = rand() % 10;

    // print lastCalculation before sumThrees and after
    printLastCalculation(array);
    sumThrees(array);
    printLastCalculation(array);

    // free the array
    freeArray(array);
    return 0;
}

/* Create an integer array of size
Takes the desired size to be allocated
returns pointer to the array and hides an element of type "ArrayInfo" before the returned pointer */
int * createArray(int size){
    // create and check array
    ArrayInfo *array = malloc(size*sizeof(int)+sizeof(ArrayInfo));
    if(!array) return NULL;
    // initialize size and lastCalculation
    array[0].size = size;
    array[0].lastCalculation = 0;
    //return
    return (int *)(array+1);
}

/* Return the size of the array
takes a pointer to an integer array with a hidden ArrayInfo element
returns integer "size" stored in -1 element */
int getSize(int *array){
    return ((ArrayInfo *)array-1)->size;
}

/* Returns a pointer containing a pointer to ArrayInfo element
takes a pointer to an integer array with a hidden ArrayInfo element
returns pointer to elemetn with array info stored */
ArrayInfo * getInfo(int *array){
    return  ((ArrayInfo *)array-1);
}

/* prints the last calculation performed on the array
takes a pointer to an integer array with a hidden ArrayInfo element */
void printLastCalculation(int *array){
    printf("Last Calculation: %d\n", getInfo(array)->lastCalculation);
}


/* Saves the sum of all the 3's in the array to lastCalculation
takes pointer to an integer array with a hidden ArrayInfo element
saves the sum of all 3's to lastCalculation in ArrayInfo */
void sumThrees(int *array){
    // create count variable
    int count = 0;
    // iterate list and add array[i] to list    (I do it like this and not just add 3 because if
    //                                           <result>%3 != 0 then you know something is wrong)
    for(int i = 0; i < getInfo(array)->size; i++){
        if(array[i] == 3) count+=array[i];
    }
    getInfo(array)->lastCalculation = count;
}

/* Frees an integer array with a hidden ArrayInfo element
takes pointer to an integer array with a hidden ArrayInfo element */
void freeArray(int *array){
    free((ArrayInfo *)array-1);
}