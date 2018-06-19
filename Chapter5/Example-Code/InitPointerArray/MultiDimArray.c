/*
 *	Date: 2018-06-19
 *	Page 111 of K&R
 *	By Rivers
*/

#include<stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int i);

int main()
{
	int year, month, day;

	printf("Give me a date. I will give you the day of the year.\n");
	scanf("%d%d%d", &year, &month, &day);
	printf("Here is the day of the year:\n%d\n",
			day_of_year(year, month, day));

	printf("Give me a day of the year. I will give you the day of the month.\n");
	scanf("%d%d", &year, &day);
	month_day(year, day, &month, &day);
	printf("Here is the day of the month:%s %d\n",
			month_name(month), day);

	return 0;
}
