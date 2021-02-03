#include<stdio.h>
#include<stdlib.h>
#include "queue_stack.h"

// struct Node
// {
//     struct Node *lchild;
//     int data;
//     struct Node *rchild;
// }*root = NULL;

void Insert(int key)
{
    struct Node *p = root;
    struct Node *r = NULL;
    struct Node *q;
    if(!p)
    {
        q = (struct Node *)malloc(sizeof(struct Node));
        q->data = key;
        q->lchild = q->rchild = NULL;
        root = q;
        return;
    }
    while(p)
    {
        r = p;
        if(key > p->data)
            p = p->rchild;
        else if(key < p->data)
            p = p->lchild;
        else
            return;
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(r->data > p->data)
        r->lchild = p;
    else
        r->rchild = p;    
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
    if(!p)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
}

void InOrder(struct Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        printf("%d ", p->data);
        InOrder(p->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t = root;
    while(t != NULL)
    {
        if(key == t->data)
            return t;
        else if(key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

int Height(struct Node *p)
{
    int x, y;
    if(!p)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? (x + 1): (y + 1);
}

// 找出中序遍历的最右结点
struct Node *InPre(struct Node *p)
{
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

// 找出中序遍历的最左结点
struct Node *InSucc(struct Node *p)
{
    while(p && p->rchild)
        p = p->lchild;
    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;
    if(!p)
        return NULL;
    if(!p->lchild && !p->rchild)
    {
        if(p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else
    {
        if(Height(p->lchild) >  Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

// TODO
// void CreatePre(int Pre[], int n)
// {
//     struct Stack st;
//     struct Node *p, *t;
//     int i = 0;

//     SCreate(&st);

//     root = (struct Node *)malloc(sizeof(struct Node));
//     root->data = Pre[i++];
//     root->lchild = root->rchild = NULL;
//     p = root;
//     while(i < n)
//     {
//         if(Pre[i] < p->data)
//         {
//             t = (struct Node *)malloc(sizeof(struct Node));
//             t->data = Pre[i++];
//             t->lchild = t->rchild = NULL;
//             p->lchild = t;
//             Push(&st, t);
//             p = t;
//         }
//         else if((Pre[i] > p->data) && (Pre[i] < StackTop(st)))
//         {
//             t = (struct Node *)malloc(sizeof(struct Node));
//             t->data = Pre[i++];
//             t->lchild = t->rchild = NULL;
//             p->rchild = t;
//             p = t;
//         }
//         else
//         {
//             p = Pop(&st);
//         }
//     }
// }

int main()
{
    // struct Node *temp, *delete;
    // ===========Insert==============
    // Insert(10);
    // Insert(8);
    // Insert(30);
    // Insert(25);
    // Insert(5);
    // ===========RInsert==============
    // root = RInsert(root, 10);
    // RInsert(root, 8);
    // RInsert(root, 30);
    // RInsert(root, 25);
    // RInsert(root, 5);

    // ===========Search & Delete==============
    // InOrder(root);
    // printf("\n");
    // temp = Search(8);
    // if(temp)
    //     printf("%d is found\n", temp->data);
    // else
    //     printf("not found\n");
    
    // Delete(root, 10);
    // printf("after delete:\n");
    // InOrder(root);
    // printf("\n");

    // ===========CreatePre==============
    // int Pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    // CreatePre(Pre, sizeof(Pre) / sizeof(Pre[0]));
    // InOrder(root);
    // printf("\n");

    

    return 0;
}