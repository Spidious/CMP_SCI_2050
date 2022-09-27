#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
float * readFloatFileIntoArray(FILE *fptr, int *length);
void freeFloatArray(float *arr);

// Main Function
int main(void)
{
    // Create fptr and length
    FILE* fptr = NULL;
    int length;

    // Call first function
    float *array = readFloatFileIntoArray(fptr, &length);

    // Print full array
    for(int i = 0; i< length; i++) printf("%f\n", array[i]);

    // Free array
    freeFloatArray(array);

}

// readFloatFileIntoArray function
float * readFloatFileIntoArray(FILE *fptr, int *length)
{
    // Open file and get size
    fptr = fopen("file.txt", "r");
    fscanf(fptr, "%d\n", length);
    float *array = malloc(*length*sizeof(float));

    // Check malloc worked
    if(!array)
    {
        puts("Unable to allocate memory\n");
        exit(-1);
    }

    // Load rest of file into array
    for(int i = 0; i < *length; i++)
    {
        fscanf(fptr, "%f\n", &array[i]);
    }
    
    // Close file and return array
    fclose(fptr);
    return array;
}

// freeFloatArray function
void freeFloatArray(float *arr)
{
    // Free and set to NULL
    free(arr);
    arr = NULL;
}