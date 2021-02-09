#include<stdio.h>

void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    i = l; j = mid + 1; k = l;
    int B[100];

    while((i <= mid) && (j <= h))
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i <= mid; i++)
        B[k++] = A[i];
    for(; j <= h; j++)
        B[k++] = A[j];
    for(i = l; i <= h; i++)
        A[i] = B[i];
}

void IMergeSort(int A[], int n)
{
    int p, i, l, mid, h;

    for(p = 2; p <= n; p = p * 2)
    {
        for(i = 0; i + p < n + 1; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    if(p / 2 < n)
        Merge(A, 0, p/2 - 1, n - 1);
}

void RMergeSort(int A[], int l, int h)
{
    int mid;

    if(l < h)
    {
        mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(int);
    int i;

    // IMergeSort(A, n);
    RMergeSort(A, 0, n - 1);

    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}