/*
 *	Data: 2018-05-29
 * 	Exercise 1-3 of K&R
 * 	By Rivers
*/

#include<stdio.h>

int main()
{
	int lower, upper, step;
	float fahr, celcius;

	// Print a heading for the table
	printf("%15s %10s\n", "Fahrenheit", "Celcius");
	printf("%15s %10s\n", "----------", "-------");

	// Print the body of the table
	lower = 0;
	upper = 200;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celcius = (5.0 / 9.0) * (fahr - 32);
		printf("%15.0f %10.1f\n", fahr, celcius);
		fahr += step;
	}

	return 0;
}
