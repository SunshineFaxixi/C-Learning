#include<stdio.h>

int main()
{
    char A[] = "madam";
    int size = sizeof(A) / sizeof(char);
    int i, j;

    for (i = 0, j = size - 2; i < j; i++, j--)
    {
        if(A[i] != A[j])
            break;
    }
    if(A[i] == A[j]).
        printf("Yes");
    else
        printf("False");                                                                                                                                                                                                                         
    return 0;
}