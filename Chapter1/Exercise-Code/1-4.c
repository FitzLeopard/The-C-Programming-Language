/*
 * 	Date: 2018-05-29
 *	Exercise 1-4 of K&R
 * 	By Rivers
*/

#include<stdio.h>

int main()
{
	int lower, upper, step;
	float celcius, fahr;
	
	// Print a heading for the table
	printf("%10s %15s\n", "Celcius", "Fahrenheit");
	printf("%10s %15s\n", "-------", "----------");
	
	// Print the body of the table
	lower = 0;
	upper = 200;
	step = 20;

	celcius = lower;
	while (celcius <= upper) {
		fahr = (9.0 / 5.0) * celcius + 32;
		printf("%10.0f %15.1f\n", celcius, fahr);
		celcius += step;
	}

	return 0;
}
