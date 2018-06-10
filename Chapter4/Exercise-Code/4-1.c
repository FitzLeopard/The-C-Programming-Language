/*
 *	Date: 2018-06-10
 *	Exercise 4-1 of K&R	
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000		/* maximum input line length */

int Getline(char s[], int max);
/* strrindex: find the rightmost occurence of t in s */
int strrindex(char s[], char t[]);

/* test strrindex: find the rightmost occurence of t in s */
int main()
{
	char line[MAXLINE], pattern[MAXLINE];

	Getline(line, MAXLINE);
	scanf("%s", pattern);
	printf("%d\n", strrindex(line, pattern));

	return 0;
}

int Getline(char s[], int max)
{
	int c, i = 0;

	while (max-- && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	
	return i;
}

int strrindex(char s[], char t[])
{
	int i, j, k, index = -1;

	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
			;
		if (k > 0 && t[k] == '\0') {
			index = i;
		}
	}
	return index;
}
