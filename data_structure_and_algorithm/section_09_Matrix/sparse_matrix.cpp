#include<iostream>

using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    struct Element *ele;
public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }
    void Read()
    {
        cout << "Enter all the elements" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
        }
    }

    void Display()
    {
        int k = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if((i == ele[k].i) && (j == ele[k].j))
                {
                    cout << ele[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Sparse s1(5, 5, 5);
    s1.Read();
    s1.Display();
    return 0;
}