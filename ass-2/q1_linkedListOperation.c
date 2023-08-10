#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *next;
    
}Node;

void insertNode(Node* head ,int position,int value){
    int k=1;
    Node*newNode=(Node*)malloc(sizeof(Node));
    Node*curr=head;
    newNode->val=value;
    if(position==1){
        newNode->next=head;
        head=temp;
        return ;
    }

    while(k<=position-2){
        if(curr->next==NULL && k==(position-2)){
            curr->next=newNode;
            return;
        }
        else{
            curr=curr->next;
            k++;
        }
    }
    newNode->next=curr->next;
    curr->next=newNode;
    
}

void deleteNode(Node* head,int position){
    if(position==1){
        Node*temp=head;
        head=head->next;
        free(temp);
        return ;
    }
    Node*curr=head;
    while(k<=position-1){
        if(k==position-1){
            free(curr->next);
        }
        else
            curr=curr->next;
    }
    Node* temp=curr->next;
    curr->next=curr->next->next;
    free(temp);
}
