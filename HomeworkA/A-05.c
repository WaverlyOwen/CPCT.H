#include <stdio.h>

char calendar[12][28] = {
    "Sun Mon Tue Wed Thu Fri Sat",
    "",
    "                   ",
    "",
    "                   ",
    "",
    "                   "
};

int zeller(int year, int month) {
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }
    int d = 1;
    int K = year % 100;
    int J = year / 100;
    int h = (d + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;
    int weekday = (h + 6) % 7;
    return weekday;
}

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int get_days_in_month(int year, int month) {
    int days;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            if (is_leap_year(year)) {
                days = 29;
            } else {
                days = 28;
            }
            break;
        default:
            days = 0;
            break;
    }
    return days;
}

void horizontal(int a,int b) {
    for(int i = 0; i < 4; ++i) {
        calendar[2 * a][8 * b + i - 1] = '#';
    }
}

void vertical(int a,int b) {
    switch (b) {
        case 1:
            b = 7;
            break;
        case 2:
            b = 10;
            break;
        case 3:
            b = 15;
            break;
        case 4:
            b = 18;
            break;
    }
    for(int i = 0; i < 3; ++i) {
        calendar[2 * a + i][b] = '#';
    }
}

void left_zero() {
    vertical(1, 1);
    vertical(2, 1);
    vertical(1, 2);
    vertical(2, 2);
    horizontal(1, 1);
    horizontal(3, 1);
}

void left_one() {
    vertical(1, 2);
    vertical(2, 2);
}

void generate(int year, int month) {
    int weekday = zeller(year, month);
    int days = get_days_in_month(year, month);
    int day = 0;
    for(int i = 0; i <= 5; ++i){
        for(int k = 1;k <= 7; ++k) {
            day = i * 7 + k - weekday;
            calendar[2 * i + 1][4 * k - 1] = ' ';
            calendar[2 * i + 1][4 * k - 2] = ' ';
            if(day <= 0) {
                calendar[2 * i + 1][4 * k - 3] = ' ';
                calendar[2 * i + 1][4 * k - 4] = ' ';
                continue;
            }
            else if (day > days) {
                if(i > 1) {
                    calendar[2 * i + 1][4 * k - 5] = 0;
                    calendar[2 * i + 1][4 * k - 6] = 0;
                }
                break;
            }
            else {
                if (day / 10) calendar[2 * i + 1][4 * k - 4] = '0' + day / 10;
                else calendar[2 * i + 1][4 * k - 4] = ' ';
                calendar[2 * i + 1][4 * k - 3] = '0' + day % 10;
            }
        }
        calendar[2 * i + 1][27] = 0;
        calendar[2 * i + 1][26] = 0;
    }
    if (month < 10) left_zero();
    else left_one();
    switch (month % 10) {
        case 0:
            vertical(1, 3);
            vertical(2, 3);
            vertical(1, 4);
            vertical(2, 4);
            horizontal(1, 2);
            horizontal(3, 2);
            break;
        case 1: 
            vertical(1, 4);
            vertical(2, 4);
            break;
        case 2: 
            vertical(2, 3);
            vertical(1, 4);
            horizontal(1, 2);
            horizontal(2, 2);
            horizontal(3, 2);
            break;
        case 3: 
            vertical(1, 4);
            vertical(2, 4);
            horizontal(1, 2);
            horizontal(2, 2);
            horizontal(3, 2);
            break;
        case 4: 
            vertical(1, 4);
            vertical(2, 4);
            vertical(1, 3);
            horizontal(2, 2);
            break;
        case 5: 
            vertical(1, 3);
            vertical(2, 4);
            horizontal(1, 2);
            horizontal(2, 2);
            horizontal(3, 2);
            break;
        case 6: 
            vertical(1, 3);
            vertical(2, 3);
            vertical(2, 4);
            horizontal(1, 2);
            horizontal(2, 2);
            horizontal(3, 2);
            break;
        case 7: 
            vertical(1, 4);
            vertical(2, 4);
            horizontal(1, 2);
            break;
        case 8: 
            vertical(1, 3);
            vertical(2, 3);
            vertical(1, 4);
            vertical(2, 4);
            horizontal(1, 2);
            horizontal(2, 2);
            horizontal(3, 2);
            break;
        case 9: 
            vertical(1, 3);
            vertical(1, 4);
            vertical(2, 4);
            horizontal(1, 2);
            horizontal(2, 2);
            horizontal(3, 2);
            break;
        default:
            break;
    }

}

void out() {
    for (int i = 0; i < 12; i++) {
        printf("%s\n", calendar[i]);
    }
}

int main() {
    int year = 0;
    int month = 0;
    scanf("%d %d", &year, &month);
    generate(year, month);
    out();
    return 0;
}