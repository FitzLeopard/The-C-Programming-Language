/*
 *	Date: 2018-06-15 *	Page 97 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<ctype.h> 
#include<math.h>

#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void) /* get a (possibly pushed back) char */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push char back on input */
{
	if (bufp >= BUFSIZE) {
		printf("Error: ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+') {
		c = getch();
	}
	if (!isdigit(c) && c != EOF) {
		ungetch(c);
		return 0;	/* not a number */
	}
	else {
		for (*pn = 0; isdigit(c); c = getch()) {
			*pn = *pn * 10 + c - '0';
		}
		*pn *= sign;
		if (c != EOF) {
			ungetch(c);
		}
	}
	return c;
}

/* getfloat: get next float-point number from input to *pf */
int getfloat(double *pf)
{
	int sign, c;
	double power = 1.0;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
		ungetch(c);
		return 0;
	}
	/* get the sign of float number */
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+') {
		c = getch();
	}
	/* if it is +-letter(invalid) */
	if (!isdigit(c) && c != EOF) {
		ungetch(c);
		return 0;
	}
	/* get the integer part */
	for (*pf = 0.0; isdigit(c); c = getch()) {
		*pf = *pf * 10 + c - '0';
	}
	if (c != '.' && c != 'e' && c != 'E') {
		ungetch(c);
		return c;
	}
	/* get the fraction part */
	if (c == '.') {
		c = getch();
		for (; isdigit(c); c = getch()) {
			*pf = *pf * 10 + c - '0';
			power *= 10;
		}
	}
	/* get the exponetial part */
	if (c == 'e' || c == 'E') {
		int expo = 0;
		c = getint(&expo);
		power *= pow(10, -expo);
	}
	*pf *= sign / power;
	return c;
}

