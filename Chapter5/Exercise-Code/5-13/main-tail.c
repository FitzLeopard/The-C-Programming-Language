/*
 *	Date: 2018-06-20
 *	Exercise 5-13 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1000	/* max size of the line */
#define MAXTAIL 100		/* max size of the tail */ 
int TailNum(int argc, char *argv[]);
int getTail(char *TailLine[], int tail);
void printTail(char *TailLine[], int tail, int tailp);

int main(int argc, char *argv[])
{
	int tail = 10, 	/* tail: the number of lines of the tail */
		tailp;		/* tailp: the index of the first line of the tail
					   in TailLine									*/
	char *TailLine[MAXTAIL];

	tail = TailNum(argc, argv);
	if (tail < 0) {
		return 1;
	}

	tailp = getTail(TailLine, tail);
	if (tailp < 0) {
		return 2;
	}

	printTail(TailLine, tail, tailp);

	return 0;
}

/* TailNum: return the number of the lines in the tail */
int TailNum(int argc, char *argv[])
{
	int tail = 10;

	if (argc > 2) {
		printf("Error: Too many arguments\n");
		return -1;
	}
	else if (argc == 2) {
		tail = atoi(argv[1] + 1);
		if (tail <= 0) {
			printf("Error: Illegal number of lines\n");
			return -1;
		}
		return tail;
	}
	return tail;
}


int Getline(char *line, int max);
/* getTail: get the tail and store them in TailLine[0..tail - 1]
   			return the index of the first line in TailLine 		*/
int getTail(char *TailLine[], int tail)
{
	char line[MAXLINE], *tmp;
	int len, nline = 0, tailp = -1, i;

	for (i = 0; i < MAXTAIL; ++i) {
		TailLine[i] = NULL;
	}
	while ((Getline(line, MAXLINE) > 0)) {
		++nline;
		tailp = (tailp + 1) % tail;
		if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
			printf("Error: Too long input per line\n");
			return -1;
		}
		if (nline <= tail) {
			TailLine[tailp] = (char *) malloc((len + 1) * sizeof(char));
		}
		strcpy(TailLine[tailp], line);
	}
	
	return TailLine[tailp + 1] == NULL ? 0 : tailp + 1;
}

/* printTail: print all the tail lines */
void printTail(char *TailLine[], int tail, int tailp)
{
	int i;

	for (i = 0; i < tail; ++i) {
		if (TailLine[(tailp + i) % tail] == NULL) {
			break;
		}
		printf("%s", TailLine[(tailp + i) % tail]);
	}
}

/* Getline: get a line of string, newline included
   			return the length of the line, newline included */
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
