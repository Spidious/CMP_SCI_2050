#include <stdio.h>
#include <string.h>

int main(void)
{
    char p1[4] = {"THH\0"};
    char p2[4] = {"THH\0"};

    printf("%d\n", strcmp(p1, p2));
}