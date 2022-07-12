#include <stdio.h>

int main() {

    // Display:
    printf("int\t\t:\t%zd\n", sizeof(int));
    printf("short\t\t:\t%zd\n", sizeof(short));
    printf("char\t\t:\t%zd\n", sizeof(char));
    printf("long\t\t:\t%zd\n", sizeof(long));
    printf("long long\t:\t%zd\n", sizeof(long long));
    printf("double\t\t:\t%zd\n", sizeof(double));
    printf("long double\t:\t%zd\n", sizeof(long double));

    return 0;
}