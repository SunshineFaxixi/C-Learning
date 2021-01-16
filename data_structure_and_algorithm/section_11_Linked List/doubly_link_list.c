#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head;

void Create(int A[], int n)
{
    struct Node *last, *t;
    int i;

    head = malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(i = 1; i < n; i++)
    {
        t = malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    while(h)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}

int Length(struct Node *h)
{
    int len = 0;
    while(h)
    {
        len++;
        h = h->next;
    }
    return len;
}

void Insert(struct Node *h, int index, int x)
{   
    struct Node *t;
    int i;

    if(index < 0 || index > Length(h))
        return;
    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = head;
        head = t;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
            h = h->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = h->next;
        t->prev = h;
        if(h->next)
            h->next->prev = t;
        h->next = t;
    }
    
}

int Delete(struct Node *h, int index)
{
    struct Node *p = h;
    int x, i;

    if(index < 1 || index > Length(h))
        return - 1;
    if(index == 1)
    {
        p = head;
        head = head->next;
        x = p->data;
        free(p);
        if(head)
            head->prev = NULL;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
        {
            p=p->next;
        }

        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *h)
{
    struct Node *temp;

    while(h)
    {
        temp = h->next;
        h->next = h->prev;
        h->prev = temp;
        h = h->prev;
        if(h != NULL && h->next == NULL)
            head = h;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40};
    Create(A, 4);
    // ================ Insert ================
    // Insert(head, 3, 29);
    // ================ Delete ================
    // int x = Delete(head, 0);    
    // printf("%d\n", x);
    // ================ Reverse ================
    Reverse(head);
    Display(head);
}