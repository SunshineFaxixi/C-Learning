#include<stdio.h>
#include "Chaining.h"

int Hash(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    int index = Hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HashTable[10];
    struct Node *temp;
    int i;

    for(i = 0; i < 10; i++)
        HashTable[i] = NULL;

    Insert(HashTable, 42);
    Insert(HashTable, 22);
    Insert(HashTable, 52);

    temp = Search(HashTable[Hash(22)], 22);
    if(temp)
        printf("Find: %d\n", temp->data);
    else
        printf("Not found.\n");
    

    return 0;
}