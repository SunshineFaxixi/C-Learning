#include<stdio.h>

void Insertion(int A[], int n)
{
    int i, j, x;

    for(i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while((j > -1) && (A[j] > x))
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(int);
    int i;

    Insertion(A, n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}