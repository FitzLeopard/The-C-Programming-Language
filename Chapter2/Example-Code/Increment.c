/*
 *	Date: 2018-06-04
 *	Page 47 and 48 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000

/* delete all c from s */
void squeeze(char s[], char c);
/* concatenate t to s */
void strcat(char s[], const char t[]);

int main()
{
	char s1[MAXLINE], s2[MAXLINE];
	char c;

	printf("Give me a string:\n");
	fgets(s1, MAXLINE, stdin);
	printf("You want to delete which character?\n");
	c = getchar();

	squeeze(s1, c);
	printf("Now your string is:\n");
	printf("%s\n", s1);

	printf("Give me another string to concatenate:\n");
	scanf("%s", s2);
	strcat(s1, s2);
	printf("%s%s", "Now your string is:\n", s1);

	return 0;
}

/* delete all c from s */
void squeeze(char s[], char c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; ++i) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

/* concatenate t to s */
void strcat(char s[], const char t[])
{
	int i = 0, j = 0;

	while (s[i] != '\0') {
		++i;
	}
	while ((s[i++] = t[j++]) != '\0')
		;
	s[i] = '\0';
}
