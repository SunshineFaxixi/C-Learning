#include<stdio.h>
#include<stdlib.h>
#include "quene.h"

struct Node *root = NULL;

void CreateTree()
{
    struct Quene q;
    struct Node *p, *t;
    int x;

    Create(&q, 10);

    printf("Enter value for root: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    EnQuene(&q, root);
    while(!IsEmpty(&q))
    {
        p = DeQuene(&q);

        printf("Enter lchild value of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            EnQuene(&q, t);
        }

        printf("Enter rchild value of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            EnQuene(&q, t);
        }
    }
}

void PreOrder(struct Node *root)
{
    if(root)
    {
        printf("%d ", root->data);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void InOrder(struct Node *root)
{
    if(root)
    {
        InOrder(root->lchild);
        printf("%d ", root->data);
        InOrder(root->rchild);
    }
}

void PostOrder(struct Node *root)
{
    if(root)
    {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%d ", root->data);
    }
}

int main()
{
    CreateTree();
    printf("\nPreOrder:\n");
    PreOrder(root);
    printf("\nInOrder:\n");
    InOrder(root);
    printf("\nPostOrder:\n");
    PostOrder(root);

    return 0;
}