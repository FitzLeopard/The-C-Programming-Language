/*
 *	Date: 2018-06-12
 *	Page 82 of K&R
 *	By Rivers */

#include<stdio.h>
#include"calc.h"
#include<ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i = 0, cnext;
	static int c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		if (c != '-' && c != '+') {
			while (islower(c)) {
				s[++i] = c = getch();
			}
			if (i > 1) {	/* func name */
				s[i] = '\0';
				return NAME;
			}
			if (s[0] >= 'A' && s[0] <= 'Z') {		/* variable */
				return VAR;
			}
			else {		/* not a number */
				return s[0];
			}
		}
		cnext = getch();
		if (isdigit(cnext)) {
			s[++i] = c = cnext;		/* a number with sign */
		}
		else {	/* not a number */
			if (cnext != EOF) {
				ungetch(cnext);
			}
			return c;
		}
	}
	if (isdigit(c)) {		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.') {			/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	}
	s[i] = '\0';

	return NUMBER;
}
