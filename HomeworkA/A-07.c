#include <stdio.h>

int a, b, c, na, nb, nc, ma, mb, mc, E;

int max(int* a,int* b) {
    if (*a > *b) return *a;
    else return *b;
}

int min(int* a,int* b) {
    if (*a < *b) return *a;
    else return *b;
}

int check(int* i, int* j ,int* k) {
    if (*i * a + *j * b + *k * c == E) {
        return 1;
    }
    if (*i * a + *j * b - *k * c == E) {
        *k = - *k;
        return 1;
    }
    if (*i * a - *j * b + *k * c == E) {
        *k = - *k;
        return 1;
    }
    if (*i * a - *j * b - *k * c == E) {
        *k = - *k;
        *j = - *j;
        return 1;
    }
    if (0 - *i * a + *j * b + *k * c == E) {
        *i = - *i;
        return 1;
    }
    if (0 - *i * a + *j * b - *k * c == E) {
        *k = - *k;
        *i = - *i;
        return 1;
    }
    if (0 - *i * a - *j * b + *k * c == E) {
        *j = - *j;
        *i = - *i;
        return 1;
    }
    return 0;
}

void print(int x) {
    if (x == 0) printf("not used 0\n");
    else if (x > 0) printf("pay %d\n", x);
    else printf("get %d\n", - x);
}

int loop(int num) {
    int k = 0;
    for (int i = 0;i <= num; ++i) {
        for (int j = 0;j <= num - i; ++j) {
            k = num - i - j;
            if(check(&i, &j, &k)){
                printf("%d\n",num);
                print(i);
                print(j);
                print(k);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &na, &nb, &nc, &ma, &mb, &mc, &E);
    int max_num = max(&na, &ma) + max(&nb, &mb) + max(&nc, &mc);
    for(int num = E / a; num <= max_num; ++num){
        if(loop(num))return 0;
    }
    printf("Wrong");
    return 0;
}