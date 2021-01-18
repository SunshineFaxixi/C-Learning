#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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

int IsOperator(char x) 
{
    if((x == '+') || (x == '-') || (x == '*') || (x == '/'))
        return 1;
    else
        return 0;
}

int Eval(char *postfix)
{
    int i;
    int x1, x2;
    int r;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(!IsOperator(postfix[i]))
            Push(postfix[i] - '0');
        else
        {
            x2 = Pop();
            x1 = Pop();
            switch(postfix[i])
            {
                case '+': r = x1 + x2; break; 
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            Push(r);
        }
    }
    return(top->data);
}

int main()
{
    char *postfix = "234*+82/-";
    printf("Result is %d\n", Eval(postfix));

    return 0;
}