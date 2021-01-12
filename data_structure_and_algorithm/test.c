#include<stdio.h>

#define SIZE 5 

int main()
{
    for (int i = 0; i < 5; i++)
    {
        if(i == SIZE-1)
            printf("%d: lllll\n", i);
    }
}