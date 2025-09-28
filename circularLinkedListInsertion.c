#include <Stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTranverse(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

int main(){

    // Allocated memory for nodes in the linked list in Heap
    struct Node *head = (struct Node *) malloc (sizeof(struct Node));    // head means first element in linked list
    struct Node *second = (struct Node *) malloc (sizeof(struct Node));
    struct Node *third = (struct Node *) malloc (sizeof(struct Node));
    struct Node *forth = (struct Node *) malloc (sizeof(struct Node));

    
    // link first and second nodes
    head->data = 26;
    head->next = second;

    // link second and third nodes
    second->data = 9;
    second->next = third;

    third->data = 10;
    third->next = forth;

    forth->data = 35;
    forth->next = head;

    printf("Before insertion : \n");
    linkedListTranverse(head);
    
    printf("\nAfter insertion : \n");
    head = insertAtFirst(head, 24);
    linkedListTranverse(head);
    return 0;
}