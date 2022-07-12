#include <stdio.h>

int main() {
    int primes[50] = {0};
    int primeIndex = 2; // Index of primes array which is occupied

    _Bool isPrime;

    // hardcode prime numbers
    primes[0] = 2;
    primes[1] = 3;

    for(int p = 5; p <= 100; p += 2) {
        isPrime = 1;

        for (int i = 1; p / primes[i] >= primes[i]; ++i)
            if (p % primes[i] == 0)
                isPrime = 0;

        if (isPrime) {
            primes[primeIndex] = p;
            ++primeIndex;
        }
    }

    for (int i = 0;  i < primeIndex;  ++i)
         printf ("%i  ", primes[i]);

    printf("\n");
    return 0;
}
