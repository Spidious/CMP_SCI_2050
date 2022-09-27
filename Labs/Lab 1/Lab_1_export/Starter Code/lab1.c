#include "lab1.h"

int getMin(int size, int *array, int *result)
{
    // Reset result
    *result = 0;

    // Test that size is at least 1
    if(size<=1)
    {
        return -1;
    }

    // Test if array is NULL, if not, set 'minSize' = first element, check if any other element is less than 'minSize'
    if(array != NULL)
    {
        int minSize = array[0];
        for(int i = 0; i < size-1; i++)
        {
            if(array[i]<minSize)
            {
                minSize = array[i];
            }
        }
        *result = minSize;
        // Return error code 0
        return 0;
    }
    else
    {
        // If array is NULL return -1
        return -1;
    }
}
