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

struct Stack
{
    int size;
    int top;
    struct Node **A;
};

void SCreate(struct Stack *st)
{
    printf("Enter the size of the stack: ");
    scanf("%d",&st->size);
    st->A = (struct Node **)malloc(st->size * sizeof(struct Node *));
    st->top = -1;
}

void Push(struct Stack *st, struct Node *x)
{
    if(st->top == st->size - 1)
    {
        printf("StackOverflow\n");
    }
    else
    {
        st->top++;
        st->A[st->top] = x;
    }
}

struct Node *Pop(struct Stack *st)
{
    struct Node * x = NULL;

    if(st->top < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->A[st->top--];
    }
    return x;
}

int SIsEmpty(struct Stack st)
{
    return (st.top == -1);
}