
#include <stdio.h>
#include "calendar.h"

int main()
{
	int month;
	long year;

	printf("Gregorian Calendar Calculator");
	printf("\n");
	printf("=============================");
	printf("\n\n");

	printf("Enter Month (1-12) = ");
	scanf("%d",&month);

	while(month < 1 || month > 12)
	{
		printf("\nInvalid Month, Please Enter Again (1-12) - ");
		scanf("%d",&month);
	}

	printf("\nEnter Year = ");
	scanf("%ld",&year);

	while(year < 1)
	{
		printf("\nInvalid Year, Please Enter Again - ");
		scanf("%ld",&year);
	}

	display_month(month, year);

	return 0;
}




















