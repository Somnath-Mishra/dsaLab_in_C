#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int val;
    struct Node *next;
    
}Node;

Node* insertNode(Node* head ,int position,int value){
    int k=1;
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->val=value;
    Node*curr=head;
   
    if(position==1){
        newNode->next=head;
        head=newNode;
        return head;
    }

    while(k<=position-2){
        if(curr->next==NULL && k==(position-2)){
            curr->next=newNode;
            return head;
        }
        else{
            curr=curr->next;
            k++;
        }
    }
    newNode->next=curr->next;
    curr->next=newNode;
    return head;
}

Node* deleteNode(Node* head,int position){
    if(head->next==NULL){
        head=NULL;
        return head;
    }
    if(position==1){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node*curr=head;
    int k=0;
    while(k<=position-2&&curr->next!=NULL){
       
            curr=curr->next;
            k++;   
        
    }
    Node* temp=curr->next;
    curr->next=curr->next->next;
    free(temp);
    return head;
}

Node *reverse(Node*head){
   Node* prev = NULL;
    Node* future;
    Node* curr = head;

    while (curr != NULL) {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }

    return prev;
}
void printLinkedList(Node *head){
    Node*curr=head;
    while(curr!=NULL){
        printf("%d ",curr->val);
        curr=curr->next;
    }
    printf("\n");
}

int countNumberOfNodes(Node* head){
    if(head==NULL)
        return 0;
    Node* curr=head;
    int count=0;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    return count;
}
int main(){
    Node*head=NULL,*curr;
    int n,temp,position,value,delPos;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    printf("Enter value of node value : ");
    while(n--){
        scanf("%d",&temp);
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->val=temp;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            curr=head;
        }
        else{
            curr->next=newNode;
            curr=curr->next;
        }
    }
    printf("Printing current linked list : ");
    printLinkedList(head);
    printf("Insert node at a specified position ,enter position and value : ");
    scanf("%d%d",&position,&value);
    Node *tempHead=insertNode(head,position,value);
    printLinkedList(tempHead);
    printf("delete a node from a specified position : ");
    scanf("%d",&delPos);
    tempHead=deleteNode(tempHead,delPos-1);
    printLinkedList(tempHead);
    printf("The number of nodes in given linked list is %d\n",countNumberOfNodes(tempHead));
    tempHead=reverse(tempHead);
    printf("Printing reverse of linked list : ");
    printLinkedList(tempHead);
    
    return 0;
}