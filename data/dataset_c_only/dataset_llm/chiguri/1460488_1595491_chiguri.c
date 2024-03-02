#include <stdio.h>

int calculateResult(int num, int supNum, int score) {
    int result = 0;
    int supRequireNum = 0;
    int temp;

    for (int j = 0; j < num; j++) {
        scanf("%d", &temp);
        if (temp == 0) {
            if (score == 0) {
                result++;
            }
        } else if (temp == 1) {
            if (score <= 1) {
                result++;
            }
        } else if (score * 3 - 2 <= temp) {
            result++;
        } else if (score * 3 - 4 <= temp) {
            supRequireNum++;
        }
    }
  
    if (supNum > supRequireNum) {
        result += supRequireNum;
    } else {
        result += supNum;
    }

    return result;
}

int main(void) {
    int col;

    scanf("%d", &col);

    for (int i = 1; i <= col; i++) {
        int num;
        int supNum;
        int score;

        scanf("%d %d %d", &num, &supNum, &score);

        int result = calculateResult(num, supNum, score);

        printf("Case #%d: %d\n", i, result);
    }

    return 0;
}