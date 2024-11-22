#include <stdio.h>

int main() {
    int n = 0;
    unsigned long long max = 0;
    scanf("%d %llu",&n,&max);
    if(n <= 0) {
        printf("overflow");
        return 0;
    }
    unsigned long long sum = 0;
    unsigned long long factorial = 1;
    for(int i = 1; i <= n; i++) {
        if(factorial >= max/i) {
            printf("overflow");
            return 0;
        }
        factorial *= i;
        if(max - factorial < sum) {
            printf("overflow");
            return 0;
        }
        sum += factorial;
    }
    printf("%llu",sum);
    return 0;
}