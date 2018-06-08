/*
 *	Date: 2018-06-08
 *	Exercise 3-2 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000

/* escape: convert the invisible char in t into visible escape
 * sequence in s when copying t to s.						*/
void escape(char s[], char t[]);
/* deescape: convert the visible escape sequence in t into
 * invisible char in s when copying t to s.				*/
void deescape(char s[], char t[]);

int main()
{
	char Escape[MAXLINE], Deescape[MAXLINE];
	/* Escape has visible escape sequence
	 * Deescape has invisible char 		*/

	printf("Give me a string with invisible char:\n");
	fgets(Deescape, MAXLINE, stdin);
	escape(Escape, Deescape);
	printf("Here is the string with visible escape sequence:\n");
	printf("%s\n", Escape);

	printf("Give me a string with visible escape sequence:\n");
	fgets(Escape, MAXLINE, stdin);
	deescape(Deescape, Escape);
	printf("Here is the string with invisible char:\n");
	printf("%s", Deescape);

	return 0;
}
/* escape: convert the invisible char in t into visible escape
 * sequence in s when copying t to s.						*/
void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
		case '\t':
			s[j] = '\\';
			s[j + 1] = 't';
			j += 2;
			break;
		case '\n':
			s[j] = '\\';
			s[j + 1] = 'n';
			j += 2;
			break;
		default:
			s[j] = t[i];
			++j;
		}
	}
	s[j] = '\0';
}

/* deescape: convert the visible escape sequence in t into
 * invisible char in s when copying t to s.				*/
void deescape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; ++i) {
		if (t[i] == '\\') {
			switch (t[i + 1]) {
			case 't':
				s[j++] = '\t';
				++i;
				break;
			case 'n':
				s[j++] = '\n';
				++i;
				break;
			default:
				printf("Error: invalid escape sequence---"
						"only '\\n' and '\\t' allowed\n");
			}
		}
		else {
			s[j++] = t[i];
		}
	}
	s[j] = '\0';
}
