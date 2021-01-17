#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node *next;
}*top = NULL;

void Push(char x)
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
    char x = -1;
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

int IsBalance(char *st)
{
    int i;

    for(i = 0; st[i] != '\0'; i++)
    {
        if(st[i] == '(')
            Push(st[i]);
        else if(st[i] == ')')
        {
            if(top == NULL)
                return 0;
            Pop();
        }
    }
    return (top == NULL);
}

int main()
{
    char *st = "((((a+b)*(c-d)))";
    printf("is balanced: %d\n", IsBalance(st));
    return 0;
}