/*
 *	Date: 2018-06-12
 *	Page 82 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include"calc.h"


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
		double tmp1 = pop();
		double tmp2 = pop();
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

