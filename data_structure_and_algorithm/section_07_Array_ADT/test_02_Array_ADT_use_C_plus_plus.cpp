#include<iostream>
using namespace std;
class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[sz];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
};

void Array::Display()
{
    int i;
    cout << "Elements are\n";
    for (i = 0; i < length; i++)
        cout << A[i] << " ";
}

void Array::Append(int x)
{
    if(length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x)
{
    int i;
    if(index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
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
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }

    return 0;
}

void Array::swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key)
{
    int i;

    for (i = 0; i < length; i++)
    {
        if(A[i] == key)
        {
            swap(&A[i], &A[0]);
            return i;
        }
    }

    return -1;
}

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of Array";
    scanf("%d", &sz);
    arr1 = new Array(sz);

    do
    {
        cout << "\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice ";
        cin >> ch;
        switch(ch)
        {
            case 1:
                cout << "Enter an element and index";
                cin >> x >> index;
                arr1->Insert(index, x);
                break;
            case 2:
                cout << "Enter index";
                x = arr1->Delete(index);
                cout << "Deleted Element is" << x;
                break;
            case 3:
                cout << "Enter Element to search";
                cin >> x;
                index = arr1->LinearSearch(x);
                cout << "Element index " << index;
                break;
            case 4:
                // cout << "Sum is " << arr1->Sum();
                break;
            case 5:
                arr1->Display();
                break;
        }
    } while (ch < 6);

    return 0;
}