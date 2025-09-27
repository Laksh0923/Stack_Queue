#include <stdio.h>
#include <Stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case - 1  --> Insert the element in the beginning of the linked list
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case - 2 --> Insert the element at the index in the linked list
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr= (struct Node *) malloc (sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

//  Case - 3 --> Insert the element at the end of the linked list
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case - 4 --> Inserting the element at the given node in the linked list
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main(){

    struct Node *head = (struct Node *) malloc (sizeof(struct Node));
    struct Node *second = (struct Node *) malloc (sizeof(struct Node));
    struct Node *third = (struct Node *) malloc (sizeof(struct Node));

    head->data = 26;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 1;
    third->next = NULL;

    linkedListTraversal(head);
    //head = insertAtFirst(head, 10);   // For case 1
    // head = insertAtIndex(head, 10 ,1); // For case 2
    //head = insertAtEnd(head, 10);  // For case 3
    head = insertAfterNode(head, second, 10);  // For case 4
    printf("\n");
    linkedListTraversal(head);

    return  0;
}