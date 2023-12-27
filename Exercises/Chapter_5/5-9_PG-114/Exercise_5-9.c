#include <stdio.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main(int argc, char const *argv[])
{
    dprintINT(day_of_year(2020,4,19));
    int month;
    int day;
    month_day(2021,365,&month,&day);
    dprintINT(month);
    dprintINT(day);

    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (year < 0 || month < 0 || month > 12 || day < 0 || day > *(*(daytab+1) + month)){
        printf("ERROR: Invalid input\n");
        return -1;
    }
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year%400 == 0;
    for (i = 1; i< month; i++)
        day += *(*(daytab+leap) + i);
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year < 0 || yearday < 0 || yearday > 365){
        printf("ERROR: Invalid input\n");
        *pmonth = -1;
        *pday = -1;
        return;
    }
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year%400 == 0;
    for (i = 1; yearday > *(*(daytab+leap) + i); i++)
        yearday -= *(*(daytab+leap) + i);
    *pmonth = i;
    *pday = yearday;
}

