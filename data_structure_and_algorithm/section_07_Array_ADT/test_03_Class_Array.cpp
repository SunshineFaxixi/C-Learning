#include<iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        A = new int[10];
        size = 10;
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new int[size];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
};

void Array::Display()
{
    int i;

    cout << "Elements are\n";
    for (i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::Insert(int index, int x)
{
    int i;
    if(index >= 0 && index <= length)
    {
        for (i = length - 1; i >= index; i--)
            A[i + 1] = A[i];
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index)
{
    int i;
    int x = 0;

    if(index >= 0 && index < length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }

    return x;
}

int main()
{
    Array arr(10);
    arr.Insert(0, 10);
    arr.Insert(1, 19);
    arr.Insert(2, 30);
    arr.Display();
    cout <<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}