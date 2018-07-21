/*
 * Date: 2018-07-21
 * Page 163 of K&R2
 * By Rivers
*/

#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

/* cat: concatenate files, version 2 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *progName = argv[0];

	if (argc == 1) {
		filecopy(stdin, stdout);
	}
	else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				fprintf(stderr, "%s: cannot open %s\n", progName, *argv);
				exit(1);
			}
			else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	if (ferror(stdout)) {
		fprintf(stderr, "%s: error writing stdout\n", progName);
		exit(2);
	}

	exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = fgetc(ifp)) != EOF) {
		fputc(c, ofp);
	}
}
