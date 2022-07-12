#include <stdio.h>

int gcd(int u, int v) { // Greatest Common Divisor
    int temp;

    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }
    return u;
}

float absoluteValue(float x) {
    if (x < 0)
        x = -x;

    return x;
}

float squareRoot(float x) {
    const float epsilon = .00001;
    float guess   = 1.0;
    float returnValue = 0.0;

    if (x < 0) { // check if number is a negative value
        printf ("Negative argument to squareRoot.\n");
        returnValue = -1.0;
    }
    else { 
        while  (absoluteValue(guess * guess - x) >= epsilon)
           guess = ( x / guess + guess ) / 2.0;

        returnValue = guess;
    }

    return returnValue;
}

int main() {
    // code implementations here!
    return 0;
}