//here we create a BST tree 
// also traversal code here


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};

struct node * create(void);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);

int main()
{
    struct node *root;
    root=NULL;
    root=create();

    printf("preorder is ");
    preorder(root);
    printf("\n");

    printf("inorder is ");
    inorder(root);
    printf("\n");
    
    printf("post order is ");
    postorder(root);
}

struct node * create(void)
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data(enter -1 if you do not want to create any other node)");
    scanf("%d",&x);
    if(x==-1)
        return 0;
    else
    {
        newnode->data=x;
        printf("enter left child of %d ",x);
        newnode->left=create();
        printf("enter right child of %d" ,x);
        newnode->right=create();
        return newnode;
    }
}

void preorder(struct node *root)
{
    if(root==0)
        return ;
    else
    {
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root==0)
        return ;
    else
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root==0)
        return ;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}