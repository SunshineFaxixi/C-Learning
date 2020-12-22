#include<stdio.h>

int main()
{
    int A[] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int diff = A[0] - 0;
    int i;

    for (i = 0; i < 11; i++)
    {
        if(A[i] - i != diff)
        {
            while(diff < A[i] - i)
            {
                printf("%d\n", diff + i);
                diff++;
            }
        }
    }

    return 0;
}