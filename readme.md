# PrintCalendar

Simple C Implementation to Print the Gregorian Calendar for any given month and year

Structure:
  
  calendar.c - contains the definition for the functions used 
    
    1. is_leap_year()    : to determine given year is a leap year
    2. days_in_month()   : returns the number of days in that given month
    3. days_from_epoch() : returns the number of days from epoch, 1 January 1970
    4. day_of_week()     : returns the day of the week of the given date, epoch was a Thursday
    5. display_month()   : prints the calendat
    
  main.c - driver program
  
  
  * You can use the 'run' file to directly test the program
  * calendar.a is the library that can be statically linked to your own program
