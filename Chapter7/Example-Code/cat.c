/*
 * Date: 2018-07-21
 * Page 162 of K&R2 
 * By Rivers
*/

#include <stdio.h>

void filecopy(FILE *, FILE *);

/* cat: concatenate files, version 1 */
int main(int argc, char *argv[])
{
	FILE *fp;
	
	if (argc == 1) {
		filecopy(stdin, stdout);
	}
	else {
		while (--argc) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("Cannot open %s\n", *argv);
				return 1;
			}
			else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}

	return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while ((c = fgetc(ifp)) != EOF) {
		putc(c, ofp);
	}
}
