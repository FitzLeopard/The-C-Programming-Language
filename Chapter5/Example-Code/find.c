/*
 *	Date: 2018-06-19
 *	Page 116 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 1000

int Getline(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
	char line[MAXLINE]; int found = 0;

	if (argc > 2) {
		printf("Usage: find pattern\n");
		return -1;
	}
	else {
		while (Getline(line, MAXLINE) > 0) {
			if (strstr(line, argv[1]) != NULL) {
				printf("%s", line);
				++found;
			}
		}
	}

	return found;
}

int Getline(char *line, int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';

	return i;
}
