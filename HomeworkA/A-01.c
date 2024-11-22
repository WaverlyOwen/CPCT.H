#include <stdio.h>
#include <math.h>

typedef long long ll;

void exchange(ll* a,ll* b){
    if(*a > *b) {
        ll temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    
    while (n--) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a <= 0 || b <= 0 || c <= 0) {
            printf("error\n");
            continue;
        }

        // a <= b <= c
        exchange(&a, &b);
        exchange(&b, &c);
        exchange(&a, &b);
        
        // IsTriangle
        if (a <= c - b) {
            printf("error\n");
            continue;
        }

        // IsDengbian
        if (a == b && c == b) {
            printf("dengbian\n");
            continue;
        }

        // IsDengyao
        if (a == b || c == b) {
            printf("dengyao\n");
            continue;
        }

        // IsRight
        double d = (a * 1.0 / c) * (a * 1.0 / c) + (b * 1.0 / c) * (b * 1.0 / c);
        int is_right = (fabs(d - 1.0) < 10e-16);

        if (is_right) {
            printf("zhijao\n");
            continue;
        }


        printf("putong\n");
    }

    return 0;
}