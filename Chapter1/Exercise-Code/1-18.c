/*
 *	Date: 2018-05-31
 *	Exercise 1-18 of K&R
 *	By Rivers
*/

#include<stdio.h>
#define MAXLINE 1001		/* no-need-to-print input line size + 1 */

int Getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Remove trailing blanks and tabs from each line of input, 
 * and to delete entirely blank lines.					  */

/* Since it is impossible to handle the problem without storing
 * the whole line, this program is designed to handle input of 
 * whose lines the length is less than or equal to MAXLINE - 1 */

int main()
{
	int i, len;			/* i is a loop variant
						 * len for the current input line length */
	char line[MAXLINE];	/* current input line */

	while ((len = Getline(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
			// overflow detected
			printf("Overflow detected.\n");
			return -1;
		}
		i = len - 2;
		while (line[i] == ' ' || line[i] == '\t') {
			line[i] = '\n';
			line[i + 1] = '\0';
			--i;
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
