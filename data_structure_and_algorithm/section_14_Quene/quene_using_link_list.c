#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void EnQuene(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("Quene is full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int DeQuene()
{
    int x = -1;

    if(front == NULL)
    {
        printf("Quene is empty\n");
    }
    else
    {
        struct Node *p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p = front;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int A[] = {1, 2, 4, 2, 6};
    for(int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        EnQuene(A[i]);
    }

    Display();

    printf("%d\n", DeQuene());

    Display();

    return 0;
}