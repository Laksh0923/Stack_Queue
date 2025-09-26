#include <Stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTranverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    // Allocated memory for nodes in the linked list in Heap
    struct Node *head = (struct Node *) malloc (sizeof(struct Node));    // head means first element in linked list
    struct Node *second = (struct Node *) malloc (sizeof(struct Node));
    struct Node *third = (struct Node *) malloc (sizeof(struct Node));


    
    // link first and second nodes
    head->data = 26;
    head->next = second;

    // link second and third nodes
    second->data = 9;
    second->next = third;

    third->data = 10;
    third->next = NULL;

    linkedListTranverse(head);
    return 0;
}