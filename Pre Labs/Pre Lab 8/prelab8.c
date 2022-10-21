#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void *obj;
    struct node *next;
}Node;

typedef struct{
    Node *head;
}List;

List initList();
int insertAtHead(void *object, List list);
int insertAtTail(void *object, List list);
void * removeHead(List list);
void * removeTail(List list);
void freeList(List list);

int main(void){
    List list = initList();
    printf("Insert at head error output: %d\n", insertAtHead((void *)4, list));
    printf("Insert at head error output: %d\n", insertAtHead((void *)3, list));
    printf("Insert at head error output: %d\n", insertAtHead((void *)2, list));
    printf("Insert at head error output: %d\n", insertAtHead((void *)1, list));
    printf("Insert at tail error output: %d\n", insertAtTail((void *)5, list));
    printf("Insert at tail error output: %d\n", insertAtTail((void *)6, list));
    printf("Insert at tail error output: %d\n", insertAtTail((void *)7, list));
    printf("Insert at tail error output: %d\n", insertAtTail((void *)8, list));
    removeHead(list);
    removeHead(list);
    removeTail(list);
    removeTail(list);

    freeList(list);

    Node *hold = list.head->next;
    while(hold!=NULL){
        printf("%d\n", (int)(long)(int *)hold->obj);
        hold = hold->next;
    }

}

List initList(){
    // Initialize list, dummy
    List *list = malloc(sizeof(List *));
    Node *dummy = malloc(sizeof(Node *));
    // Set variables to null or appropriate value
    list->head = dummy;
    dummy->obj = NULL;
    dummy->next = NULL;
    // Return dereferenced list
    return *list;
}

int insertAtHead(void * object, List list){
    // Allocate and check
    Node *node = malloc(sizeof(Node *));
    if(!node) return 1;
    // Set obj and next values to insert it
    node->obj = object;
    node->next = list.head->next;
    list.head->next = node;
    return 0;
}

int insertAtTail(void *object, List list){
    // Get tail pointer
    Node *tail = list.head->next;
    while(tail->next!=NULL) tail = tail->next;
    // Allocate and check
    Node *node = malloc(sizeof(Node *));
    if(!node) return 1;
    // set obj and next values to insert it
    node->obj = object;
    node->next = tail->next;
    tail->next = node;
    return 0;
}

void * removeHead(List list){
    Node *node = list.head->next;
    list.head->next = list.head->next->next;
    free(node);
}

void * removeTail(List list){
    Node * end = list.head->next;
    while(end->next->next != NULL) end = end->next;
    free(end->next);
    end->next = NULL;
}

void freeList(List list){
    Node * hold;
    while(list.head->next != NULL){
        hold = list.head->next->next;
        free(list.head->next);
        list.head->next = hold;
    }
    free(hold);
}