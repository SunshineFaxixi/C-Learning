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
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void EnQuene(struct Quene *q, int x)
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

int DeQuene(struct Quene *q)
{
    int x = -1;

    if(q->rear == q->front)
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

void Display(struct Quene q)
{
    int i = q.front + 1;

    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

int main()
{
    struct Quene q;
    int i;
    int A[] = {1, 3, 5, 6, 7};
    Create(&q, 5);

    for(i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        EnQuene(&q, A[i]);
    
    Display(q);

    printf("%d\n", DeQuene(&q));

    return 0;
}