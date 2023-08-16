#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node*prev;
    struct Node*next;
}Node;


Node*insertNode(Node*head,Node*new,Node*target){
    new->next=target->next;
    new->prev=target;
    if(target->next!=NULL)
        target->next->prev=new;
    target->next=new;
    return head;
}


Node* deleteNode(Node* head,Node*target){
    if(target!=head)
        target->prev->next=target->next;
    else{
        head=target->next;
        head->prev=NULL;
    }
    if(target->next!=NULL){
        target->next->prev=target->prev;
    }
    free(target);
    return head;
}

Node* reverse(Node*head){
    Node* start = head;
    Node* end = head;
    int count=0,k=0;
    while (end->next != head) {
        end = end->next;
        count++;
    }
    while (start != end &&k<=count/2) {
        int temp=start->val;
        start->val=end->val;
        end->val=temp;
        start = start->next;
        end = end->prev;
        k++;
    }
    return head;
}


int numberOfNodes(Node*head){
    Node*curr=head;
    if(head->next==head)
        return 1;
    int count=1;
    curr=curr->next;
    while(curr!=head){
        count++;
        curr=curr->next;
    }
    return count;
}


void printdoublyLinkedList(Node *head){
    Node*curr=head;
    if(head->next==head){
        printf("%d\n",head->val);
        return ;
    }
    printf("%d ",curr->val);
    curr=curr->next;
    while(curr!=head){
        printf("%d ",curr->val);
        curr=curr->next;
    }
    printf("\n");
}

int main(){
    int n,temp,position,value;
    Node*head=NULL,*curr;

    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Enter values of nodes : ");
    while(n--){
        scanf("%d",&temp);
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->val=temp;
        newNode->next=NULL;
        newNode->prev=NULL;
        if(head==NULL){
            head=newNode;
            curr=head;
        }
        else{
            curr->next=newNode;
            curr->next->prev=curr;
            curr=curr->next;
        }
        if(n==0){
            curr->next=head;
        }
    }

    printf("Printing current doubly linked list : ");
    printdoublyLinkedList(head);


    printf("insert a node at specified position ,enter value of node and position : ");
    scanf("%d%d",&value,&position);
    Node*tempNode=(Node*)malloc(sizeof(Node));
    tempNode->val=value;
    position=position-2;
    curr=head;
    while(position--){
        curr=curr->next;
    }
    Node*currHead=insertNode(head,tempNode,curr);
    printf("Printing new doubly linked list : ");
    printdoublyLinkedList(currHead);


    printf("Enter position where you delete node : ");
    scanf("%d",&position);
    position=position-1;
    curr=head;
    while(position--){
        curr=curr->next;
    }
    currHead=deleteNode(currHead,curr);
    printf("Printing current doubly linked list : ");
    printdoublyLinkedList(currHead);


    printf("The number of nodes in doubly linked list is %d \n",numberOfNodes(currHead));


    printf("Printing reverse of linked list : ");
    currHead=reverse(currHead);
    printdoublyLinkedList(currHead);


    return 0;
}
