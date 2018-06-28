#include<stdio.h>

int main()
{
    printf("The maximum of int: %d\n", (~(unsigned int)0) >> 1);
    printf("The minimum of int: %d\n", (int)~((~(unsigned int)0) >> 1));
    printf("The maximum of char: %d\n", (((unsigned char)~0) >> 1));
    printf("The minimum of char: %d\n", (short)~(((unsigned char)~0) >> 1));
    printf("The maximum of short: %d\n", ((unsigned short)~0) >> 1);
    printf("The minimum of short: %d\n", ~((~(unsigned short)0) >> 1));
    printf("The maximum of long: %ld\n",  ((unsigned long)~0) >> 1);
    printf("The minimum of long: %ld\n", (long)~((~(unsigned long)0) >> 1));

    return 0;
}