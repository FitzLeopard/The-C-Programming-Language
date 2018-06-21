/*
 *	Date: 2018-05-31
 *	Page 29 of K&R
 *	By Rivers
*/

#include<stdio.h>

int Getline(char line[], int maxline);

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
