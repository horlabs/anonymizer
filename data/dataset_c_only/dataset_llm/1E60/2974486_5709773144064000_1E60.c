#include <stdio.h>
#include <stdlib.h>

#define MAX_CASES 100

typedef struct {
    double C;
    double F;
    double X;
} TestCase;

double calculateTotalTime(TestCase testCase) {
    double total_time = 0.0;
    double rate = 2.0;
    
    while (1) {
        double time_without_farm = testCase.X / rate;
        double time_to_buy_farm = testCase.C / rate;
        double time_with_farm = testCase.X / (rate + testCase.F);
        
        if (time_without_farm < (time_to_buy_farm + time_with_farm)) {
            total_time += time_without_farm;
            break;
        }
        
        rate += testCase.F;
        total_time += time_to_buy_farm;
    }
    
    return total_time;
}

int main() {
    int num_cases;
    scanf("%d\n", &num_cases);
    
    TestCase testCases[MAX_CASES];
    
    for (int i = 0; i < num_cases; i++) {
        scanf("%lf %lf %lf\n", &testCases[i].C, &testCases[i].F, &testCases[i].X);
    }
    
    for (int i = 0; i < num_cases; i++) {
        double total_time = calculateTotalTime(testCases[i]);
        printf("Case #%d: %.8lf\n", i+1, total_time);
    }
    
    return 0;
}