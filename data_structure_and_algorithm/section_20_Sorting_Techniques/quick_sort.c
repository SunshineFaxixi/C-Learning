#include<stdio.h>

void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int A[], int l, int h)
{
    int i = l, j = h;
    int pivot = A[l];

    do
    {
        do{i++;}while(A[i] <= pivot);
        while(A[j] > pivot){j--;}
        if(i < j) Swap(&A[i], &A[j]);
    } while (i < j);
    Swap(&A[j], &A[l]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;

    if(l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(int);
    int i;

    QuickSort(A, 0, n - 1);

    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}