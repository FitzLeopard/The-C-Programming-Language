/*
 *	Date: 2018-06-14
 *	Exercise 4-13 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<string.h>

#define MAX 1000

void reverse(char s[], int start, int end);

int main()
{
	char s[MAX];

	fgets(s, MAX, stdin);
	reverse(s, 0, strlen(s) - 1);
	printf("%s", s);

	return 0;
}

/* reverse: reverse the s[start]..s[end] */
void reverse(char s[], int start, int end)
{
	if (start < end) {
		char tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;

		reverse(s, start + 1, end - 1);
	}
}
