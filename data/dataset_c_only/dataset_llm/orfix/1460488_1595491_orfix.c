#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int n;
    int goodDancers;
    int surprising;
    double best;
} TestCase;

double calculate_mean_score(double score) {
    double mean_score = score / 3;
    return floor(mean_score);
}

double calculate_category(double score) {
    double mean_score = calculate_mean_score(score);
    return (mean_score - floor(mean_score));
}

double calculate_max(double mean_score, double category) {
    if (category == 0) {
        return mean_score;
    } else if (category <= 0.5) {
        return mean_score + 1;
    } else {
        return mean_score + 1;
    }
}

double calculate_max_sur(double mean_score, double category) {
    if (category == 0) {
        return mean_score + 1;
    } else if (category <= 0.5) {
        return mean_score + 1;
    } else {
        return mean_score + 2;
    }
}

void process_testcase(TestCase *testcase) {
    for (int i = 0; i < testcase->n; i++) {
        double score;
        scanf("%lf", &score);

        if (score < testcase->best) {
            continue;
        }

        double category = calculate_category(score);
        double mean_score = calculate_mean_score(score);

        double max = calculate_max(mean_score, category);
        double max_sur = calculate_max_sur(mean_score, category);

        if (max >= testcase->best) {
            testcase->goodDancers++;
        } else if (testcase->surprising > 0 && max_sur >= testcase->best) {
            testcase->goodDancers++;
            testcase->surprising--;
        }
    }
}

int main(void) {
    int testcases;
    scanf("%d\n", &testcases);

    TestCase cases[testcases];

    for (int i = 0; i < testcases; i++) {
        scanf("%d %d %lf", &(cases[i].n), &(cases[i].surprising), &(cases[i].best));
        process_testcase(&(cases[i]));
    }

    for (int i = 0; i < testcases; i++) {
        printf("Case #%d: %d\n", i + 1, cases[i].goodDancers);
    }

    return 0;
}