#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int main(int arg, char *args[]){
    assert(arg>1); // There must be at least 1 argument
    for(int i = 0; i< arg; i++){
        printf("test\n");
    }
}