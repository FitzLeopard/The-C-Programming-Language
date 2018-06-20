/*
 *	Date: 2018-06-20
 *	Exercise 5-11 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include"tab.h"

int main(int argc, char *argv[])
{
	char tab[MAXLINE + 1];

	tabset(argc, argv, tab);
	entab(tab);

	return 0;
}
