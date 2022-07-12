#include <stdio.h>

int binarySearch(int inp_arr[], int x, int low, int high) {
    // repeat until the pointers low and high meet each other:
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (inp_arr[mid] == x)
            return mid;

        if (inp_arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

int main(void) {
    int sampleArray[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(sampleArray) / sizeof(sampleArray[0]);
    int x = 4;
    int result = binarySearch(sampleArray, x, 0, n - 1);

    if (result == -1) // if not found
        printf("Not found\n");
    else
        printf("Element is ound at index %d\n", result);
        
    return 0;
}