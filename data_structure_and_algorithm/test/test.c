#include<stdio.h>
#include "test1.c"
#include<time.h>

static int variable = 10;

void printVar1()
{
    int count = 0;

    count++;
}

void printVar()
{
    static int count = 0;
    count++;
    printf("print %d times\n", count);
}

void copyij(int src[2048][2048], int dst[2048][2048])
{
    int i, j;
    for(i = 0; i < 2048; i++)
    {
        for(j = 0; j < 2048; j++)
            dst[i][j] = src[i][j];
    }
}

void copyji(int src[2048][2048], int dst[2048][2048])
{
    int i, j;
    for(j = 0; j < 2048; j++)
    {
        for(i = 0; i < 2048; i++)
            dst[i][j] = src[i][j];
    }
}

int main()
{
    // // static in function test
    // int i;
    // printVar1();
    // for(i = 0; i < 5; i++)
    // {
    //     printVar();
    //     printVar1();
    // }    

    // // static outof function test
    // printf("variable = %d\n", variable);
    // callfunc();
    // printf("variable = %d\n", variable);

    // for(int i = 0; i < 8; ++i)909738
    // {
    //     printf("%d ", i);
    // }
    // printf("%d\n", 40000 * 40000);
    // printf("%f\n", 1e20 + ((-1e20) + 3.14));

    int src[2048][2048] = {1};
    int dst[2048][2048] = {0};

    clock_t start, end;
    start = clock();
    copyij(src, dst);
    end = clock();
    printf("%f\n", (float)(end-start)*1000/CLOCKS_PER_SEC);
    // copyji();

    return 0;
}