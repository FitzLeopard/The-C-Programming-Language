/*
 *	Date: 2018-06-15
 *	Page 101 of K&R
 *	By Rivers
*/

#define ALLOCSIZE 10000		/* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else {
		return 0;
	}
}

void free(char * p)
{
	if (p < allocbuf + ALLOCSIZE && p >= allocbuf) {
		allocp = p;
	}
}
