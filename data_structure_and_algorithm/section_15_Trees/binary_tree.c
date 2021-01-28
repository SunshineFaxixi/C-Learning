#include<stdio.h>
#include<stdlib.h>
#include "queue_stack.h"

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

void IPreOrder(struct Node *p)
{
    struct Stack st;
    SCreate(&st);

    while(p || (!SIsEmpty(st)))
    {
        if(p)
        {
            printf("%d ", p->data);
            Push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = Pop(&st);
            p = p->rchild;
        }
    }
}

void IInOrder(struct Node *p)
{
    struct Stack st;

    while(p || (!SIsEmpty(st)))
    {
        if(p)
        {
            Push(&st, p);
            p = p->lchild;
        }
        else
        {
            p = Pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

// void IPostOrder(struct Node *p)
// {
//     struct Stack st;
//     long long int temp;
//     while(p || (!SIsEmpty(st)))
//     {
//         if(p)
//         {
//             Push(&st, p);
//             p = p->lchild;
//         }
//         else
//         {
//             temp = Pop(&st);
//             if(temp > 0)
//             {
//                 Push(&st, (-temp));
//                 p = ((struct Node *)temp)->rchild;
//             }
//             else
//             {
//                 printf("%d ", ((struct Node *)(-1 * temp))->data);
//                 p = NULL;
//             }      
//         }
//     }
// }

void LevelOrder(struct Node *root)
{
    struct Quene q;
    Create(&q, 100);
    
    printf("%d ", root->data);
    EnQuene(&q, root);
    while(!IsEmpty(&q))
    {
        root = DeQuene(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            EnQuene(&q, root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            EnQuene(&q, root->rchild);
        }
    }
}

int Count(struct Node *root)
{
    int x, y;
    if(root)
        return Count(root->lchild) + Count(root->rchild) + 1;
    return 0;
}

int Count1(struct Node *root)
{
    int x, y;
    if(root != NULL)
    {
        x = Count1(root->lchild);
        y = Count1(root->rchild);
        if(root->lchild && root->rchild)
            return x + y + 1;
        else
        {
            return x + y;
        }
    }
    return 0;
}

int CountLeaf(struct Node *root)
{
    if(root == NULL)
        return 0;
    if(!root->lchild && !root->rchild)
        return CountLeaf(root->lchild) + CountLeaf(root->rchild) + 1;
    return CountLeaf(root->lchild) + CountLeaf(root->rchild);
}

int Height(struct Node *root)
{
    int x = 0, y = 0;
    if(!root) 
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if(x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    CreateTree(100);
    // printf("\nPreOrder:\n");
    // PreOrder(root);
    // printf("\nInOrder:\n");
    // InOrder(root);
    // printf("\nPostOrder:\n");
    // PostOrder(root);

    // printf("\n==========iter==========");
    printf("\nPreOrder:\n");
    IPreOrder(root);
    printf("\nInOrder:\n");
    IInOrder(root);
    // printf("\nPostOrder:\n");
    // IPostOrder(root);
    printf("\nLevelOrder:\n");
    LevelOrder(root);
    printf("\ncount: %d\n", Count(root));
    printf("node of degree 2 count: %d\n", Count1(root));
    printf("Height: %d\n", Height(root));
    printf("Count leaf: %d\n", CountLeaf(root));
    return 0;
}