/*
 *	Date: 2018-06-10
 *	Page 71 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<ctype.h>

#define MAXLINE 1000

/* atof: convert string s to float-point value */
double atof(char s[]);
int Getline(char s[], int max);

int main()
{
	char s[MAXLINE];
	double sum = 0.0;

	while (Getline(s, MAXLINE) > 0) {
		sum += atof(s);
		printf("%g\n", sum);
	}

	return 0;
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

/* atof: convert string s to float-point value */
double atof(char s[])
{
	int i = 0;
	double val = 0.0, power = 1.0, sign = 1.0;

	while (isspace(s[i])) {
		++i;
	}
	if (s[i] == '-') {
		sign = -1;
		++i;
	}
	while (isdigit(s[i])) {
		val = val * 10 + s[i++] - '0';
	}
	if (s[i++] == '.') {
		while (isdigit(s[i])) {
			val = val * 10 + s[i++] - '0';
			power *= 10;
		}
	}

	return val * sign / power;
}
