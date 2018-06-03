/*
 *	Date: 2018-06-03
 *	Exercise 2-2 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000

/* write an equivalent loop without using && or || */
int Getline(char s[], int lim);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = Getline(line, MAXLINE)) > 0) {
		printf("%s%15s%d\n", line, "length: ", len);
	}

	return 0;
}

int Getline(char s[], int lim)
{
	int flag = 1;
	int i = 0, c = 0;

	for (i = 0; flag == 1; ++i) {
		if (i < lim - 1) {
			if ((c = getchar()) != '\n') {
				if (c != EOF) {
					;
				}
				else {
					flag = 0;
				}
			}
			else {
				flag = 0;
			}
		}
		else {
			flag = 0;
		}
		if (flag == 1) {
			s[i] = c;
		}
	}
	--i;			// This decrement is so important.

	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
