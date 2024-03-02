#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double calculateAnswer(int k, double C, double F, double X);
int calculateK(double C, double F, double X);

int main()
{
    int numOfCases, caseCount = 0;
    scanf("%d", &numOfCases);
  
    while (numOfCases) {
        double C, F, X;
        scanf("%lf%lf%lf", &C, &F, &X);
      
        printf("Case #%d: %.7lf\n", ++caseCount, calculateAnswer(calculateK(C, F, X), C, F, X));
        numOfCases--;
    }
  
    return 0;
}

double calculateAnswer(int k, double C, double F, double X)
{
    int i;
    double answer = 0;
  
    for (i = 0; i < k; i++) {
        answer += C / (2.0 + F * i);
    }
  
    return answer + X / (2.0 + k * F);
}

int calculateK(double C, double F, double X)
{
    int k = (F * X - 2 * C) / (F * C);
  
    if (k < 0) {
        k = 0;
    }
  
    return k;
}