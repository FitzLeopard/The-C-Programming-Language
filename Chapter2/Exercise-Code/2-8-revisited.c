#include<stdio.h>

unsigned rightrot(unsigned x, int n);

int main()
{
    int x, n;

    scanf("%d%d", &x, &n);
    printf("%u\n", rightrot(x, n));
    
    return 0;
}

/* rightrot: right rotate n bits of x */
unsigned rightrot(unsigned x, int n)
{
    int len = (sizeof x) * 8;

    n %= len;
    for (int i = 0; i < n; ++i) {
        x = ((x & 1) << (len - 1)) | (x >> 1);
    }
    return x;
}