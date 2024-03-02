#include <stdio.h>

void readInput(int *T, int *answers) {
    scanf("%d", T);
    for (int i = 0; i < *T * 2; i++) {
        scanf("%d", &answers[i]);
        for (int j = 0; j < 4; j++) {
            int x;
            scanf("%d", &x);
        }
    }
}

int countDuplicates(int *answers, int T, int *possible) {
    int twos = 0;
    int bt = 0;
    for (int i = 0; i < T * 2; i+=2) {
        int ans = answers[i];
        for (int j = 0; j < 4; j++) {
            int x;
            scanf("%d", &x);
            if (j == ans - 1) {
                possible[x]++;
                if (possible[x] == 2) {
                    bt = x;
                    twos++;
                }
            }
        }
    }
    return twos;
}

void printResult(int t, int twos, int bt) {
    printf("Case #%d: ", t);
    if (twos == 0) {
        printf("Volunteer cheated!");
    } else if (twos >= 2) {
        printf("Bad magician!");
    } else {
        printf("%d", bt);
    }
    printf("\n");
}

int main() {
    int T;
    int answers[100] = {0};
    readInput(&T, answers);
    
    for(int t = 1; t <= T; t++) {
        int possible[17] = {0};
        int twos = countDuplicates(answers, t, possible);
        printResult(t, twos, twos > 0 ? bt : 0);
    }

    return 0;
}