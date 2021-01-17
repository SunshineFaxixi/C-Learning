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

int IsBalance1(char *st)  // check {}, [], ()
{
    int i;
    char x;

    for(i = 0; st[i] != '\0'; i++)
    {
        if((st[i] == '{') || (st[i] == '[') || (st[i] == '('))
            Push(st[i]);
        if((st[i] == '}') || (st[i] == ']') || (st[i] == ')'))
        {
            if(top != NULL)
            {
                x = Pop();
                if(((st[i] == '}') && (x != '{')) || 
                   ((st[i] == ']') && (x != '[')) ||
                   ((st[i] == ')') && (x != '(')))
                    return 0;
            }
            else
            {
                return 0;
            }
        }
    }
    return (top == NULL);
}

int main()
{
    // char *st = "((((a+b)*(c-d)))";
    // printf("is balanced: %d\n", IsBalance(st));

    char *st1 = "{{{([a+b]*[c-d])/e}}";
    printf("is balanced: %d\n", IsBalance1(st1));
    return 0;
}