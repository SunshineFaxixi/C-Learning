#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void Push(int x);
    int Pop();
    int Peek(int index);
    int IsEmpty();
    int IsFull();
    int StackTop();
};

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    Node *p = top;
    while(p)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::Push(int x)
{
    Node *t = new Node;
    if(!t)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::Pop()
{
    int x = -1;

    if(!top)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node *t = top;
        top = top->next;
        x = t->data;
        delete(t);
    }
    return x;
}

int Stack::IsEmpty()
{
   return top ? 0 : 1;
}

int Stack::IsFull()
{
    Node *t = new Node;
    int r = t ? 0 : 1;
    delete(t);
    return r;
}

int Stack::Peek(int index)
{
    int i;

    if(IsEmpty())
    {
        return -1;
    }
    else
    {
        Node *p = top;
        for(i = 0; (p != NULL) && (i < index - 1); i++)
            p = p->next;
        if(p)
            return p->data;
        else
            return -1;
    }
}

int Stack::StackTop()
{
    if(top)
        return top->data;
    return -1;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    Stack stk;
    int i;

    for(i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        stk.Push(A[i]);

    cout << "Stack peek at 3rd: " << stk.Peek(3) << endl;
    cout << "Stack peek at 10th: " << stk.Peek(10) << endl;
    cout << "Stack top: " << stk.StackTop() << endl;
    cout << "Stack empty: " << stk.IsEmpty() << endl;
    cout << "Stack full: " << stk.IsFull() << endl;

    cout << "Popped: " << endl;
    for(i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        cout << stk.Pop() << ", " << flush;
    cout << endl;

    return 0;
}
