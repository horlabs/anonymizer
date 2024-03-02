#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int n;
    int s;
    int p;
} Test;

int calculate_threshold(int p, int threshold_delta) {
    return p > threshold_delta ? 3 * p - threshold_delta : 0;
}

int is_score_possible(int score, int threshold, int surprise_count) {
    return score >= threshold && (score > 1 || surprise_count > 0);
}

int count_possible_scores(Test test) {
    int i;
    int y = 0;

    for (i = 0; i < test.n; i++) {
        int total;
        int threshold_norm = calculate_threshold(test.p, 2);
        int threshold_surprise = calculate_threshold(test.p, 4);

        scanf("%d", &total);

        if (test.p > 10) {
            continue;
        }

        if (is_score_possible(total, threshold_norm, test.s)) {
            y++;
            if (total >= threshold_surprise) {
                test.s--;
            }
        }
    }

    return y;
}

void execute_test(int test_number) {
    Test test;

    scanf("%d %d %d", &test.n, &test.s, &test.p);

    int result = count_possible_scores(test);

    printf("Case #%d: %d\n", test_number + 1, result);
}

int main() {
    int t, i;
    scanf("%d", &t);
	
    for (i = 0; i < t; i++) {
        execute_test(i);
    }

    return 0;
}