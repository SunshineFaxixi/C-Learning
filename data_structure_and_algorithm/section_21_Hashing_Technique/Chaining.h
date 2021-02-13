#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int key)
{
    struct Node *t;
    struct Node *p = *H;
    struct Node *q = NULL;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;
    if(*H == NULL)
        *H = t;
    else
    {
        while(p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if(p == *H)
        {
            t->next = *H; 
            *H = t;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }
}

struct Node *Search(struct Node *p, int key)
{
    while(p)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}