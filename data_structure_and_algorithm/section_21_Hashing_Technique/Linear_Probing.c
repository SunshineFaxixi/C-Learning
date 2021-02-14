#include<stdio.h>
#define SIZE 10

int Hash(int key)
{
    return key % SIZE;
}

int Probing(int HT[], int key)
{
    int index = key % SIZE;
    int i = 0;
    while(HT[((key + i)) % SIZE] != 0)
        i++;
    return (index + i) % SIZE;
}

void Insert(int HT[], int key)
{
    int index = Hash(key);

    if(HT[index] != 0)
        index = Probing(HT, key);
    HT[index] = key;
}

int Search(int HT[], int key)
{
    int i;
    int index = Hash(key);

    while(HT[(index + i) % SIZE] != key)
        i++;
    return (index + i) % SIZE;
}

int main()
{
    int HT[SIZE] = {0};

    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);

    printf("key is found at %d\n", Search(HT, 26));

    return 0;
}