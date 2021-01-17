#include<stdio.h>
#include "test1.c"

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

int main()
{
    // static in function test
    int i;
    printVar1();
    for(i = 0; i < 5; i++)
    {
        printVar();
        printVar1();
    }    

    // static outof function test
    printf("variable = %d\n", variable);
    callfunc();
    printf("variable = %d\n", variable);

    return 0;
}