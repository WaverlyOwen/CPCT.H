#include <stdio.h>
#include <math.h>

void print(double start, double end) {
    double step = 0.2;
    for (double i = start; 0.1 < fabs(end + step - i); i += step) {
        printf("%.1f", i);
        if (1e-1 < fabs(end - i)) {
            printf(" ");
        }
    }
}

int main() {
    double GPA = 0;
    scanf("%lf", &GPA);
    int sum = GPA * 10;
    if (sum == 50) {
        printf("100.0");
        return 0;
    }
    else if (sum == 0) {
        print(0.0, 59.0);
        return 0;
    }
    if (sum > 45) {
        print(50.0 + sum, 100.0 - 0.2 * (50 - sum));
        return 0;
    }
    double start = floor(sum / 10.0 + 1) * 10.0 +sum;
    double end = 0;
    if (sum >= 37) end = 54.0 + sum;
    else if (sum >= 28) end = 55.0 + sum;
    else if (sum >= 19) end = 56.0 + sum;
    else if (sum >= 10) end = 57.0 + sum;
    else end = 58.0 + sum;
    if (sum == 37 || sum == 28 || sum == 19 || sum == 10) end += 0.2;
    print(start, end);
    return 0;
}