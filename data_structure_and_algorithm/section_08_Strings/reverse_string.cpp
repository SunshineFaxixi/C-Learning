#include<stdio.h>


int main()
{

    // ===================方法一=======================
    // char A[] = "python";
    // char B[7];
    // int i, j;

    // for (i = 0; A[i] != '\0'; i++)
    // {

    // }
    // i = i - 1;
    // for (j = 0; i >= 0; j++, i--)
    // {
    //     B[j] = A[i];
    // }
    // B[j] = '\0';
    // printf("%s\n", B);

    // return 0;

    // ===================方法二=======================
    char A[] = "python";
    int i, j;
    char t;

    for (j = 0; A[j] != '\0'; j++)
    {

    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        t = A[i];
        A[i] = A[j];
        A[j] = t;366666666666666666666666666
    }

    printf("%s\n", A);

    return 0;
}