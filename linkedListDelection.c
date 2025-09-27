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

//Case - 1 --> Deleting the first element from the linked list
struct Node * deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//Case - 2 --> Deleting the element at a given index from the linked list
struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i=1; i<index-1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Case - 3 --> Deleting the last element from the linked list
struct Node * deleteAtLast(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}

//Case - 4 --> Deleting the element with a given value from the linked list
struct Node * deleteAtValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    
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
    forth->next = NULL;

    printf("Before deletion : \n");
    linkedListTranverse(head);

    // head = deleteFirst(head);       // For case 1
    //head = deleteAtIndex(head, 2);     // For case 2
    //head = deleteAtLast(head);     // For case 3
    head = deleteAtValue(head, 99);  // For case 4
    printf("\nAfter deletion : \n");
    linkedListTranverse(head);
    return 0;
}