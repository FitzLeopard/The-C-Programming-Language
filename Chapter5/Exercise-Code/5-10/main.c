/*
 *	Date: 2018-06-20
 *	Exercise 5-10 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>
#include"calc.h"

#define MAXARG 20

double pop(void);
void push(double);
int getop(char *s, char *op);

int main(int argc, char *argv[])
{
	double op2;
	int type;
	char s[MAXARG];

	while (--argc > 0) {
		type = getop(s, *++argv);
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
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
			default:
				putchar(type);
				printf("Error: unknown operator or operand\n");
		}
	}
	printf("%6.4f\n", pop());

	return 0;
}
