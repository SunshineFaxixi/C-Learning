#include<stdio.h>
#define BLURB "Authentic imitation!"

int main(void)
{
	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d**% d**\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**\n", 6, 6, 6);
	return 0;
}
