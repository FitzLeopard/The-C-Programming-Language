/*
 *	Date: 2018-06-12
 *	Page 82 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>	/* for atof() */
#include<math.h>
#include<string.h>
#include"calc.h"

/* reverse Polish Calculator */
int main()
{
	int type, mod1, mod2, var = 0;
	double op2, mod1f, mod2f, variable[26];
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
			case '=':
				if (var >= 'A' && var <= 'Z') {
					pop();
					variable[var - 'A'] = pop();
				}
				else {
					printf("Error: No variable detected\n");
				}
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
				else if (strcmp(s, "pop") == 0) {
					pop();
				}
				else {
					printf("Error: unknown name of function\n");
				}
			break;
			case VAR:
				push(variable[s[0] - 'A']);
				var = s[0];
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
			case '\n':
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}
