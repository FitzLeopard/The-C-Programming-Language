/*
 * 	Date: 2018-05-29
 *	Exercise 1-5 of K&R
 *	By Rivers
*/

#include<stdio.h>

int main()
{
	int fahr;

	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return 0;
}
