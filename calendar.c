#include <stdio.h>
#include <stdbool.h>

// a.
bool is_leap_year(int year) 
{
  if ( year%400 == 0) // Exactly divisible by 400 e.g. 1600, 2000
    return true;
  else if ( year%100 == 0) // Exactly divisible by 100 and not by 400 e.g. 1900, 2100
    return false;
  else if ( year%4 == 0 ) // Exactly divisible by 4 and neither by 100 nor 400 e.g. 2016, 2020
    return true;
  else // Not divisible by 4 or 100 or 400 e.g. 2017, 2018, 2019
    return false;    
}


// b. 
int days_in_month(int month, int year) 
{
    if(month == 9 || month == 4 || month == 6 || month == 11)
    	return 30;
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    	return 31;
    else if(month == 2 && is_leap_year(year)==true)
    	return 29;
    else
    	return 28;
}

// c.
int days_from_epoch(int day, int month, int year) 
{
    int days = 0;
    int i = 0;
    int j = 0;
    int diff = 0;

    if(year<1970)
    {
    	diff = 1970 - year;

    	for(j=1;j<diff;j++)
    	{
    		if(is_leap_year(1970-j))
    			days+=366;
    		else
    			days+=365;
		}
    	
		for(i=month+1;i<=12;i++)
			days += days_in_month(i-1,year);

		days += (days_in_month(month,year)-day+1);
    }

    else
    {
    	diff = year - 1970;

    	for(j=0;j<diff;j++)
    	{
    		if(is_leap_year(1970+j))
    			days+=366;
    		else
    			days+=365;
		}

		for(i=1;i<month;i++)
			days += days_in_month(i,year);

		days += (day-1);
	}

	return days;
}

// d.
int day_of_week(int day, int month, int year) 
{
    int _day = days_from_epoch(day,month,year)%7;

    if(year>1970)
    {
    	switch(_day)
    	{
    		case 0 : 
    			return 4;
    		case 1 :
    			return 5;
    		case 2 : 
    			return 6;
    		case 3 :
    			return 0;
    		case 4 : 
    			return 1;
    		case 5 :
    			return 2;
    		case 6 : 
    			return 3;

    	}
    }
    else
    {
    	switch(_day)
    	{
    		case 0 : 
    			return 4;
    		case 1 :
    			return 3;
    		case 2 : 
    			return 2;
    		case 3 :
    			return 1;
    		case 4 : 
    			return 0;
    		case 5 :
    			return 6;
    		case 6 : 
    			return 5;

    	}
    }
}    


// e. 
void display_month(int month, int year) 
{
 	
 	printf("\nTHE CALENDAR FOR %d-%d IS -\n",month,year); 
 	printf("\n  S  M  T  W  T  F  S\n");

 	int begin = day_of_week(1,month,year);
 	int i = 0;
 	int count = 0;

 	for(i=0;i<3*begin;i++)
 	{
 		printf(" ");
 		++count;
 	}

 	for(i=1;i<=days_in_month(month,year);i++)
 	{
 		printf("%3d",i);
 		count+=3;
 		if(count%21==0)
 			printf("\n");
 	}
 	printf("\n\n");
}