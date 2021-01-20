#include<stdio.h>
#include<stdlib.h>

struct Quene
{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Quene *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void EnQuene(struct Quene *q, int x)
{
    if(q->rear == q->size - 1)
        printf("Quene is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x; 
    }
}

int DeQuene(struct Quene *q)
{
    int x = -1;

    if(q->front == q->rear)
        printf("Quene is empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Quene q)
{   
    int i;
    for(i = q.front + 1; i < q.rear + 1; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Quene q;
    Create(&q, 5);
    int A[] = {10, 20, 30};
    for(int i = 0; i < sizeof(A) / sizeof(int); i++)
        EnQuene(&q, A[i]);
    Display(q);

    printf("%d\n", DeQuene(&q));

    return 0;
}