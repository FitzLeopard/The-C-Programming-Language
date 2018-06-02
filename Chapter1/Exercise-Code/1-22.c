/*
 *	Date: 2018-06-02
 *	Exercise 1-22 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<ctype.h>		// for isalpha()

#define LINELEN 40

int Getline(char s[], int lim);
void copy(char to[], char from[]);

/* Fold the long input lines into two or more shorter lines
 * after the first non-blank character that occur before the
 * LINELEN-th column of input.
 * I will use the program from Exercise 1-18 and 1-9 to do
 * preprocessing. As a result, the input of this program shall
 * have the following property:
 * - no consecutive blanks
 * - no trailing blanks or tabs								*/

int main()
{
	char line[LINELEN];
	char nextLine[LINELEN];			/* next line 
									 * (for intelligent processing) */
	int len, nextLen;

	while ((len = Getline(line, LINELEN)) > 0) {
		while (len == LINELEN - 1 && line[LINELEN - 2] != '\n') {		// overflow(long line)
			nextLen = Getline(nextLine, LINELEN);
			if (isalpha(line[LINELEN - 2]) && isalpha(nextLine[0])) {		// long word
				printf("%s-\n", line);
			}
			else {
				printf("%s\n", line);
			}
			copy(line, nextLine);
			len = nextLen;
		}
		printf("%s", line);
	}

	return 0;
}

/* Getline: read a line into s, return length */
int Getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough*/
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
