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

int main(){
    struct stack *s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc (s->size * sizeof(int));
    
    
    if(isEmpty(s)){
        printf("The stack is empty");
    }else{
        printf("The stack is not empty");
    }

    return 0;
}