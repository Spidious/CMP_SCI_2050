#include"lab7.h"


// Create a list containing a dummy node and return a pointer to that list
// Will return NULL upon failure
Node * makeList(){
    // Allocate and check
    Node * node = malloc(sizeof(Node *));
    if(!node) return NULL;
    // set data to null and return
    node->next = NULL;
    node->data = NULL;
    return node;
}

// Will return the size of a linked list containing a dummy node
// Takes a pointer to the dummy node
// returns an integer equal to the size of the linked list
int getSize(Node *head){
    // Set node to the first element after head and create count
    Node *node = head->next;
    int count = 0;
    // Count nodes
    while(node!=NULL){
        count++;
        node = node->next;
    }
    return count;
}


// Insert a node at the given index
// Takes a Node pointer to the head of a list
// Takes a void pointer to something that is entered into the list
// Takes an integer index
// Returns 0 on success and 1 on failure
int insertAtIndex(Node *head, void *data, int index){
    // check valid index
    if((index < 0)||(index > getSize(head))) return 1;
    // Create required variables
    int size = getSize(head);
    Node *indexNode = head;
    Node *newNode = malloc(sizeof(Node *));
    if(!newNode) return 1;  // Check newNode

    // check if end of list and get node before index
    if(index == size-1) for(int i = 0; i < size-1; i++) indexNode = indexNode->next;
    for(int i = 0; i < index; i++) indexNode = indexNode->next;

    // Change and set next and data variables
    newNode->next = indexNode->next;
    indexNode-> next = newNode;
    newNode->data = data;

    return 0;
}

// Returns the data of the 0th element and removes it
// takes a pointer to the head node
// returns NULL if list is empty and the data if it exists
void * removeFromHead(Node *head){
    // check if list is empty
    if(head->next == NULL) return NULL;
    // Create Node and Void varaibles to hold the 1th element and the data of the 0th element
    Node *hold = head->next->next;
    void * data = head->next->data;
    // free the 0th element and set the 1th element to be the 0th element
    free(head->next);
    head->next = hold;
    // return the held data
    return data;
}

// Get the void pointer value of the data stored at the index
// takes a pointer to the head node
// takes an integer index
// returns NULL if index invalid and the data if successful
void * getAtIndex(Node *head, int index){
    // check for valid index
    if((index < 0)||(index > getSize(head)-1)) return NULL;
    // create indexNode and get node at index
    Node * indexNode = head;
    for(int i = 0; i <= index; i++) indexNode = indexNode->next;
    // return the data of that index
    return indexNode->data;
}

// Frees a linked list
// takes a node pointer to the head of a list
void freeList(Node *head){
    // create hold
    Node *hold;\
    // remove each node in the list
    while(head->next!=NULL){
        hold = head->next;
        free(head);
        head = hold;
    }
    // free the final remaining node
    free(head);
}