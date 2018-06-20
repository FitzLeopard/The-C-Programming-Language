/*
 *	Date: 2018-06-20
 *	Exercise 5-10 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXVAL 1000

static double val[MAXVAL];		/* stack */
static int valp;		/* next free position of stack */

double pop(void)
{
	if (valp == 0) {
		printf("Error: Stack is empty. Unable to pop.\n");
	}
	else {
		return val[--valp];
	}
}

void push(double t)
{
	if (valp == MAXVAL) {
		printf("Error: Stack is full. Unable to push.\n");
	}
	else {
		val[valp++] = t;
	}
}
