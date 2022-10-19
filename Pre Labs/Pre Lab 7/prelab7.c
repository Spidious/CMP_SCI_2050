#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct{
    int object;
    struct listStruct *next;
}List;

List * initList(int * err);
List * insertAtHead(int param, List * list, int * err);
int getAtIndex(int index, List * list);
int getListLength(List *);
List * freeList(List *);
int getThisItem(List list);

int main(void){
    int errCheck = 0;
    List *list = initList(&errCheck);
    if(errCheck) return 1;


    for(int i = 20; i > 0; i--){
        list = insertAtHead(i, list, &errCheck);
    }

    List * p = list;
    printf("2xptr test: %d\n", p->object);

    for(int i = 1; i <= 21; i++){
        printf("%d\n", getAtIndex(i, list));
    }

    printf("Size : %d\n", getListLength(list));

    printf("%d\n", getThisItem(*((list->next)->next)->next));

    printf("%p\n", list->next);
    freeList(list);
    printf("%p\n", list->next);


}

List * initList(int * err){
    *err = 0;
    List *list = malloc(sizeof(List));
    if(!list) *err = 1;
    list->object = 1234612344;
    list->next = NULL;
    return list;
}

List * insertAtHead(int param, List * list, int * err){
    *err = 1;
    List * newObj = malloc(sizeof(List));
    newObj->object = param;
    newObj->next = list;
    if(newObj->object == param) *err = 0;
    return newObj;
}

int getAtIndex(int index, List * list){
    List *node = list;
    for(int i = 1; i < index; i++){
        node = node->next;
    }
    return node->object;
}

int getListLength(List * list){
    int count = 0;
    List *n = list;
    while (n != NULL){
        count++;
        n = n->next;
    }
    free(n);
    return count;
}

List * freeList(List * list){
    List *tmp = list;
    while(list->next != NULL){
        tmp = list;
        list = list->next;
        free(tmp);        
    }
    return NULL;
}

int getThisItem(List list){
    return list.object;
}