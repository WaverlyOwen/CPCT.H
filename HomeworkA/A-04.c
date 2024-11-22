#include <stdio.h>

void out(const int* n,const int* i) {
    for(int k = 1;k <= *n + *i - 1; ++k) {
        if( k % 2 != (*n - *i) % 2 && k + *i > *n) printf("%d", *i);
        else printf(" ");
    }
    printf("\n");
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <=n; ++i) out(&n,&i);
    for(int i = n - 1; i >= 1; --i) out(&n,&i);
    return 0;
}