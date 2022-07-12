#include <stdio.h>

int main() {
#if __STDC_VERSION__ >= 201710L
    printf("Version used for this program: C18\n");
#elif __STDC_VERSION__ >= 201112L
    printf("Version used fot htis program: C11\n");
#elif __STDC_VERSION__ >= 199901L
    printf("Version used for this program: C99\n");
#else
    printf("Version used for this program: C89/C90\n");
#endif
    return 0;
}