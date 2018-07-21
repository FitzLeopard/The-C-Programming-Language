/*
 * Date: 2018-07-21
 * Exercise 7-7 of K&R
 * By Rivers
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000

void findPattern(char *pattern, FILE *ifp, char *fileName, int, int);

int main(int argc, char *argv[])
{
	char ** fileP = NULL, **argvBU = argv;
	char *pattern;
	int except = 0, caseSense = 1, argcBU = argc;

	if (argc == 1) {
		fprintf(stderr, "Usage: %s <pattern> [-xc] [-f <file1> <file2> ...]\n", 
				argv[0]);
		return 1;
	}

	pattern = argv[1];
	while (--argcBU > 0) {
		if (**++argvBU == '-') {
			char *cp = *argvBU;
			while (*cp) {
				switch (*cp) {
					case 'x':
						except = 1;
						break;
					case 'c':
						caseSense = 0;
						break;
					case 'f':
						fileP = argvBU + 1;
						break;
				}
				++cp;
			}
		}
	}
	if (fileP == NULL) {
		findPattern(pattern, stdin, "stdin", caseSense, except);
	}
	else {
		FILE *fp;
		while (fileP - argv < argc && (*fileP)[0] != '-') {
			fp = fopen(*fileP, "r");
			if (fp == NULL) {
				fprintf(stderr, "%s: Cannot open %s\n", argv[0], *fileP);
				return 2;
			}
			findPattern(pattern, fp, *fileP, caseSense, except);
			fclose(fp);
			++fileP;
		}
	}

	return 0;
}

/* findPattern: find pattern in ifp and print them */
void findPattern(char *pattern, FILE *ifp, char *fileName, int caseSense, int except)
{
	int nline = 0, found = 0;
	char line[MAXLINE], lineBU[MAXLINE], *tmp;

	// not case sensitive, all converted to lower case
	if (!caseSense) {
		tmp = pattern;
		while (*tmp) {
			*tmp = tolower(*tmp);
			++tmp;
		}
	}
	printf("-----------------\n");
	printf("%s:\n", fileName);
	while (fgets(line, MAXLINE, ifp) != NULL) {
		++nline;
		strcpy(lineBU, line);

		// not case sensitive, all converted to lower case
		if (!caseSense) {
			tmp = lineBU;
			while (*tmp) {
				*tmp = tolower(*tmp);
				++tmp;
			}
		}

		char *mark = strstr(lineBU, pattern);
		if ((except) ? !mark : mark) {
			found = 1;
			printf("Line %d:\n", nline);
			printf("%s", line);
		}
	}
	if (!found) {
		printf("No pattern is %s found.\n", except ? "not" : "");
	}
	printf("-----------------\n");
}
