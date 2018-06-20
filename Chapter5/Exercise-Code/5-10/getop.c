/*
 *	Date: 2018-06-20
 *	Exercise 5-10 of K&R
 *	By Rivers
*/

#include<ctype.h>
#include"calc.h"

/* getop: get operand or operator from string op
   store operand in string s					*/
int getop(char *s, char *op)
{
	char *sp = s;

	while (isspace(*op)) {
		++op;
	}
	*sp++ = *op++;
	*sp = '\0';
	if (!isdigit(*s) && *s != '-' && *s != '+') {
		return *s;
	}
	while (isdigit(*op)) {		/* get the integer part */
		*sp++ = *op++;
	}
	if (*op == '.') {
		*sp++ = *op++;
	}
	while (isdigit(*op)) {		/* get the fraction part */
		*sp++ = *op++;
	}
	*sp = '\0';
	return (sp - s == 1 && !isdigit(*s)) ? *s : NUMBER;
}
