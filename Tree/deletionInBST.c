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

struct node* inorderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node* deleteNode(struct node* root, int value){
    // base case of recursion
    if(root == NULL) return NULL;
    if(root->left == NULL || root->right == NULL){
        free(root);
        return NULL;
    }
    // Traverse to the value you want to delete
    if(value > root->data){
        root->right = deleteNode(root->right, value);
    } else if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    // deletion technique
    else{
        struct node * iPre = inorderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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
    printf("\n");
    deleteNode(p1, 4);
    inorder(p1);
    return 0;
}