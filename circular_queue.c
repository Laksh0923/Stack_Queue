#include <stdio.h>
#include <stdlib.h>

struct circularQueue{
    int size;
    int f;      // f -> front index
    int b;      // b -> back index
    int *arr;
};

int isEmpty(struct circularQueue *ptr){
    if(ptr->f == ptr->b){
        return 1;
    } else{
        return 0;
    }
}

int isFull(struct circularQueue *ptr){
    if((ptr->b+1)%ptr->size == ptr->f){
        return 1;
    }else{
        return 0;
    }
}

int enqueue(struct circularQueue *ptr, int value){
    if(isFull(ptr)){
        printf("Queue overflow\n");
    }else{
        ptr->b = (ptr->b + 1) % ptr->size;
        ptr->arr[ptr->b] = value;
        printf("Value added : %d\n", value);
    }   
}

int dequeue(struct circularQueue *ptr){
    int a  = -1;
    if(isEmpty(ptr)){
        printf("No element to dequeue\n");
    }else{
        ptr->f = (ptr->f + 1) % ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main(){
    struct circularQueue q;
    q.size = 8;
    q.f = q.b = 0;             // frontindex and backindex should inital be zero
    q.arr = (int *)malloc (q.size * sizeof(int));

    // Enqueue --> Adding element in the queue
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    //enqueue(&q, 10);      // stack overflow

    // Dequeue --> Removing element from the queue
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    //printf("Value removed : %d\n", dequeue(&q));   // return -1 means : no element to remove from queue

    free(q.arr);      // releases the allocated memory
    q.arr = NULL;     // (optional, but prevents dangling pointer issues)
    return 0;

}