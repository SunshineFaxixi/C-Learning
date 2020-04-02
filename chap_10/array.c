#include<stdio.h>
#define SIZE 50

int main(void)
{
    int counter, events[SIZE];

    for(counter = 0; counter < SIZE; counter++)
    {
        events[counter] = 2 * counter;
    }

    return 0;
}
