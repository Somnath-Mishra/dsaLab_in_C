#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;


void printList(Node *head)
{
    Node *curr = head;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
}


Node *insertPos(Node *head,int pos,int data)
{
  
    Node *temp ;
    temp = (Node*)malloc(sizeof(Node));
    temp->data  = data;
    if(pos == 1)
    {
        temp->next = head;
        head = temp;
        printList(head);
        return head;
        
    }
    Node *curr = head;
    int i;
    for(i = 1;i<=pos-2&& curr!=NULL;i++)
    {
        curr=curr->next;
        
    }
    if(curr == NULL)
    {
        printList(head);
    }
    temp->next = curr->next;
    curr->next = temp;
    printList(head);
    return head;
}



Node *deletePos(Node *head,int pos)
{
    Node *temp = head,*target;
    if(pos==1) {
        head = temp->next;
        free(temp);
        printList(head);
        return head;
    }
    
    int i;
    for( i = 1;i<=pos-2;i++)
    {
       temp = temp->next;
      
       
    }
 
   
   target = temp->next;
    temp->next = target->next;
    
    free(target);
    printList(head);
    return head;
    
}

int main()
{
    int num, x;
    printf("Enter no of nodes you want to insert\n");
    scanf("%d",&num);
    int i = 0;
    Node *head = NULL;
    Node *tail;
    for(i = 0;i<num;i++)
    {
        scanf("%d",&x);
        Node *curr = (Node*)malloc(sizeof(Node));
        curr->data = x;
        curr->next = NULL;
        if(head == NULL)
        {
            head = curr;
            tail = curr;
            
        }
        else{
            tail->next = curr;
            tail = curr;
        }
        
    }
    int val,pos,del;
    printf("Enter position and value where you want to insert value :\n");
    scanf("%d %d",&pos,&val);
    Node *head1 =insertPos(head,pos,val);
    printf("\nEnter the position where you want to delete the node : \n");
    scanf("%d",&del);
    deletePos(head1,del);
    
    return 0;
}