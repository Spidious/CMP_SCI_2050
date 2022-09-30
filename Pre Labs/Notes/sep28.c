#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


int main(void){
    // abstraction
        // makes designer ask what...

        // Steering wheel is technically no longer relevant. It is not practical in all cases
        // Changing it would be dangerous, Companies would change it constantly and 
            // You do not want to have people figuring it out as they go.

    // collection ADTs
        // A colletion ADT (container) provides a means for storing a group of objects
        // Collection ADT "holds" or "contains" some number of objects.
    // Bag ADT
        // Bag is a collection of objects with few or no restrictions on content
        // Bag operations include
            // add item to bag
            // delete item from bag
            // check if item is in bag
            // check for full bag
    // Set ADT
    // List ADT
        // List is an indexed collection of objects. There is first object and a last object on the list
            // describe its data
            // specify the operations



    // Linked list (more like array, not an adt)
        // the word "list" is sometimes used to refer to the list ADT and is 
        // also sometimes used to refer to a data structure called a "linked List"

        // this is a data structure that is commonly used to implement the list ADT
        // important to understand the difference between.....


    struct Node *head = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = (struct Node *)malloc(sizeof(struct Node));

    head->next->data = 2;
    puts("test");

    printf("%d\n", head->next->data);
    return(0);
}