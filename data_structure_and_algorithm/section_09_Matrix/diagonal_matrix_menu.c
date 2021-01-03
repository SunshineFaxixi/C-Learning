#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n, choice, i, j, x;
    int *A;

    printf("Enter the dimension: ");
    scanf("%d", &n);

    A = (int *)malloc(n * sizeof(int));

    do{
        printf("1. Create\n");
        printf("2. Set\n");
        printf("3. Get\n");
        printf("4. Display\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                for (i = 0; i < n; i++)
                {
                    A[i] = 0;
                }
                break;
            }
            case 2:
            {
                printf("Enter row, col, value: \n");
                scanf("%d %d %d", &i, &j, &x);
                if(i == j)
                    A[i - 1] = x;
                break;
            }
            case 3:
            {
                printf("Enter row, col:\n");
                scanf("%d %d", &i, &j);
                if(i == j)
                    printf("%d\n", A[i - 1]);
                else
                    printf("0 ");
                break;
            }
            case 4:
            {
                for (i = 1; i <= n; i++)
                {
                    for (j = 1; j <= n; j++)
                    {
                        if(i == j)
                            printf("%d ", A[i - 1]);
                        else
                            printf("0 ");
                    }
                    printf("\n");
                }
                printf("\n");
                break;
            }
        }
    } while (choice <= 4);

    return 0;
}