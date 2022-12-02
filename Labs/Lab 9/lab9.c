#include "lab9.h"

// Use Bubble Sort to sort the array from least to greatest
// takes a Runner pointer array and an integer size
void sortByAge(Runner *array, int size){
    // Create runner and go start bubble sort
    Runner hold;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            // if 2 values are in decending order then swap them
            if(array[j+1].age < array[j].age){
                hold = array[j];
                array[j] = array[j+1];
                array[j+1] = hold;
            }
        }
    }
}

// Uses recursion to find age in array
// takes runner pointer array, integer age, integer start and end index
// at the end returns the index for the age
// returns -1 on error
int findAge_R(Runner *array, int age, int startIndex, int endIndex){
    // find middle index
    int middleIndex = startIndex+(endIndex-startIndex)/2;

    if(age == array[middleIndex].age){  // check if it found the age
        return middleIndex;
    }
    else if(middleIndex == startIndex){ // only needed for the last element of the array
        return endIndex;
    }
    else if(age < array[middleIndex].age){  // check if age is less than
        return findAge_R(array, age, startIndex, middleIndex);
    } 
    else if(age > array[middleIndex].age){  // check if age is greater than
        return findAge_R(array, age, middleIndex, endIndex);
    }
    else{
        return -1;
    }
}

// get the index from an array by the age of its element.
// takes a runner pointer, integer size, and integer age
// returns the integer index at which is the runner with the age
// returns -1 on error
int getByAge(Runner *array, int size, int age){
    // call recursive function
    return findAge_R(array, age, 0, size-1);
}