#include <stdio.h>

int main() {
    char card[3] = {0};
    int cards[5][2] = {0};
    while (1) {
        for(int i = 0; i < 5; ++i) {
            scanf("%2s", card);
            if(card[0] == '0' && card[1] == '\0')return 0;
            switch (card[0]) {
                case 'D':
                    cards[i][0] = 1;
                    break;
                case 'C':
                    cards[i][0] = 2;
                    break;
                case 'H':
                    cards[i][0] = 3;
                    break;
                case 'S':
                    cards[i][0] = 4;
                    break;
                default:
                    --i;
                    continue;
            }
            switch (card[1]) {
                case 'A':
                    cards[i][1] = 1;
                    break;
                case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                    cards[i][1] = card[1] - '0';
                    break;
                case 'T':
                    cards[i][1] = 10;
                    break;
                case 'J':
                    cards[i][1] = 11;
                    break;
                case 'Q':
                    cards[i][1] = 12;
                    break;
                case 'K':
                    cards[i][1] = 13;
                    break;
                default:
                    --i;
                    continue;
            }
            for(int j = 0; j < i; ++j) {
                if(cards[i][0] == cards[j][0] && cards[i][1] == cards[j][1]) {
                    i--;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            int temp[2] = {0};
            for (int j = 1; j < 5;++j) {
                if (cards[j-1][1] > cards[j][1]) {
                    temp[0] = cards[j][0];
                    temp[1] = cards[j][1];
                    cards[j][0] = cards[j-1][0];
                    cards[j][1] = cards[j-1][1];
                    cards[j-1][0] = temp[0];
                    cards[j-1][1] = temp[1];
                }
            }
            for (int j = 1; j < 5;++j) {
                if (cards[j-1][0] > cards[j][0] && cards[j-1][1] == cards[j][1]) {
                    temp[0] = cards[j][0];
                    cards[j][0] = cards[j-1][0];
                    cards[j-1][0] = temp[0];
                }
            }
        }

        int straight = (cards[1][1] == cards[0][1] + 1 && cards[2][1] == cards[1][1] + 1 && cards[3][1] == cards[2][1] + 1 && cards[4][1] == cards[3][1] + 1)
        || (cards[1][1] == cards[0][1] + 9 && cards[2][1] == cards[1][1] + 1 && cards[3][1] == cards[2][1] + 1 && cards[4][1] == cards[3][1] + 1);

        int flush = cards[0][0] == cards[1][0] && cards[0][0] == cards[2][0] && cards[0][0] == cards[3][0] && cards[0][0] == cards[4][0];

        if(flush && straight) {
            printf("straight flush\n");
            continue;
        }

        if((cards[0][1] == cards[1][1] && cards[0][1] == cards[2][1] && cards[0][1] == cards[3][1]) 
        || (cards[1][1] == cards[2][1] && cards[1][1] == cards[3][1] && cards[1][1] == cards[4][1])) {
            printf("four of a kind\n");
            continue;
        }

        if((cards[0][1] == cards[1][1] && cards[0][1] == cards[2][1] && cards[3][1] == cards[4][1]) 
        || (cards[0][1] == cards[1][1] && cards[2][1] == cards[3][1] && cards[2][1] == cards[4][1])) {
            printf("full house\n");
            continue;
        }

        if(flush) {
            printf("flush\n");
            continue;
        }

        if(straight) {
            printf("straight\n");
            continue;
        }

        if((cards[0][1] == cards[1][1] && cards[0][1] == cards[2][1]) 
        || (cards[1][1] == cards[2][1] && cards[1][1] == cards[3][1]) 
        || (cards[2][1] == cards[3][1] && cards[2][1] == cards[4][1])) {
            printf("three of a kind\n");
            continue;
        }

        int pairs = 0;
        for(int i = 1; i < 5; ++i) {
            if(cards[i - 1][1] == cards[i][1]) ++pairs;
        }

        if(pairs == 2) {
            printf("two pairs\n");
            continue;
        }

        if(pairs == 1) {
            printf("pair\n");
            continue;
        }

        printf("others\n");
    }
    return 0;
}