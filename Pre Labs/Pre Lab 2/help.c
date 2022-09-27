#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *array;
    int size = 50;
    array = malloc(size * sizeof(int));

    printf("%ld\n", sizeof(array));

    free(array);
}