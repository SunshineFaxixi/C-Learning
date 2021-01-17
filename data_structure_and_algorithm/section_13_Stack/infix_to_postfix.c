#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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

char Pop()
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

int IsOperator(char x)
{
    if((x == '+') || (x == '-') || (x == '*') || (x == '/'))
        return 1;
    else
        return 0;
}

int Pre(char x)  // 优先级
{
    if((x == '+') || (x == '-'))
        return 1;
    else if((x == '*') || (x == '/'))
        return 2;
    return 0;
}

char *InfixToPostfix(char *infix)
{
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(len + 1));
    int i, j;
    i = j = 0;

    while(infix[i] != '\0')
    {
        if(!IsOperator(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(top)
            {
                if(Pre(infix[i]) > Pre(top->data))
                    Push(infix[i++]);
                else
                {
                    postfix[j++] = Pop();
                }
            }
            else
            {
                Push(infix[i++]);
            }
        }
    }
    while(top)
        postfix[j++] = Pop();
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    char *postfix = InfixToPostfix(infix);
    printf("%s\n", postfix);

    return 0;
}