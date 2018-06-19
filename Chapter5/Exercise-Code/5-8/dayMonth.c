/*
 *	Date: 2018-06-19
 *	Page 111 of K&R
 *	By Rivers
*/

#include<stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (day < 1 || day > daytab[leap][month]) {
		printf("Error: illegal date\n");
		return -1;
	}
	for (i = 1; i < month; ++i) {
		day += daytab[leap][i];
	}

	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (yearday > 365 + leap) {
		printf("Error: illegal day of the year\n");
		return;
	}
	for (*pmonth = 1; yearday > daytab[leap][*pmonth]; ++*pmonth)
		yearday -= daytab[leap][*pmonth];
	*pday = yearday;
}
