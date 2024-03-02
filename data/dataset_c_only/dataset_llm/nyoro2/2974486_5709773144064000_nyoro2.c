//
// anonymized_qual_b.c
//

#include <stdio.h>

double calculateTime(double c, double f, double x) {
    double time_base = 0;
    double time1, time2;
    int j = 0;
    
    while(1) {
        time1 = time_base + x/(f*j+2);
        time_base += c/(f*j+2);
        j++;
        time2 = time_base + x/(f*j+2);
        if(time1 <= time2) break;
    }
    
    return time1;
}

int main() {
    int numTestCases;
    int i;

    fscanf(stdin, "%d\n", &numTestCases);
    
    for(i = 0; i < numTestCases; i++) {
        double c, f, x;
        fscanf(stdin, "%lf %lf %lf\n", &c, &f, &x);

        double result = calculateTime(c, f, x);

        printf("Case #%d: %.7f\n", i+1, result);
    }

    return 0;
}

// End of anonymized_qual_b.c