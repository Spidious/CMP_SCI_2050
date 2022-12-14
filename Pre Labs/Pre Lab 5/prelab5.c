#include <stdio.h>
#include <stdlib.h>



// #################### No Touch ##############################

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
Employee * getEmployeeByID(Employee *array, int empID);
int setEmpSalary(Employee *array, int empID, float salary);
int getEmpSalary(Employee *array, int empID, float *salary);
int setEmpJobType(Employee *array, int empID, int job);
int getEmpJobType(Employee *array, int empID, int *job);

int main(void){
    printf("%p\n", NULL);
    printf("%d\n", !NULL);
    FILE *fp = fopen("empData.txt", "r");
    if(fp == NULL){
        printf("Could not open file\n");
        return 0;
    }
    Employee *array = readEmployeeArray(fp);
    for(int i = 0; i< *(((int *)array)-1); i++) printf("%d, %d, %f\n", array[i].empID, array[i].jobType, array[i].salary);

    int imp = 3;
    setEmpSalary(array, imp, 20);
    printf("%f\n", getEmployeeByID(array, imp)->salary);
}

Employee * readEmployeeArray(FILE *fp){
    int count = 1;  // 1 because you want the first line included
    for(char c = getc(fp); c!= EOF; c = getc(fp)){  
        if(c=='\n') count++;        // Counting how many lines are in the file.
    }

    rewind(fp); // Move the file pointer back to the beginning of the file.
    Employee *array = createArray(8, sizeof(Employee));
    for(int i = 0; i<8; i++){
        fscanf(fp, "%d %d %f\n", &(array[i].empID), &(array[i].jobType), &(array[i].salary));
    }
    return array;
}

Employee * getEmployeeByID(Employee *array, int empID){
    for(int i = 0; i<*((int *)array -1); i++) if(array[i].empID == empID) return array+i;
    return NULL;
}

int setEmpSalary(Employee *array, int empID, float salary){
    getEmployeeByID(array, empID)->salary=salary;
    return(0);
}

