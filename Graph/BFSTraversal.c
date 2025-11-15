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

    // BFS Implementation
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};  // 7 represents the number of nodes in graph and initialize it with zero
    // Take the example graph from the image.png file
    int arr[7][7] = {
       //0 1 2 3 4 5 6 
        {0,1,1,1,0,0,0},   // 0
        {1,0,0,1,0,0,0},   // 1
        {1,0,0,1,1,0,0},   // 2
        {1,1,1,0,1,0,0},   // 3
        {0,0,1,1,0,1,1},   // 4
        {0,0,0,0,1,0,0},   // 5
        {0,0,0,0,1,0,0}    // 6
    };

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(arr[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
        
    }
    
    return 0;
}