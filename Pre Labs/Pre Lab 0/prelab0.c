#include <stdio.h>

//function prototype
int counter(int array[], int size, int query);

int main(void)
{
    //Set variables then call function
    int size = 15;
    int array[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int query = 9;

    int count = counter(array, size, query);

    //print to check
    printf("count is: %d\n", count);
}

int counter(int array[], int size, int query)
{
    //Iterate through the array, adding to 'count' every time a value is >= query
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i] >= query)
        {
            count++;
        }
    }
    return count;
}