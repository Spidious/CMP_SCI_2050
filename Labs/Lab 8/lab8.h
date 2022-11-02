#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;

// O(1)
Queue * makeQueue();

// O(1)
int getSize(Queue *q);

// O(n)
int enQueue(Queue *q, void *data);

// O(1)
void * deQueue(Queue *q);

// O(1)
void * peek(Queue *q);

// O(n)
void freeQueue(Queue *q);
