#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;        // f --> front index
    int b;        //  b --> back index
    int *arr;
};

int isFull(struct queue *ptr){
    if(ptr->b == ptr->size - 1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct queue *ptr){
    if(ptr->f == ptr->b){
        return 1;
    }else{
        return 0;
    }
}

int enqueue(struct queue *ptr, int value){
    if(isFull(ptr)){
        printf("Queue overflow\n");
    } else{
        ptr->b++;
        ptr->arr[ptr->b] = value;
    }
}

int dequeue(struct queue *ptr){
    int a = -1;
    if(isEmpty(ptr)){
        printf("No element to dequeue\n");
    }else{
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 8;
    q.f = q.b = -1;
    q.arr = (int *)malloc (q.size * sizeof(int));

    // Enqueue --> Adding element in the queue
    printf("Value added : %d\n",enqueue(&q, 2));
    printf("Value added : %d\n",enqueue(&q, 3));
    printf("Value added : %d\n",enqueue(&q, 4));
    printf("Value added : %d\n",enqueue(&q, 5));
    printf("Value added : %d\n",enqueue(&q, 6));
    printf("Value added : %d\n",enqueue(&q, 7));
    printf("Value added : %d\n",enqueue(&q, 8));
    printf("Value added : %d\n",enqueue(&q, 9));
    printf("Value added : %d\n",enqueue(&q, 10));   // queue overflow


    // Dequeue --> Removing element from the queue
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));
    printf("Value removed : %d\n", dequeue(&q));   // return -1 means : no element to remove from queue
    return 0;
}