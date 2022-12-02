#include "lab9.h"

#define SIZE 10

int main(void){
    Runner * array = malloc(SIZE * sizeof(Runner));
    if(!array) return 1;
    for(int i = SIZE; i > 0; i--) array[SIZE-i].age = i;

    sortByAge(array, SIZE);

    for(int i = 1; i <= SIZE; i++){
        printf("array %d: %d\n", i, getByAge(array, SIZE, i));
    }
}