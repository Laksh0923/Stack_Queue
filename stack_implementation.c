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

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc (s->size * sizeof(int));
    
    printf("Before pushing, full : %d\n", isFull(s));
    printf("Before pushing, empty : %d\n", isEmpty(s));
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    //push(s, 8);  --> Stack overflow
    printf("After pushing, full : %d\n", isFull(s));
    printf("After pushing, empty : %d\n", isEmpty(s));

    printf("Popped %d from the stack\n", pop(s));
    printf("Popped %d from the stack\n", pop(s));
    printf("Popped %d from the stack\n", pop(s));
    printf("Popped %d from the stack\n", pop(s));
    printf("Popped %d from the stack\n", pop(s));
    printf("Popped %d from the stack\n", pop(s));
    //printf("Popped %d from the stack\n", pop(s));  --> Stack underflow

    free(s);
    s = NULL;

    free(s->arr);
    s->arr = NULL;

    return 0;
}