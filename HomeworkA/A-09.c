#include <stdio.h>
#include <stdlib.h>

int strlength(const char* str) {
    int length = 0;
    while (str[length] != '\0') ++length;
    return length;
}

int reverse(char* str, int length) {
    int i = 0;
    for (; i < length / 2; ++i) {
        if(*(str + i) != *(str + length - i - 1))break;
    }
    if (i == length / 2) return 1;
    return 0;
}

int main() {
    char *str = (char *)malloc(10087 * sizeof(char));
    scanf("%s", str);
    if (reverse(str, strlength(str))) printf("yes");
    else printf("no");
    free(str);
    return 0;
}