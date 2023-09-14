#include<stdio.h>
typedef struct btnode{
    int data;
    btnode *left,*right;
}btnode;

btnode* modifyTree(btnode *Root){
    
}

void inorder(btnode *Root){
    if(Root){
        inorder(Root->left);
        printf("%d",Root->data);
        inorder(Root->right);
    }
}

void postorder(btnode *Root){
    if(Root){
        postorder(Root->left);
        postorder(Root->right);
        printf("%d",Root->data);
    }
}

void preorder(btnode *Root){
    if(Root){
        printf("%d",Root->data);
        preorder(Root->left);
        preorder(Root->right);
    }
}

int main(){
    int dis;
    btnode *Root=NULL; 
    printf("Insert Element : 1\tInorder Traversal : 2\nPostorder Traversal : 3\tPreorder Traversal : 4 \nExit 0\n");
    scanf("%d",&dis);
    switch (dis)
    {
    case 1:
        printf("Creating Tree : \n");
        Root=modifyTree(Root);
        break;
    case 2:
        printf("Inorder traversal : ");
        inorder(Root);
    break;
    case 3:
        printf("Postorder traversal : ");
        postorder(Root);
    break;
    case 4:
        printf("Preorder traversal : ");
        preorder(Root);
    break;
    case 0:
        printf("Exiting from program !!\n");
        return 0;
    break;
    default:
        printf("Invalid choice ,Please try again :\n");
    }
    return 0;
}