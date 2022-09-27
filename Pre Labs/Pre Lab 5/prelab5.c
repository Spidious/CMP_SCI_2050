#include <stdio.h>
#include <stdlib.h>

// ##################################################################

void * createArray(int arraySize, int dataTypeSize){ 
    int *array;
    array = (int *)malloc(arraySize*dataTypeSize+(2*sizeof(int))); // create array of size array, type data type.
    if(!array) return NULL;

    array[0] = dataTypeSize;
    array[1] = arraySize;   // save both size and type size
    return (void *)(array+2); // return pointer 
}

int getArraySize(void * array){
    int arraySize = *(((int *)array)-1);
    return arraySize;
}

void freeArray(void * array){
    free((int*)array-2);
}


// ##################################################################

typedef struct employee{ // Employee Struct
    int empID, jobType; 
    float salary; 
} Employee;

Employee * readEmployeeArray(FILE *fp);
Employee * getEmployeeByID(Employee *, int empID);

int main(void){
    Employee jeff;
}

Employee * readEmployeeArray(FILE *fp){
    
}
