#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct btnode
{
    int data;
    struct btnode *left, *right;
} btnode;

btnode *createNode(int data)
{
    btnode *newNode = (btnode *)malloc(sizeof(btnode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

btnode *modifyTree()
{
    printf("Enter number of nodes including null except the last leaf null: ");
    int n;
    scanf("%d", &n);
    int levelOrder[n];
    printf("Enter value of all elements (for null input -1): ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &levelOrder[i]);
    }

    getchar(); 

    btnode *Root = NULL;
    btnode *queue[MAX];
    int front = -1, rear = -1;

    if (n > 0)
    {
        Root = createNode(levelOrder[0]);
        queue[++rear] = Root;
    }
    else
    {
        return NULL; 
    }

    int i = 1;
    while (front <= rear && i < n)
    {
        btnode *curr = queue[++front];
        if (levelOrder[i] != -1)
        {
            curr->left = createNode(levelOrder[i]);
            queue[++rear] = curr->left;
        }
        i++;

        if (i < n && levelOrder[i] != -1)
        {
            curr->right = createNode(levelOrder[i]);
            queue[++rear] = curr->right;
        }
        i++;
    }
    return Root;
}

void inorder(btnode *Root)
{
    if (Root)
    {
        inorder(Root->left);
        printf("%d ", Root->data);
        inorder(Root->right);
    }
}

void postorder(btnode *Root)
{
    if (Root)
    {
        postorder(Root->left);
        postorder(Root->right);
        printf("%d ", Root->data);
    }
}

void preorder(btnode *Root)
{
    if (Root)
    {
        printf("%d ", Root->data);
        preorder(Root->left);
        preorder(Root->right);
    }
}

int main()
{
    int dis;
    btnode *Root = NULL;

    while (1)
    {
        printf("Insert Element : 1\tInorder Traversal : 2\nPostorder Traversal : 3\tPreorder Traversal : 4 \nExit 0\n");
        scanf("%d", &dis);
        switch (dis)
        {
        case 1:
            printf("Creating Tree : \n");
            Root = modifyTree();
            break;
        case 2:
            printf("Inorder traversal : ");
            inorder(Root);
            printf("\n");
            break;
        case 3:
            printf("Postorder traversal : ");
            postorder(Root);
            printf("\n");
            break;
        case 4:
            printf("Preorder traversal : ");
            preorder(Root);
            printf("\n");
            break;
        case 0:
            printf("Exiting from program !!\n");
            return 0;
        default:
            printf("Invalid choice, Please try again :\n");
        }
    }
    return 0;
}
