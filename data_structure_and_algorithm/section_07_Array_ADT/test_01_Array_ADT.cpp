#include<stdio.h>
#include<stdlib.h>

// struct Array
// {
//     int *A;
//     int size;
//     int length;
// };

struct Array1
{
    int *A;
    int size;
    int length;
};

void Display(struct Array1 arr)
{
    printf("Elements are\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void append(struct Array1 *arr1, int x)
{
    if(arr1->length < arr1->size)
    {
        arr1->A[arr1->length++] = x;
    }
}

void insert(struct Array1 *arr1, int index, int x)
{
    int i;

    if((index >= 0) && (index <= arr1->length))
    {
        for (i = arr1->length; i > index; i--)
        {
            arr1->A[i] = arr1->A[i - 1];
        }
        arr1->A[index] = x;
        arr1->length++;
    }
}

int Delete(struct Array1 *arr1, int index)
{
    int i;

    if((index >= 0) && (index < arr1->length))
    {
        int x = arr1->A[index];
        for (i = index; i < arr1->length - 1; i++)
        {
            arr1->A[i] = arr1->A[i + 1];
        }
        arr1->length--;
        return x;
    }

    return 0;
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array1 *arr1, int key)
{
    int i;

    for (i = 0; i < arr1->length; i++)
    {
        if(arr1->A[i] == key)
        {
            swap(&arr1->A[i], &arr1->A[0]);

            return i;
        }
    }

    return -1;
}

int BinarySearch(struct Array1 arr1, int key)
{
    int l, h, mid;
    l = 0;
    h = arr1.length - 1;

    while(l <= h)
    {
        mid = (l + h) / 2;
        if(key == arr1.A[mid])
            return mid;
        else if(key < arr1.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(struct Array1 arr1, int key, int l, int h)
{
    int mid;

    if(l <= h)
    {
        mid = (l + h) / 2;
        if(key == arr1.A[mid])
            return mid;
        else if(key < arr1.A[mid])
            return RBinarySearch(arr1, key, l, mid - 1);
        else
            return RBinarySearch(arr1, key, mid + 1, h);
    }

    return -1;
}

int Get(struct Array1 arr1, int index)
{
    if(index >= 0 && index < arr1.length)
        return arr1.A[index];
    return -1;
}

void Set(struct Array1 *arr1, int index, int x)
{
    if(index >= 0 && index < arr1->length)
        arr1->A[index] = x;
}

int Max(struct Array1 arr1)
{
    int max = arr1.A[0];
    int i;
    for (i = 0; i < arr1.length; i++)
    {
        if(arr1.A[i] > max)
            max = arr1.A[i];
    }
    return max;
}

int Min(struct Array1 arr1)
{
    int min = arr1.A[0];
    int i;
    for (i = 0; i < arr1.length; i++)
    {
        if(arr1.A[i] < min)
            min = arr1.A[i];
    }
    return min;
}

int Sum(struct Array1 arr1)
{
    int total = 0;
    int i;
    for (i = 0; i < arr1.length; i++)
    {
        total += arr1.A[i];
    }
    return total;
}

float Avg(struct Array1 arr1)
{
    int total = 0;
    int i;
    for (i = 0; i < arr1.length; i++)
    {
        total += arr1.A[i];
    }
    return (total / arr1.length);
}

void Reverse(struct Array1 *arr1)
{
    int i, j;
    int *B;

    B = (int *)malloc(arr1->length * sizeof(int));
    for (i = arr1->length - 1, j = 0; i >= 0; j++, i--)
        B[j] = arr1->A[i];
    for (i = 0; i < arr1->length; i++)
        arr1->A[i] = B[i];
}

void Reverse2(struct Array1 *arr1)
{
    int i, j;
    for (i = 0, j = arr1->length - 1; i < j; i++, j--)
        swap(&arr1->A[i], &arr1->A[j]);
}

void InsertSorted(struct Array1 *arr1, int x)
{
    int i;

    if(arr1->length >= arr1->size)
        return;
    i = arr1->length - 1;
    while(i >= 0 && arr1->A[i] > x)
    {
        arr1->A[i + 1] = arr1->A[i];
        i--;
    }

    arr1->A[i + 1] = x;
    arr1->length++;
}

int isSorted(struct Array1 arr1)
{
    int i;
    for (i = 0; i < arr1.length - 1; i++)
    {
        if(arr1.A[i] > arr1.A[i + 1])
            return 0;
    }

    return 1;
}

struct Array1 *MergeSorted(struct Array1 *arr1, struct Array1 *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array1 *arr3 = (struct Array1 *) malloc(sizeof(struct Array1));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

struct Array1 *Union(struct Array1 *arr1, struct Array1 *arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array1 *arr3 = (struct Array1 *)malloc(sizeof(struct Array1));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i++];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array1 *Intersection(struct Array1 *arr1, struct Array1 *arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array1 *arr3 = (struct Array1 *)malloc(sizeof(struct Array1));
    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array1 *Difference(struct Array1 *arr1, struct Array1 *arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array1 *arr3 = (struct Array1 *)malloc(sizeof(struct Array1));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i++];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// int main()
// {
    // struct Array arr;
    // printf("Enter size of an array");
    // scanf("%d", &arr.size);
    // arr.A = (int *)malloc(arr.size * sizeof(int));

    // printf("Enter all the numbers\n");
    // for (int i = 0; i < arr.size; i++)
    // {
    //     scanf("%d", &arr.A[i]);
    // }

    // struct Array1 arr1 = {{2, 3, 8, 5, 6}, 10, 5};
    // int x;
    // append(&arr1, 10);
    // insert(&arr1, 2, 10);
    // x = Delete(&arr1, 7);
    // printf("%d\n", x);
    // x = LinearSearch(&arr1, 6);
    // x = BinarySearch(arr1, 5);
    // x = Get(arr1, 7);
    // Set(&arr1, 3, 10);
    // printf("%d\n", x);
    // printf("%d\n", Max(arr1));
    // printf("%d\n", Min(arr1));
    // printf("%d\n", Sum(arr1));
    // printf("%f\n", Avg(arr1));
    // Reverse2(&arr1);
    // InsertSorted(&arr1, 1);
    // int res = isSorted(arr1);
    // printf("%d\n", res);
    // Display(arr1);

    // struct Array1 arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    // struct Array1 arr2 = {{2, 3, 16, 18, 28}, 10, 5};
    // struct Array1 *arr3;

    // // arr3 = MergeSorted(&arr1, &arr2);
    // // arr3 = Union(&arr1, &arr2);
    // // arr3 = Intersection(&arr1, &arr2);
    // arr3 = Difference(&arr1, &arr2);
    // Display(*arr3);

    // return 0;
// }
// =======================Menu Driver=======================
int main()
{
    struct Array1 arr;
    int choice;
    int index, x;

    printf("Please Enter Size of Array");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    do{
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter the index and number to insert: ");
                scanf("%d%d", &index, &x);
                insert(&arr, index, x);
                break;
            case 2:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                x = Delete (&arr, index);
                printf("Deleted Element is %d\n", x);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &x);
                index = LinearSearch(&arr, x);
                printf("Element index %d", index);
                break;
            case 4:
                printf("Sum is %d\n", Sum(arr));
                break;
            case 5:
                Display(arr);
        }
    } while (choice < 6);

    return 0;

// ===========================================================
}