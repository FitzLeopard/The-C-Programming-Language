#include<stdio.h>

char lower(char c);

int main()
{
	int c = getchar();

	printf("%c\n", lower(c));

	return 0;
}

char lower(char c)
{
	return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : (c);
}
