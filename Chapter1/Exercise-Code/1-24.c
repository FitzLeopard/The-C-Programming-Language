/*
 *  Date: 2018-06-28
 *  Exercise 1-24 of K&R
 *  By Rivers
*/

#include<stdio.h>

#define MAX 1000

struct _stack {
    int stack[MAX];
    int stackp;
};

typedef struct _stack * Stack;

void init(Stack);
void pop(Stack);
void push(Stack, int);
int top(Stack);
int isempty(Stack);
char convert(char);
int StrLit(char *, int, int);
int Getline(char *, int);

/* check a C program for rudimental syntax error,
   including parentheses, brackets, braces, quotes, both single and double
   Use the program in 1-23 to remove all the comments in it */
int main()
{
    int i, len, nline = 0;
	char line[MAX];
	char c;
    struct _stack s;

    freopen("text", "r", stdin);
    init(&s);
    while ((len = Getline(line, MAX)) > 0) {
		++nline;
		for (i = 0; i < len; ++i) {
			c = convert(line[i]);
			if (c < -3) {		// right parentheses, brackets, braces
				if (isempty(&s) || top(&s) + c != -7) {
        	        printf("Error detected\n");
					printf("%3d:%s", nline, line);
					return 0;
				}
				pop(&s);
			}
   		    else if (c < 0) {    // left parentheses, brackets, braces
           	    push(&s, c);
        	}
        	else if (c == '\'' || c == '"') {// string literal
        	    if ((i = StrLit(line, c, i)) == 0) {
        	        printf("Error detected\n");
					printf("%3d:%s", nline, line);
        	        return 0;
        	    }
        	}
		}
    }
	printf("No Error detected\n");

    return 0;
}

/* init: initialize stack s to empty */
void init(Stack s)
{
    s->stackp = 0;
}

/* pop: remove the top element of stack s */
void pop(Stack s)
{
    --s->stackp;
}

/* push: add one more element to the top of stack s */
void push(Stack s, int i)
{
    s->stack[s->stackp++] = i;
}

/* top: return the top element of stack s */
int top(Stack s)
{
    return s->stack[s->stackp - 1];
}

/* isempty: test whether stack s is empty */
int isempty(Stack s)
{
    return s->stackp == 0;
}

/* convert: convert parentheses, brackets, braces into negative numbers
   which match	 													  */
char convert(char c)
{
    switch (c) {
        case '(':
            return -1;
        case '[':
            return -2;
        case '{':
            return -3;
        case '}':
            return -4;
        case ']':
            return -5;
        case ')':
            return -6;
        default:
            return c;
    }
}

/* StrLit: omit the string literal and char literal in program
   return the next index if no error detected;
   return 0 o.w.											  */
int StrLit(char *line, int c, int i)
{
	for (++i; line[i] != '\0' && line[i] != c; ++i) {
		if (line[i] == '\\') {
			++i;
		}
	}
	if (line[i] == '\0') {
		return 0;
	}
	return i;
}

/* Getline: get one line of char
   '\n' included
   return the length			*/
int Getline(char * s, int lim)
{
    int i, c;

    i = 0;
    while (i < lim - 1) {
        c = getchar();
        if (c == EOF) {
            break;
        }
        else if (c == '\n') {
            break;
        }
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}