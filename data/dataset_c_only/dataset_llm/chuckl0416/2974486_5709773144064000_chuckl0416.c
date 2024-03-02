#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

typedef struct {
    double C;
    double F;
    double X;
} Problem;

Problem initializeProblem(double C, double F, double X) {
    Problem problem;
    problem.C = C;
    problem.F = F;
    problem.X = X;
    return problem;
}

double solveProblem(Problem problem) {
    double time = 0;
    double produce = 2;
    double ans = problem.X / produce;

    while (1) {
        if ((time + problem.C / produce + problem.X / (produce + problem.F)) >= ans) break;
        ans = time + problem.C / produce + problem.X / (produce + problem.F);
        time += problem.C / produce;
        produce += problem.F;
    }

    return ans;
}

int main() {
    int testCases, t;
    Problem problems[100];
    FILE *inputFile, *outputFile;

    inputFile = freopen(INPUT_FILE, "r", stdin);
    if (inputFile == NULL) {
        fprintf(stderr, "Failed to open input file.\n");
        return 1;
    }

    outputFile = freopen(OUTPUT_FILE, "w", stdout);
    if (outputFile == NULL) {
        fprintf(stderr, "Failed to open output file.\n");
        return 1;
    }

    scanf("%d", &testCases);

    for (t = 1; t <= testCases; t++) {
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);
        problems[t - 1] = initializeProblem(C, F, X);
    }

    for (t = 1; t <= testCases; t++) {
        Problem problem = problems[t - 1];
        printf("Case #%d: %.7lf\n", t, solveProblem(problem));
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}