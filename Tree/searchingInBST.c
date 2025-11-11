#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n = (struct node*) malloc (sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if(root->data == value){
        return root;
    }
    else if (value < root->data) {
        return search(root->left, value);
    }
    else{
        return search(root->right, value);
    }
}

int main(){
    struct node* p1 = createNode(5);
    struct node* p2 = createNode(3);
    struct node* p3 = createNode(6);
    struct node* p4 = createNode(2);
    struct node* p5 = createNode(4);

    // the tree looks like this : 
    //          5
    //         / \
    //        3   6
    //       / \
    //      2   4
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5; 

    inorder(p1);
    int key = 7;
    if (search(p1, key) != NULL) {
        printf("\nElement %d found in the BST.", key);
    } else {
        printf("\nElement %d not found in the BST.", key);
    }
    return 0;
}