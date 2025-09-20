#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;        //  1 means true
    }else{
        return 0;       //   0 means false
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size - 1){
        return 1;      //  1 means true
    }else{
        return 0;     //   0 means false
    }
}

void push(struct stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack is overflow, cannot push %d to the stack!\n", val);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is underflow, cannot pop from the stack!\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int pos){
    if(ptr->top - pos + 1 < 0){
        printf("Invalid position\n");
        return -1;
    } else{
        return ptr->arr[ptr->top - pos + 1];         
    }
}


int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc (s->size * sizeof(int));
    
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);

    for(int j=1; j<=s->top+1; j++){
        printf("The value at index %d is %d\n", j, peek(s, j));
    }

    free(s);      // releases the allocated memory
    s = NULL;     // (optional, but prevents dangling pointer issues)

    free(s->arr);      // releases the allocated memory
    s->arr = NULL;     // (optional, but prevents dangling pointer issues)
    return 0;
}