#include<stdio.h>
#include<stdlib.h>

void *createStack(int size, int typeSize);

int main(void){
    int stack = createStack(10, sizeof(int));
    
}

void *createStack(int size, int typeSize){
    int *stack = malloc(size*typeSize+sizeof(int));
    if(!stack) return NULL;
    
    stack[-1] = size;
    return (void *)(size-1);
}
