#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *A;
};

void Create(struct Stack *st)
{
    printf("Enter the size of the stack: ");
    scanf("%d",&st->size);
    st->A = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void Display(struct Stack st)
{
    int i;

    for(i = st.top; i >= 0; i--)
    {
        printf("%d ", st.A[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int x)
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

int Pop(struct Stack *st)
{
    int x = -1;

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

int Peek(struct Stack st, int index)
{
    if(st.top + 1 - index < 0)
    {
        printf("Invalid Position\n");
        return -1;
    }
    else
    {
        return st.A[st.top + 1 - index];
    }
}

int IsEmpty(struct Stack st)
{
    return (st.top == -1);
}

int IsFull(struct Stack st)
{
    return (st.top == st.size-1);
}

int StackTop(struct Stack st)
{
    if(IsEmpty(st))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return st.A[st.top];
    }
    
}

int main()
{
    struct Stack st;
    Create(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);
    // Display(st);
    // printf("pop data is %d\n", Pop(&st));
    // Display(st);
    printf("is empty: %d\n", IsEmpty(st));
    printf("is Full: %d\n", IsFull(st));
    printf("Peek value: %d\n", Peek(st, 2));
    printf("StackTop value: %d\n", StackTop(st));
    return 0;
}