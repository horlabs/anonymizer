#include <stdio.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024

typedef struct {
    double C;
    double F;
    double X;
} Problem;

typedef struct {
    double ans;
    int flag;
} Solution;

Solution solve_problem(Problem problem) {
    double c = 0.0;
    double rate = 2.0;
    double ans = 0.0;
    int flag;
    
    do {
        double ttb = (problem.X - c) / rate;
        double t = 0.0;
        double c2 = c;
        double rate2 = rate;
        flag = 0;

        do {
            t += (problem.C - c2) / rate2;
            c2 = ((problem.C - c2) / rate2) * rate2 - problem.C;
            rate2 += problem.F;
            if (t + (problem.X - c2) / rate2 < ttb) flag = 1;
        } while (!flag && t < ttb);

        if (flag) {
            t = (problem.C - c) / rate;
            c = t * rate - problem.C;
            ans += t;
            rate += problem.F;
        }
        else ans += (problem.X - c) / rate;
    } while (flag);
    
    Solution solution;
    solution.ans = ans;
    solution.flag = flag;
    return solution;
}

int main(void) {
    FILE *fin = fopen("B-small-attempt0.in", "r");
    FILE *fout = fopen("out.txt", "w");
    
    int T;
    fscanf(fin, "%d", &T);
    
    for (int k = 0; k < T; k++) {
        Problem problem;
        fscanf(fin, "%lf%lf%lf", &problem.C, &problem.F, &problem.X);
        
        Solution solution = solve_problem(problem);
        
        fprintf(fout, "Case #%d: %lf\n", k+1, solution.ans);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}