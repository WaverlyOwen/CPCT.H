#include <stdio.h>
#include <math.h>

int is_prime(unsigned int num) {
    for (unsigned int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    for (int i = 3; i <= n / 2; ++i) {
        if (is_prime(i) && is_prime(n - i)){
            printf("%u = %u + %u\n", n, i, n-i);
        }
    }
    return 0;
}