#include <stdio.h>
#include <math.h>

double calculate(const int* k) {
    return 1.0 / pow(16, *k) * (4.0 / (8 * *k + 1) - 2.0 / (8 * *k + 4) - 1.0 / (8 * *k + 5) - 1.0 / (8 * *k + 6));
}

int main() {
    int N = 0;
    double pi = 0;
    double temp = 0;
    scanf("%d", &N);
    for(int k = 0;;++k) {
        temp = calculate(&k);
        if(fabs(temp * pow(10.0,N)) < pi) {
            break;
        }
        else pi += temp;
    }
    pi = floor(pi * pow(10.0, N-1))/pow(10.0, N-1);
    printf("%.*lf", N - 1, pi);
}