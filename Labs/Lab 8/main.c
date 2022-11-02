#include "lab8.c"

int main(void){
    Queue * queue =makeQueue();
    printf("makeQueue complete\n");

    for(int i = 0; i < 500000; i++){
        enQueue(queue, (void *)(long)i);
    }
    printf("enqueue complete\n");

    int queueSize = getSize(queue);
    for(int i = 0; i < queueSize+1; i++) printf("Dequeue %d: %d\n", i, (int)(long)(int *)deQueue(queue));
    printf("dequeue complete\n");

    for(int i = rand()%queueSize/2; i < queueSize; i++){
        enQueue(queue, (void *)(long)i);
    }
    printf("%d\n", (int)(long)(int *)peek(queue));


    free(queue);
    printf("%d\n", (int)(long)(int *)peek(queue));
}