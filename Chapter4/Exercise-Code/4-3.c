/*
 *	Date: 2018-06-11
 *	Page 76, 77, 78 of K&R
 * 	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>		/* for atof() */

#define MAXOP 100		/* maximum number of operator or operand */
#define NUMBER '0'		/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish Calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 == 0.0) {
					printf("Error: zero divisor\n");
				}
				else {
					push(pop() / op2);
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

#define MAXVAL 100

int sp = 0;			/* next free position in value stack */
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("Error: stack is full, cannot push %g\n", f);
	}
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("Error: stack empty, cannot pop\n");
		return 0.0;
	}
}

#include<ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i = 0, c, cnext;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		if (c == '-' || c == '+') {
			if (!isdigit(cnext = getch())) {
				if (cnext != EOF) {
					ungetch(cnext);
				}
				return c;		/* not a number */
			}
			else {				/* a number with sign */
				s[++i] = c = cnext;
			}
		}
		else {
			return c;			/* not a number */
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
	if (c != EOF) {
		ungetch(c);
	}

	return NUMBER;
}

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

