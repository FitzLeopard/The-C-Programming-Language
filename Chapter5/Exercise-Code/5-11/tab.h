/*
 *	Date: 2018-06-11
 *	Exercise 5-11 of K&R
 *	By Rivers
*/

#define MAXLINE 1000
#define YES 	1
#define NO 		0
#define TABSTOP 4

void tabset(int argc, char *argv[], char tab[]);
void entab(char tab[]);
void detab(char tab[]);
int istabstop(char tab[], int pos);
