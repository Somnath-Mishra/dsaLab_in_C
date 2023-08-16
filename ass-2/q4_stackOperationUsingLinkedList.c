#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int val;
    struct Node *next;
    
}Node;

int top(Node*head){
    return head->val;
}
Node* pop(Node*head){
    Node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
Node* push(Node*head,int val){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->val=val;
    newNode->next=head;
    head=newNode;
    return head;
}
int size(Node*head){
    if(head==NULL)
        return 0;
    Node*curr=head;
    int count=0;
    while(curr!=NULL){
        curr=curr->next;
        count++;
    }
    return count;
}
int isEmpty(Node*head){
    if(head==NULL)
        return 1;
    else
        return 0;
}

int main(){
    int n,value,data;
    printf("Enter number of element in stack : ");
    scanf("%d",&n);
    Node*head,*curr;
    printf("Enter all element in stack : ");
    while(n--){
        scanf("%d",&value);
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->val=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            head->next=NULL;
            curr=head;
        }
        else{
            curr->next=newNode;
            curr=curr->next;
        }
    }
    printf("Printing top element in stack : ");
    printf("%d\n",top(head));

    printf("poping out element from stack then print top element : ");
    Node*newHead=pop(head);
    printf("%d\n",top(newHead));

    printf("Enter number which you want to push : ");
    scanf("%d",&data);
    printf("Push %d into stack \n",data);
    newHead=push(newHead,data);
    printf("now head is %d\n",top(newHead));
    printf("The size of stack is %d \n",size(newHead));
    printf("Now checking the stack is empty or not \n");
    if(isEmpty(newHead)){
        printf("Stack is empty \n");
    }
    else{
        printf("Stack is not empty\n");
    }
    return 0;
}