#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int obj;
    struct node *next;
}Node;

typedef struct stack{
    Node *stackHead;
}Stack;

Stack createStack();
void push(Stack *stack, int obj);
int pop(Stack *stack);

int main(void){
    // Stack has Push() and Pop()
    // behaves like a "stack of things"
        // push() puts on top of stack
        // pop() pulls from top of stack
    // example: "Undo" operation in software like photoshop or word
    Stack stack = createStack();
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));



    // Queue is first in first out
    // stack pulls from front, queue pulls from end
        // enqueue() puts data onto the queue
        // dequeue() retrieves earliest data item
    // buying tickets, first come first serve
}

Stack createStack(){
    Stack stack;
    Node *head = (Node *)malloc(sizeof(Node *));                  // Create new Stack and Node variables
    stack.stackHead = head;

    stack.stackHead->next = NULL;   // Initialize stackHead next and obj
    stack.stackHead->obj = 0;
    return stack;
}

void push(Stack *stack, int obj){
    Node *newNode = (Node *)malloc(sizeof(Node *));           // Create new node for obj and give it obj
    newNode->obj = obj;
    newNode->next = stack->stackHead;        // Set newNode.next to stackHead
    stack->stackHead = newNode;            // Change stackHead to newNode
}

int pop(Stack *stack){
    if(!stack->stackHead){
        printf("stack is null\n");
        return((int)'\0');
    }
    int obj = stack->stackHead->obj;     // set obj to stackHead.obj
    Node * node = stack->stackHead;      // create node to hold stackHead to free it later

    stack->stackHead = stack->stackHead->next;    // set stackHead to stackHead.next
    
    free(node);                         // free node

    return obj;                         // return obj
}