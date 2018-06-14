/*
 *	Date: 2018-06-12
 *	Page 82 of K&R
 *	By Rivers
*/

#define MAXOP 100		/* maximum number of operator or operand */
#define NUMBER '0'		/* signal that a number was found */
#define NAME 'n'
#define VAR 'v'

int getop(char []);
void push(double);
double pop(void);
double top(void);
void clear(void);
void swap(void);
void showAll(void);

