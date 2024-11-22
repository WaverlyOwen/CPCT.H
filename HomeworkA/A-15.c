#include <stdio.h>

#define MAX_LENGTH 10086

int my_strlen(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int isPunctuation(char c) {
    return c == '.' || c == ',' || c == '?' || c == '!';
}

int main() {
    char words[MAX_LENGTH][MAX_LENGTH];
    char punctuations[MAX_LENGTH];
    int is_punctuations[MAX_LENGTH] = {0};
    int wordCount = 0, puncCount = 0;
    
    while (scanf("%s", words[wordCount]) != EOF) {
        int len = my_strlen(words[wordCount]);
        if (len > 0 && isPunctuation(words[wordCount][len - 1])) {
            punctuations[puncCount++] = words[wordCount][len - 1];
            words[wordCount][len - 1] = '\0';
            is_punctuations[wordCount] = 1;
        }

        wordCount++;
    }
    puncCount = 0;
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s", words[i]);

        if (is_punctuations[i - 1] || (i == 0 && is_punctuations[wordCount - 1])) {
            printf("%c", punctuations[puncCount++]);
        }

        if (i > 0) {
            printf(" ");
        }
    }

    printf("\n");
    return 0;
}