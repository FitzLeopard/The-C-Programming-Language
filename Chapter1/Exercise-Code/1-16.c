/*
 *	Date: 2018-05-31
 *	Exercise 1-16 of K&R
 *	By Rivers
*/

#include<stdio.h>
#define MAXLINE 1000		/* maximum input line size */

int Getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print the longest line, no matter how long it is.
 * Print as much as possible.						*/

/* What does 'as much as possible' mean? 
 * Let Len denote the length of the longest line.
 * If Len > MAXLINE, the first MAXLINE characters will be printed.
 * And the last (Len % MAXLINE) characters will be printed.		*/

int main()
{
	int len;			/* current line length */
	int currLen;		/* part of current line length(for too-long line) */
	int max;			/* maximum length seen so far */
	char line[MAXLINE]; 	/* current input line */
	char first[MAXLINE];	/* first MAXLINE characters 
							 * (for too-long line) */
	char longest[MAXLINE];	/* first MAXLINE characters of 
							 * longest line saved here 	*/
	char longestLast[MAXLINE]; /* last (Len % MAXLINE) characters of
								* longest line saved here.		*/

	max = 0;
	while ((len = Getline(line, MAXLINE)) > 0) {
		currLen = len;
		copy(first, line);
		while (currLen == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
			// Condition for overflow
			currLen = Getline(line, MAXLINE);
			len += currLen;
		}
		if (len > max) {
			max = len;
			copy(longest, first);
			copy(longestLast, line);
		}
	}
	if (max > MAXLINE) {
		printf("%s\n", longest);
		printf("...\n");
		printf("%s", longestLast);
	}
	else if (max > 0) {
		printf("%s", longest);
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
