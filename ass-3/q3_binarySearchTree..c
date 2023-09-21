#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int key;
    struct node*left,*right;
}node;

int  search(node* root,int x){
    while(root!=NULL){
        if(root->key==x){
            return 1;
        }
        else if(root->key<x){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return 0;
}

node* insert(node* root,int x){
    node* temp=(node*)malloc(sizeof(node));
    temp->key=x;
    node* parent=NULL,*curr=root;
    while(curr!=NULL){
        parent=curr;
        if(curr->key>x){
            curr=curr->left;
        }
        else if(curr->key<x){
            curr=curr->right;
        }
        else 
            return root;
    }
    if(parent==NULL){
        return temp;
    }
    if(parent->key>x){
        parent->left=temp;
    }
    else{
        parent->right=temp;
    }
    return root;
}

node* getSuccessor(node* curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}