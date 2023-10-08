#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} node;
void inorder(node *Root)
{
    if (Root)
    {
        inorder(Root->left);
        printf("%c ", Root->data);
        inorder(Root->right);
    }
}

void postorder(node *Root)
{
    if (Root)
    {
        postorder(Root->left);
        postorder(Root->right);
        printf("%c ", Root->data);
    }
}

void preorder(node *Root)
{
    if (Root)
    {
        printf("%c ", Root->data);
        preorder(Root->left);
        preorder(Root->right);
    }
}
int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}
node *newNode(char data)
{
    node *Node = (node *)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}
node *bulidTree(char in[], char pre[], int instrt, int inEnd)
{
    static int preIndex = 0;
    if (instrt > inEnd)
        return NULL;
    node *tNode = newNode(pre[preIndex++]);
    if (instrt == inEnd)
        return tNode;
    int inIndex = search(in, instrt, inEnd, tNode->data);
    tNode->left = bulidTree(in, pre, instrt, inIndex - 1);
    tNode->right = bulidTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}
void printInorder(node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}
int main()
{
    int n;
    printf("Enter number of element : ");
    scanf("%d", &n);

    char *in = (char *)malloc(n * sizeof(char));
    char *pre = (char *)malloc(n * sizeof(char));

    printf("Enter inorder traversal : ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &in[i]);
    }
    printf("Enter preorder traversal : ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &pre[i]);
    }
    node *root = bulidTree(in, pre, 0, n - 1);
    // printInorder(root);
    int dis;
    printf("\n");
    while (1)
    {
        printf("Inorder Traversal : 1\tPostorder Traversal : 2\tPreorder Traversal : 3 \nExit 0\n");
        scanf("%d", &dis);
        switch (dis)
        {
        case 1:
            printf("Inorder traversal : ");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Postorder traversal : ");
            postorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal : ");
            preorder(root);
            printf("\n");
            break;
        case 0:
            printf("Exiting from program !!\n");
            return 0;
            break;
        default:
            printf("Invalid choice, Please try again :\n");
        }
    }
    free(in);
    free(pre);
    return 0;
}