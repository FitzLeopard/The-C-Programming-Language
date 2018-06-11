/*
 *	Date: 2018-06-11
 *	Exercise 4-1 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAXLINE 1000

/* atof: convert string s to a double-precision float-point number
 * potential scientific notation allowed						*/
double atof(char s[]);
int Getline(char s[], int max);

int main()
{
	char line[MAXLINE];
	double sum = 0.0;

	while (Getline(line, MAXLINE) > 0) {
		sum += atof(line);
		printf("%g\n", sum);
	}

	return 0;
}

/* atof: convert string s to a double-precision float-point number
 * potential scientific notation allowed						*/
double atof(char s[])
{
	double val, power, sign = 1.0;
	int i = 0;

	while (isspace(s[i])) {
		++i;
	}
	if (s[i] == '-') {
		sign = -1.0;
	}
	if (s[i] == '-' || s[i] == '+') {
		++i;
	}
	while (isdigit(s[i])) {
		val = val * 10 + s[i++] - '0';
	}
	if (s[i] == '.') {
		++i;
	}
	for (power = 1.0; isdigit(s[i]); ++i) {
		val = val * 10.0 + s[i] - '0';
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		++i;
		power *= pow(10, -atof(s + i));
	}
	
	return val * sign / power;
}

int Getline(char s[], int max)
{
	int c, i = 0;

	while (max-- && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';

	return i;
}
