/*
 *	Date: 2018-05-30
 *	Exercise 1-15 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* print Fahrenheit-Celsius table
 	for fahr = 0, 20, ..., 300 
	with function 				*/

/* Celcius: return the corresponding Celcius
 * temperature with the fahr Fahrenheit tempe-
 * rature.									*/
double Celsius(double fahr);

int main()
{
	double fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	for (fahr = lower; fahr <= upper; fahr += step) {
		printf("%3.0f %6.1f\n", fahr, Celsius(fahr));
	}

	return 0;
}

double Celsius(double fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
