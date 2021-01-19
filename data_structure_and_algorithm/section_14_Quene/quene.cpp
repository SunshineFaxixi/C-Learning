#include<iostream>

using namespace std;

class Quene
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Quene();
    Quene(int size);
    ~Quene();
    void EnQuene(int x);
    int DeQuene();
    void Display();
};

Quene::Quene()
{
    size = 10;
    front = rear = -1;
    Q = new int[size];
}

Quene::Quene(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int[this->size];
}

Quene::~Quene()
{
    delete []Q;
}

void Quene::EnQuene(int x)
{
    if(rear == size - 1)
        cout << "Quene is full" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Quene::DeQuene()
{
    int x = -1;

    if(front == rear)
        cout << "Quene is empty" << endl;
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Quene::Display()
{
    int i;

    for(i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    Quene q(sizeof(A) / sizeof(int));
    for(int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
        q.EnQuene(A[i]);
    q.Display();

    return 0;
}