#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int obj;
    struct node *next;
}Node;

typedef struct {
    Node *head, *tail;
}List;

void addNodeHead(List *list, int content);
List createList();
void printList(List list);


int main(void){
    List p = createList();
    printList(p);
}

List createList(){
    Node headNode, tailNode;
    tailNode.next = malloc(sizeof(Node *));
    tailNode.next = NULL;
    headNode.next = &tailNode;
    headNode.obj = 0;
    tailNode.obj = 0;

    List list;
    list.head = &headNode;
    list.tail = headNode.next;

    return list;
}

void addNodeHead(List *list, int content){
    Node newNode;
    newNode.obj = content;
    newNode.next = list->head;
    list->head = &newNode;
}

void printList(List list){
    Node *node = list.head;
    printf("%p\n", list.tail);
    while(node->next!=NULL){
        printf("%d   -   %p   -   %p\n", node->obj, node->next, node);
        node = node->next;
    }
}