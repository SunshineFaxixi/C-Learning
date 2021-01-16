#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

void Create(int A[], int n)
{
    struct Node *last, *t;
    int i;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);

    printf("\n");
}

void RDisplay(struct Node *h)
{
    static int flag = 0;

    if((h != head) || (flag == 0))
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}

int Length(struct Node *h)
{
    int l = 0;
    do
    {
        l++;
        h = h->next;
    } while (h != head);

    return l;
}

void Insert(struct Node *h, int index, int x)
{
    int i;
    struct Node *t;

    if(index < 0 || index > Length(h))
        return;
    if(index == 0)
    {
        t = malloc(sizeof(struct Node));
        t->data = x;
        if(h == NULL)
        {
            head = t;
            t->next = head;
        }
        else
        {
            while(h->next != head) h = h->next;
            t->next = head;
            h->next = t;
            head = t;
        }
    }
    else
    {
        for(i = 0; i < index - 1; i++)
        {
            h = h->next;
        }
        t = malloc(sizeof(struct Node));
        t->data = x;
        t->next = h->next;
        h->next = t;
    }
}

int main()
{
    // int A[] = {2, 3, 4, 5, 6};
    // Create(A, 5);

    
    // Insert(head, 2, 10);
    // Display(head);
    // RDisplay(head);

    // ============== Insert ===============
    int A[] = {2, 3, 4, 5, 6};
    Create(A, 5);
    printf("len=%d\n", Length(head));
    // Insert(head, 2, 10);
    // Insert(head, 0, 10);
    Insert(head, 5, 10);
    Display(head);

    return 0;
}