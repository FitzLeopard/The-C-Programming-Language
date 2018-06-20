/*
 *	Date: 2018-06-19
 *	Page 117 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 1000

int Getline(char *line, int max);

int main(int argc, char *argv[])
{
	int except = 0, number = 0, c, found;

	while (--argc > 0 && (*++argv)[0] == '-') {
		while (c = *(++argv[0])) {
			switch (c) {
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf("find: illegal option\n");
					argc = 0;
					found = -1;
					break;
			}
		}
	}

	char line[MAXLINE];
	int nline = 0;
	if (argc != 1) {
		printf("Usage: find -x -n pattern\n");
	}
	else {
		while (Getline(line, MAXLINE)) {
			++nline;
			if (!!strstr(line, *argv) ^ except) {
				++found;
				if (number) {
					printf("%3d:", nline);
				}
				printf("%s", line);
			}
		}
	}

	return found;
}

int Getline(char *line, int max)
{
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';

	return i;
}


