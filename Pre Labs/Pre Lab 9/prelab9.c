#include <stdlib.h>
#include <stdio.h>

//  Create Data types

typedef struct node{    // Node data type, hold data and next ptr
    void * data;
    struct node * next;
}Node;

typedef struct dummy{   // Dummy data type, hold pointers to front and rear, hold error code and size;
    Node * front, * rear;
    int error, size;
}Dummy;

typedef struct queue{Dummy * head;}Queue;    // Queue data type, hold pointer to head while not being a pointer itself

//  Function Prototypes

int getQueueErrorCode(Queue queue);
Queue queueInit();
int enqueue(void * data, Queue queue);
void * dequeue(Queue queue);
int getQueueSize(Queue queue);
void freeQueue(Queue queue);


int main(void){
    Queue myq = queueInit();
    for(int i = 0; i < 5; i++) enqueue((void *)(long)i, myq);
    int size = getQueueSize(myq);
    for(int i = 0; i < size+1; i++) printf("%d\n", (int)(long)(int *)dequeue(myq));
    freeQueue(myq);
}


// Initialize an empty queue
// returns the value of a Queue data type variable pointing to an empty queue
Queue queueInit(){
    // create queue and node variables, create nodes dynamically
    Queue queue;
    Dummy * dummy = malloc(sizeof(Dummy *));

    // Assign values
    queue.head = dummy;
    queue.head->front = NULL;
    queue.head->rear = NULL;
    queue.head->size = 0;
    queue.head->error = 0;

    // Return
    return queue;
}

/* This function returns the error code from the most 
    recently executed queue operation. 0 implies success, 
    1 implies out-of-memory error. Some functions may 
    document additional error conditions. NOTE: All  
    queue functions assign an error code.   */ 
int getQueueErrorCode(Queue queue){
    return queue.head->error;
}

int enqueue(void * data, Queue queue){
    // create new node
    Node * node = malloc(sizeof(Node *));
    if(!node){
        queue.head->error = 1;
        return 1;
    }
    node->data = data;
    node->next = NULL;

    // check if list is empty, special case
    if(queue.head->size == 0){
        queue.head->front = node;
        queue.head->rear = node;
        queue.head->size = 1;
        queue.head->error = 0;
        return 0;
    }

    // add node
    queue.head->rear->next = node;
    queue.head->rear = node;
    queue.head->size++;
    queue.head->error = 0;
    return 0;
}

/* Deletes front node and returns void pointer of data
takes a queue variable
returns Null with error code -1 if queue is empty, 0 on success*/
void * dequeue(Queue queue){
    if(queue.head->size == 0){
        printf("Queue is empty\n");
        queue.head->error = -1;
        return NULL;
    }
    
    // save data and node pointer
    void * data = queue.head->front->data;
    Node * node = queue.head->front->next;
    
    // move front pointer and free node
    free(queue.head->front);
    queue.head->front = node;

    // if front now null, set rear to null as well
    if(queue.head->front == NULL) queue.head->rear = NULL;

    // decrement size value and return the data
    queue.head->size--;
    queue.head->error = 0;
    return data;
}

int getQueueSize(Queue queue){
    return(queue.head->size);
}

void freeQueue(Queue queue){
    Node * hold;
    if(queue.head->front != NULL){
        while(queue.head->front->next != NULL){
            hold = queue.head->front->next;
            free(queue.head->front);
            queue.head->front = hold;
        }
        free(queue.head->front);
    }
    free(queue.head);
}