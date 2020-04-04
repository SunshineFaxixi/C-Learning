#include<stdio.h>

#define YEAR 5
#define MONTH 12

int main(void)
{
    const float rain[YEAR][MONTH] = 
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };
    int year, month;
    float total, subtotal;

    printf("YEAR    RAINFALL (inches)\n");
    for(year = 0, total = 0; year < YEAR; year++)
    {
        for(month = 0, subtotal = 0; month < MONTH; month++)
        {
            subtotal += rain[year][month];
        }
        printf("%5d %15.1f\n", year, subtotal);
        total += subtotal;
    }
    printf("\nThe yearly average is %.1f inches.\n", (total / YEAR));
    
    printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Des\n");
    for(month = 0, total = 0; month < MONTH; month++)
    {
        for(year = 0, subtotal = 0; year < YEAR; year++)
        {
            subtotal += rain[year][month];
        }
        printf("%4.1f", (subtotal / YEAR));
    }
    return 0;
}


