/*
 *	Date: 2018-06-02
 *	Standard solution to Exercise 1-23 of K&R
 *	By Rivers
*/

#include<stdio.h>

void RmComment(int c);
void RmBlock();
void RmLine();
void EchoQuote(int c);

int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		RmComment(c);
	}

	return 0;
}

void RmComment(int c)
{
	int d;

	if (c == '/') {
		d = getchar();
		if (d == '*') {		// block comment
			RmBlock();
		}
		else if (d == '/') {	// line comment
			RmLine();
		}
		else {
			putchar(c);
			putchar(d);
		}
	}
	else {
		if (c == '\'' || c == '"') {
			EchoQuote(c);
		}
		else {
			putchar(c);
		}
	}
}

void RmBlock()
{
	int c, clast;

	c = clast = 0;
	clast = getchar();
	c = getchar();
	while (!(clast == '*' && c == '/')) {
		clast = c;
		c = getchar();
	}
}

void RmLine()
{
	int c;

	c = 0;
	while ((c = getchar()) != '\n')
		;
	putchar(c);
}

void EchoQuote(int c)
{
	int d;

	putchar(c);
	d = 0;
	while ((d = getchar()) != c) {
		putchar(d);
		if (d == '\\') {	// escape sequence
			putchar(getchar());
		}
	}
	putchar(d);
}
