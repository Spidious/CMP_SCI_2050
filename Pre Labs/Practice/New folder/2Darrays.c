#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"



void testy(void){
    int n = 7, j = 20; // height, width

    int **array = malloc(n*sizeof(int *)); //Create array of pointers
    for(int i = 0; i< n; i++) array[i] = malloc(j*sizeof(int)); //iterate through array of pointers and allocate pointers
    for(int i = 0; i< n; i++) for(int x = 0; x < j; x++) array[i][x] = 0; //Iterate through 2d array and initialize each variable
    
    for(int i = 0; i< n; i++){
        for(int x = 0; x < j; x++){
            printf("%d ", array[i][x]); // Print each variable in 2d array
        }
        printf("\n");
    }


    for(int i = 0; i< n; i++) free(array[i]); //iterate through array of arrays and free each array
    free(array); // Free first dimension array

    printf("\n");

    printf("%d\n", array[n][j]); // Should return segmentation fault
}

int main(void){
    int width = 10, height = 5;
    int **array = createArray(height, sizeof(int *));
    for(int i = 0; i < height; i++) array[i] = createArray(width, sizeof(int));
}