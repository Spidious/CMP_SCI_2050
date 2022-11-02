#include "lab8.h"

struct Node {
	Node *next;
	void *data;
};

struct Queue {
	Node *list;
	int size;
};


// Creates a queue with a dummy node
// returns a queue pointer to the head of the queue list
// returns null if malloc fails
Queue * makeQueue(){
    // create queue and dummy variables and check
    Queue * queue = malloc(sizeof(Queue));
    Node * dummy = malloc(sizeof(Node));
    if(!queue || !dummy) return NULL;

    dummy->data = NULL;
    dummy->next = NULL;
    queue->list = dummy;
    queue->size = 0;

    return queue;
}


// returns the size of a queue
int getSize(Queue *q){
    return(q->size);
    }


// adds an item to the queue
// takes a queue pointer and a void pointer to the data
// returns 1 on failure and 0 on success
int enQueue(Queue *q, void *data){
    // save size, create and check the new node, assign next and data
    int size = getSize(q);
    Node * newNode = malloc(sizeof(Node));
    if(!newNode) return 1;
    newNode->next = q->list->next;
    newNode->data = data;

    // iterate through queue to reach end
    for(int i = 0; i < size-1; i++){
        newNode->next = newNode->next->next;
    }

	// use special case instead if size is 0
    if(size==0){
		q->list->next = newNode;
	}
	else{
		newNode->next->next = newNode;
	}

	// set newnode->next to null, add 1 to size; return successful
    newNode->next = NULL;
	q->size++;
    return 0;
}

// Dequeues and returns the data of the next element
// takes a Queue pointer
// returns void pointer of the data for the next element, NULL if empty
void * deQueue(Queue *q){
	// check if empty, save 0th element and its data
	if(q->size == 0) return NULL;
	Node * hold = q->list->next;
	void * data = hold->data;
	
	// remove 0th element from list and free hold
	q->list->next = hold->next;
	free(hold);
	// decrement size
	q->size--;
	// return the data
	return data;
}

// returns the data of the next element without dequeueing it
// returns void pointer of data, NULL if empty
void * peek(Queue *q){
	if(q->size == 0) return NULL;
	return q->list->next->data;
}

// frees a queue
// takes a queue pointer
void freeQueue(Queue *q){
	// create hold node pointer
	Node * hold;
	// if list isn't null, loop until it is
    if(q->list != NULL){
        while(q->list->next != NULL){
			// set hold to list->next, free list, set list to hold
            hold = q->list->next;
            free(q->list);
            q->list = hold;
        }
		// free list then q
        free(q->list);
    }
    free(q);
}