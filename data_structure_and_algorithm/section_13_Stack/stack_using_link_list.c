#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void Push(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(!t)
    {
        printf("stack is full\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop()
{
    int x = -1;
    struct Node *p;

    if(!top)
    {
        printf("stack empty\n");
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }

    return x;
}

void Display()
{
    struct Node *p = top;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Display();
    printf("%d ", Pop());
    printf("%d ", Pop());
    return 0;
}