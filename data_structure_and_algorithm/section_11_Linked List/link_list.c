#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *last, *temp;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

void Reverse_RDisplay(struct Node *p)
{
    if(p != NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}

int count(struct Node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p = p->next;
    }

    return l;
}

int Rcount(struct Node *p)
{
    if(p != NULL)
    {
        return Rcount(p->next) + 1;
    }
    else
        return 0;
}

int sum(struct Node *p)
{
    int s = 0;

    while(p)
    {
        s += p->data;
        p = p->next;
    }

    return s;
}

int Rsum(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

int max(struct Node *p)
{
    int m = INT_MIN;
    while(p)
    {
        if(p->data > m)
            m = p->data;
        p = p->next;
    }

    return m;
}

int Rmax(struct Node *p)
{
    int x = 0;

    if(p == NULL)
        return INT_MIN;
    x = Rmax(p->next);
    return x > p->data ? x : p->data;
}

struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while(p)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }    
            
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node *RSearch(struct Node *p, int key)
{
    if(!p)
        return NULL;
    if(p->data == key)
        return p;
    return RSearch(p->next, key);
}

void Insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    int i;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(pos == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; (i < pos - 1) && p; i++)
        {
            p = p->next;
        }
        if(p)
        {
            t->next = p->next;
            p->next = t;
        }
    }
}

void InsertSorted(struct Node *p, int x)
{
    struct Node *t, *q;
    int i;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        while(p && (p->data < x))
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    // int A[] = {43, 5, 7, 40, 25, 20, 53};
    // create(A, 7);
    // printf("\nwhile loop:\n");
    // display(first);
    // printf("\nrecursion:\n");
    // RDisplay(first);
    // printf("\nreverse print:\n");
    // Reverse_RDisplay(first);
    
    // printf("\n");
    // printf("Length is %d\n", count(first));
    // printf("RLength is %d\n", Rcount(first));

    // printf("Sum is %d\n", sum(first));
    // printf("RSum is %d\n", Rsum(first));

    // printf("Max is %d\n", max(first));
    // printf("RMax is %d\n", Rmax(first));

    display(first);
    printf("\n");

    Insert(first, 0, 8);
    Insert(first, 1, 10);
    Insert(first, 2, 21);
    display(first);
    printf("\n");

    return 0;
}