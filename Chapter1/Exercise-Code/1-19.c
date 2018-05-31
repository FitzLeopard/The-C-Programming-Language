/*
 *	Date: 2018-05-31
 *	Exercise 1-19 of K&R
 *	By Rivers
*/

#include<stdio.h>
#define MAXLINE 1001		/* max size of input line */ 

int Getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

/* Reverse the character string.
 * Since it is impossible to reverse the string without storing
 * the whole string. I will assume that the length of a line in
 * the input is at most MAXLINE - 1.						   */

int main()
{
	char line[MAXLINE];
	int len;

	while ((len = Getline(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
			// overflow detected
			printf("Overflow detected.\n");
			return -1;
		}
		reverse(line);
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

/* reverse: reverse the whole string */
void reverse(char s[])
{
	int len, i, tmp;
	char * ss;

	ss = s;
	len = 0;
	while (*ss) {
		++len;
		++ss;
	}
	for (i = len - 2; i > (len - 2) / 2; --i) {
		tmp = s[i];
		s[i] = s[len - 2 - i];
		s[len - 2 - i] = tmp;
	}
}
