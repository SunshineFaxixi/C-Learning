#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Create(int A[], int n)
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

void Create2(int A[], int n)
{
    struct Node *last, *temp;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *p)
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

int Count(struct Node *p)
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

int Sum(struct Node *p)
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

int Max(struct Node *p)
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
    struct Node *t, *q = NULL;

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

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int i;
    int x = -1;

    if(index < 1 || index > Count(p))
        return -1;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; p && (i < index - 1); i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

int IsSorted(struct Node *p)
{
    int x = INT_MIN;
    while(p)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }

    return 1;
}

void RemoveDuplicated(struct Node *p)
{
    struct Node *q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }

}

void Reverse1(struct Node *p)
{
    int *A;
    int i = 0;
    struct Node *q = p;

    A = (int *) malloc(sizeof(int) * Count(p));

    while(q)
    {
        A[i++] = q->data;
        q = q->next;
    }

    q = p;
    i--;
    while(q)
    {
        q->data = A[i--];
        q = q->next;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if(p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concat(struct Node *p, struct Node *q)
{
    third = p;

    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}

struct Node *Merge(struct Node *first, struct Node *second)
{
    struct Node *last;

    if(first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    while(first && second)
    {
        if(first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if(first)
        last->next = first;
    else
        last->next = second;

    return third;
}

int IsLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;
    } while (p && q && (p != q));

    return (p == q) ? 1 : 0;
}

int main()
{
    // int A[] = {43, 5, 7, 40, 25, 20, 53};
    // Create(A, 7);
    // // printf("\nwhile loop:\n");
    // Display(first);
    // printf("\nrecursion:\n");
    // RDisplay(first);
    // printf("\nreverse print:\n");
    // Reverse_RDisplay(first);
    
    // printf("\n");
    // printf("Length is %d\n", Count(first));
    // printf("RLength is %d\n", Rcount(first));

    // printf("Sum is %d\n", Sum(first));
    // printf("RSum is %d\n", Rsum(first));

    // printf("Max is %d\n", Max(first));
    // printf("RMax is %d\n", Rmax(first));

    // Display(first);
    // printf("\n");

    // Insert(first, 0, 8);
    // Insert(first, 1, 10);
    // Insert(first, 2, 21);
    // display(first);
    // printf("\n");
    // printf("delete element is %d\n", Delete (first, 10));
    // Display(first);

    // int A[] = {43, 5, 7, 40, 25, 20, 53};
    // int A[] = {5, 7, 20, 53};
    // Create(A, 4);
    // Display(first);
    // printf("\n");
    // if(IsSorted(first))
    //     printf("Sorted\n");
    // elseglgl
    //     printf("Not Sorted\n");
// ============ Concat =====================
    int A1[] = {11, 13, 15, 17, 19, 25};
    Create(A1, 6);
    Display(first);
    printf("\n");

    int A2[] = {10, 12, 14, 16, 20, 24};
    Create2(A2, 6);
    Display(second);
    printf("\n");

    Concat(second, first);
    Display(third);
    printf("\n");
// ============ Merge ======================
    // int A1[] = {11, 13, 15, 17, 19, 25};
    // Create(A1, 6);
    // Display(first);
    // printf("\n");

    // int A2[] = {10, 12, 14, 16, 20, 24};
    // Create2(A2, 6);
    // Display(second);
    // printf("\n");

    // struct Node *p3 = Merge(first, second);
    // Display(p3);
    // printf("\n");

    // ===============================================

    // removeDuplicated(first);
    // Reverse1(first);
    // Reverse2(first);
    // Reverse3(NULL,first);

    // display(first);
    // printf("\n");

    return 0;
}