/*
 *	Date: 2018-05-31
 *	Exercise 1-17 of K&R
 *	By Rivers
*/

#include<stdio.h>
#define MAXLINE 81		/* no-need-to-print input line size + 1 */

int Getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print all lines that are longer than 80 characters.
 * No matter how long the line is.					*/

#define GREATER 1
#define LESSEQ	0

int main()
{
	int len;		/* current input line size */
	int state;
	char line[MAXLINE];

	state = LESSEQ;
	while ((len = Getline(line, MAXLINE)) > 0) {
		state = LESSEQ;
		while (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
			state = GREATER;
			printf("%s", line);
			len = Getline(line, MAXLINE);
		}
		if (state == GREATER) {
			printf("%s", line);
		}
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
