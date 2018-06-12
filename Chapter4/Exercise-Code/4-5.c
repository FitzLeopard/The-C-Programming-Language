/*
 *	Date: 2018-06-11
 *	Page 76, 77, 78 of K&R
 * 	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>		/* for atof() */
#include<math.h>
#include<string.h>

#define MAXOP 100		/* maximum number of operator or operand */
#define NUMBER '0'		/* signal that a number was found */
#define NAME 'n'

int getop(char []);
void push(double);
double pop(void);
double top(void);
void clear(void);
void swap(void);
void showAll(void);

/* reverse Polish Calculator */
int main()
{
	int type, mod1, mod2;
	double op2, mod1f, mod2f;
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
			/* 's' for swap; 'w' for watch; 'c' for clear;
			 * 'a' for show all							*/
			case 's':
				swap();
				break;
			case 'c':
				clear();
				break;
			case 'w':
				printf("%g\n", top());
				break;
			case 'a':
				showAll();
				break;
			case NAME:
				if (strcmp(s, "sin") == 0) {
					push(sin(pop()));
				}
				else if (strcmp(s, "cos") == 0) {
					push(cos(pop()));
				}
				else if (strcmp(s, "exp") == 0) {
					push(exp(pop()));
				}
				else if (strcmp(s, "pow") == 0) {
					op2 = pop();
					push(pow(pop(), op2));
				}
				else {
					printf("Error: unknown name of function\n");
				}
			break;
			case '\n':
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

/* showAll: show all the elements in stack */
void showAll(void)
{
	int i;

	printf("There %s %d element%s in the stack.\n",
			(sp == 1) ? "is": "are",
			sp,
			(sp == 1) ? "" : "s");
	if (sp > 0) {
		for (i = 0; i < sp; ++i) {
			printf("%6.2g%c", val[i], (i % 10 == 9 || i == sp - 1) ? '\n':' ');
		}
	}
}

/* top: return the top of the stack */
double top(void)
{
	if (sp > 0) {
		return val[sp - 1];
	}
	else {
		printf("stack empty\n");
	}
}

/* clear: clear the stack */
void clear(void)
{
	sp = 0;
	printf("stack clear\n");
}

/* swap: swap two elements on the top of the stack */
void swap(void)
{
	if (sp < 2) {
		printf("Error: There are less than two elements. Unable to swap.\n");
	}
	else {
		double tmp1 = top();
		double tmp2 = top();
		push(tmp1);
		push(tmp2);
	}
}

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
		if (c != '-' && c != '+') {
			while (islower(c)) {
				s[++i] = c = getch();
			}
			if (i > 1) {
				if (c != EOF) {
					ungetch(c);
				}
				s[i] = '\0';
				return NAME;
			}
			return s[0];
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

