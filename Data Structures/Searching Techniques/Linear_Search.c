#include <stdio.h>

int linearSearch(int inp_arr[], int n, int x) {
    // Going through array sequencially
    for (int i = 0; i < n; i++)
        if (inp_arr[i] == x)
            return i;
    return -1;
}

int main(void) {
    int sampleArray[] = {2, 4, 0, 1, 9};
    int x = 1; // element to find
    int n = sizeof(sampleArray) / sizeof(sampleArray[0]);

    int result = linearSearch(sampleArray, n, x);

    (result == -1) ? printf("Element not found\n") : printf("Element found at indez: %d\n", result);
    return 0;
}