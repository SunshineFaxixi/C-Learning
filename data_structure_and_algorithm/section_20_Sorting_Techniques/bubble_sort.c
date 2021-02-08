#include<stdio.h>

void Swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n)
{
    int i, j, temp, flag;

    for(i = 0; i < n - 1; i++)
    {
        flag = 0;
        for(j = 0; j < n - 1 - i; j++)
        {
            if(A[j] > A[j + 1])
            {
                Swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if(flag == 0)  break;
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(int);
    int i;

    BubbleSort(A, n);

    for(i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}