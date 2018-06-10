/*
 *	Date: 2018-06-10
 *	Page 69 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000		/* maximum input line length */

int Getline(char s[], int max);
int strindex(char s[], char t[]);

char pattern[] = "ould";	/* pattern to search for */

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int count = 0;

	while (Getline(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			++count;
		}
	}

	return count;
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

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
			;
		if (k > 0 && t[k] == '\0') {
			return i;
		}
	}
	return -1;
}
