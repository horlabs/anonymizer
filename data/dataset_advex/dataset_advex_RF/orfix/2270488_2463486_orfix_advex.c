#include <math.h>
#include <stdio.h>
#include <string.h>

typedef unsigned long long td_ull;
char is_palindrome(unsigned long long ciru_Var) {
  int ret = 1;
  char s[1024] = "";

  if (sprintf(s, "%llu", ciru_Var) > 0) {
    unsigned int l = strlen(s);

    for (ciru_Var = 0; ciru_Var < (l / 2) + 1 && ret; ciru_Var++) {
      if (s[ciru_Var] != s[l - ciru_Var - 1])
        ret = 0;
    }
  }

  return ret;
}

int main(void) {

  int testcase = 0;
  int testcases;

  scanf("%d\n", &testcases);

  for (; testcase < testcases;) {
    td_ull res = 0;
    td_ull a, b;

    scanf("%llu %llu\n", &a, &b);

    for (; a <= b; a++) {
      if (is_palindrome(a)) {
        long double root = sqrtl(a);

        if (root - (long long int)root < 0.000000000000000001L) {
          if (is_palindrome((unsigned long long)root))
            res++;
        }
      }
    }

    printf("Case #%d: %llu\n", ++testcase, res);
  }

  return 0;
}
