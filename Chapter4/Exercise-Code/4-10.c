/*
 *	Date: 2018-06-11
 *	Exercise 4-10 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>		/* for atof() */
#include<math.h>

#define MAXOP 100		/* maximum number of operator or operand */
#define NUMBER '0'		/* signal that a number was found */
#define MAXLEN 1000

int getop(char []);
void push(double);
double pop(void);
int Getline(char line[], int maxlen);

char line[MAXLEN];

/* reverse Polish Calculator */
int main()
{
	int type, mod1, mod2;
	double op2, mod1f, mod2f;
	char s[MAXOP];

	Getline(line, MAXLEN);
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
			case '%':
				mod2 = mod2f = pop();
				mod1 = mod1f = pop();
				if (fabs(mod2 - mod2f) <= 1e-6 && fabs(mod1 - mod1f) <= 1e-6) {
					push(mod1 % mod2);
				}
				else {
					printf("Error: %% can only be applied to integers.\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				Getline(line, MAXLEN);
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

int Getline(char line[], int maxlen);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int c, cnext, j = 0;
	static int i = 0;

	while ((s[0] = c = line[i]) == ' ' || c == '\t')
		++i;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		if (c != '-' && c != '+') {
			if (c == '\n') {
				i = 0;
			}
			else {
				++i;
			}
			return c;
		}
		cnext = line[++i]; 
		if (isdigit(cnext)) {	
			s[++j] = c = cnext;		/* a number with sign */
		}
		else {	/* not a number */
			return c;
		}
	}
	if (isdigit(c)) {		/* collect integer part */
		while (isdigit(s[++j] = c = line[++i]))
			;
	}
	if (c == '.') {			/* collect fraction part */
		while (isdigit(s[++j] = c = line[++i]))
			;
	}
	s[j] = '\0';

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
