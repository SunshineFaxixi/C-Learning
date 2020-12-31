#include<stdio.h>

int main()
{
    // ===============方法一：略====================

    // ===============方法二=========================
    // char A[] = "finding";
    // int i;
    // int H[26] = {0};

    // for (i = 0; A[i] != '\0'; i++)
    // {
    //     H[A[i] - 97]++;
    // }

    // for (i = 0; i < 26; i++)
    // {
    //     if(H[i] > 1)
    //         printf("%c %d\n", i + 97, H[i]);
    // }

    // ===============方法三=========================
    char A[] = "finding";
    int H = 0, x, i;

    for (i = 0; A[i] != '\0'; i++)
    {
        x = 1 << (A[i] - 97);
        if((x & H) > 0)
            printf("%c is duplicated\n", A[i]);
        else
            H |= x;
    }

    return 0;
}