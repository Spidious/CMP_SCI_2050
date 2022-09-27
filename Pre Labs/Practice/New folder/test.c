#include <stdio.h>
#include <math.h>

int main () {
    char str[80];

    sprintf(str, "Value of Pi = %f", 3.14);
    puts(str);

    vprintf("test");
    
    return(0);
}
