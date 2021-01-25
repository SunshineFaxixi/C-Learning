#include<stdio.h>
#include<stdlib.h>

struct SNode
{
    struct SNode *lchild;
    int data;
    struct SNode *rchild;
};

struct Stack
{
    int size;
    int top;
    struct SNode **A;
};

void SCreate(struct Stack *st)
{
    printf("Enter the size of the stack: ");
    scanf("%d",&st->size);
    st->A = (struct SNode **)malloc(st->size * sizeof(struct SNode *));
    st->top = -1;
}

void Push(struct Stack *st, struct SNode *x)
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

struct SNode *Pop(struct Stack *st)
{
    struct SNode * x = NULL;

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