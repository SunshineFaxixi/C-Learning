#include<stdio.h>
#include<stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

void Create(struct Poly *p)
{
    printf("Enter the terms: ");
    scanf("%d", &p->n);
    p->t = (struct Term *)malloc(p->n * sizeof(struct Term));
    for (int i = 0; i < p->n; i++)
    {
        printf("Enter No %d: \n", i + 1);
        scanf("%d %d", &p->t[i].coeff, &p->t[i].exp);
    }
}

void Display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        printf("%dx%d+", p.t[i].coeff, p.t[i].exp);
    }
    printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    struct Poly *p3;

    p3 = (struct Poly *)malloc(sizeof(struct Poly));
    p3->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    i = j = k = 0;
    while(i < p1->n &&j < p2->n)
    {
        if(p1->t[i].exp > p2->t[j].exp)
            p3->t[k++] = p1->t[i++];
        else if(p1->t[i].exp < p2->t[j].exp)
            p3->t[k++] = p2->t[j++];
        else
        {
            p3->t[k].exp = p1->t[i].exp;
            p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }

    for (; i < p1->n; i++)
        p3->t[k++] = p1->t[i];
    for (; j < p2->n; j++)
        p3->t[k++] = p2->t[j];

    p3->n = k;
    return p3;
}

int main()
{
    struct Poly p1, p2, *p3;
    Create(&p1);
    Create(&p2);
    p3 = add(&p1, &p2);

    printf("\n");
    Display(p1);

    printf("\n");
    Display(p2);

    printf("\n");
    Display(*p3);

    return 0;
}