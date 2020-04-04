#include<stdio.h>

#define PI 3.141593

int main(void)
{
	int number = 7;
	float pies = 12.75;
	int cost = 7800;

	printf("The %d contestants ate %f berry pies.\n", number, pies);
	printf("The value of pi is %f.\n", PI);
	printf("Farewell! thou art too dear for my possessing,\n");
	printf("%c%d\n", '$', cost);
	printf("only %d%% of Sally's gribbles were ediable.\n", 2 * 6);

	return 0;
}

