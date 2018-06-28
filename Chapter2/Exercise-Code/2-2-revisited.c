#include<stdio.h>

#define MAX 100

int Getline(char *, int);

int main()
{
    char line[MAX];
    int len;
    
    while ((len = Getline(line, MAX)) > 0) {
        printf("length: %d\n%s", len, line);
    }

    return 0;
}

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