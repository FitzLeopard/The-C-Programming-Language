/*
 * Data: 2018-07-21
 * Exercise 7-6 of K&R
 * By Rivers
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* diff: compare two files and print the first line that is different */
int main(int argc, char *argv[])
{
	int nline = 0;
	char line1[MAXLINE], line2[MAXLINE];
	char *l1, *l2;
	FILE *fp1, *fp2;

	if (argc != 3) {
		fprintf(stderr, "%s: Usage: diff <file1> <file2>\n", argv[0]);
	}
	else {
		fp1 = fopen(argv[1], "r");
		if (fp1 == NULL) {
			fprintf(stderr, "%s: Cannot open %s\n", argv[0], argv[1]);
			return 1;
		}
		fp2 = fopen(argv[2], "r");
		if (fp2 == NULL) {
			fprintf(stderr, "%s: Cannot open %s\n", argv[0], argv[2]);
			return 1;
		}
		while ((l1 = fgets(line1, MAXLINE, fp1)) != NULL & 
			(l2 = fgets(line2, MAXLINE, fp2)) != NULL) {
			++nline;
			if (strcmp(line1, line2) != 0) {
				printf("Line %d:\n", nline);
				printf("%s:\n%s", argv[1], line1);
				printf("------------\n");
				printf("%s:\n%s", argv[2], line2);
				return 0;
			}	
		}
	}

	if (l1 == l2) {
		printf("These two files are identical.\n");
	}
	else {
		printf("One of them is a sub-file of the other.\n");
	}
	return 0;
}
