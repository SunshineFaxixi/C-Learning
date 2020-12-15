#include<stdio.h>
#include<stdlib.h>

int main()
{
    // int A[5];
    // int B[5] = {1, 2, 3, 4, 5};
    // int C[10] = {2, 4, 6};
    // int D[5] = {0};
    // int E[] = {1, 2, 3, 4, 5, 6};

    // int i;
    // for (i = 0; i < 5; i++)
    // {
    //     printf("%u\n", &A[i]);
    // }

    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    int i;

    p = (int *)malloc(5 * sizeof(int));
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;
 

























 
    for (i = 0; i < 5; i++)
        printf("%d ", A[i]);

    printf("\n");
    for (i = 0; i < 5; i++)
        printf("%d ", p[i]);
    printf("\n");

    return 0;
}