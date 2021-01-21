#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Quene
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

int IsEmpty(struct Quene *q)
{
    return (q->rear == q->front);
}

void Create(struct Quene *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void EnQuene(struct Quene *q, struct Node *x)
{
    if((q->rear + 1) % q->size == q->front)
    {
        printf("Quene is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *DeQuene(struct Quene *q)
{
    struct Node *x = NULL;

    if(IsEmpty(q))
    {
        printf("Quene is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
