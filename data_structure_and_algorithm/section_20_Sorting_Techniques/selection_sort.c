#include<stdio.h>

void Swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[], int n)
{
    int i, j, k;

    for(i = 0; i < n - 1; i++)
    {
        for(j = k = i; j < n; j++)
        {
            if(A[k] > A[j])
                k = j;
        }
        Swap(&A[k], &A[i]);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(int);
    int i;

    SelectionSort(A, n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}