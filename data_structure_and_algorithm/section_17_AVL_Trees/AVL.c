#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int bf;
    struct Node *rchild;
}*root = NULL;

void PreOrder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void PostOrder(struct Node *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%d ", p->data);
    }
}

int Height(struct Node *p)
{
    int x = 0, y = 0;
    if(!p)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? (x + 1) : (y + 1);
}

struct Node *LLRotation(struct Node *p)
{
    int lbf = 0, rbf = 0;
    struct Node *pl = p->lchild;

    pl->bf = 0;
    p->lchild = pl->rchild;
    pl->rchild = p;
    lbf = Height(p->lchild) + 1;
    rbf = Height(p->rchild) + 1;
    p->bf = lbf - rbf;
    if(p == root) root = pl;
    return pl;
}

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    int lbf, rbf;

    plr->bf = 0;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    lbf = Height(pl->lchild) + 1;
    rbf = Height(pl->rchild) + 1;
    pl->bf = lbf - rbf;

    lbf = Height(p->lchild) + 1;
    rbf = Height(p->rchild) + 1;
    p->bf = lbf - rbf;

    if(p == root) root = plr;
    return plr;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t;
    int lbf, rbf;

    if(!p)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->bf = 0;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    
    lbf = Height(p->lchild) + 1;
    rbf = Height(p->rchild) + 1;
    p->bf = lbf - rbf;
    if((p->bf == 2) && (p->lchild->bf == 1))
        return LLRotation(p);
    if((p->bf == 2) && (p->lchild->bf == -1))
        return LRRotation(p);
    // if((p->bf == -2) && (p->rchild->bf == 1))
    //     return RRRotation(p);
    // if((p->bf == -2) && (p->rchild->bf == -1))
    //     return RLRotation(p);
    return p;
}

int main()
{
    root = RInsert(root, 50);
    root = RInsert(root, 20);
    root = RInsert(root, 25);

    PreOrder(root);
    printf("\n");
    PostOrder(root);
    return 0;
}