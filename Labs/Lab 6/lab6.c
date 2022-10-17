#include "lab6.h"

// testing my code
int main(void){
    // Creating the array
    Student *arr = createArray(100);

    //Just to put something in the array, filling it with random numbers so I don't have to.
    for(int i = 0; i < getSize(arr); i++){
        arr[i].gpa = (float)(rand()%400)/100;
        arr[i].id = rand()%1000;
    }

    // Call getMaxID and print results (using getGPA because it was unused)
    Student *student = getMaxID(arr);
    printf("%.2f\n%d\n", getGPA(student), getID(student));
}



/* Create an Student array of size
Takes the desired size to be allocated
returns pointer to the array and hides an element of type int before the returned pointer */
Student * createArray(int size){
    // create and check array
    int *array = malloc(size*sizeof(Student)+sizeof(int));
    if(!array) return NULL;
    // initialize size and lastCalculation
    array[0] = size;
    //return
    return (Student *)(array+1);
}

/* Return the size of the array
takes a pointer to an integer array with a hidden int element
returns integer "size" stored in -1 element */
int getSize(Student *array){
    return ((int *)array)[-1];
}

/* Return the pointer to a student struct in an array
takes a student array and an integer index*/
Student * getStudent(Student *array, int index){
    return array+index;
}

/* returns the gpa of a given student pointer
takes Student pointer varaible*/
float getGPA(Student *s){
    return s->gpa;
}

/* returns the id of a given student pointer
takes Student pointer varaible*/
int getID(Student *s){
    return s->id;
}

/* returns the pointer to a student variable with the highest ID in an array
takes a student array*/
Student * getMaxID(Student *array){
    // Create variables to hold index of highest id, the starting id, and variable for newID;
    int index = 0, id = getID(getStudent(array, 0)), newID;

    for(int i = 1; i < getSize(array); i++){
        // Set newID to current id and compare to current highest id
        newID = getID(getStudent(array, i));
        if(newID > id){
            // Set id to newID for further checking, Save index of the new high
            id = newID;
            index = i;
        }
    }
    
    return array+index;
}

/* Frees a student array with hidden size element of type int
takes Student array*/
void freeArray(Student *array){
    free(((int *)array)-1);
}

