#include<stdio.h>
#include<stdlib.h>

int FindMax(int A[], int n)
{
    int i;
    int max = INT_MIN;

    for(i = 0; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int max, i, j;
    int *C;

    max = FindMax(A, n);
    C = (int *)malloc(sizeof(int) * (max + 1));
    for(i = 0; i < max + 1; i++)
        C[i] = 0;
    for(i = 0; i < n; i++)
        C[A[i]]++;
    i = 0, j = 0;
    while(i < max + 1)
    {
        if(C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(int);
    int i;

    // IMergeSort(A, n);
    // RMergeSort(A, 0, n - 1);
    CountSort(A, n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}