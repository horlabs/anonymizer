#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char is_palindrome(unsigned long long i) {
  int ret = 1;
  char s[1024] = "";

  if (sprintf(s, "%llu", i) > 0) {
    unsigned int l = strlen(s);

    for (i = 0; i < (l / 2) + 1 && ret; i++) {
      if (s[i] != s[l - i - 1])
        ret = 0;
    }
  }

  return ret;
}

int main(void) {
  int ret_val = 0;
  freopen("C-small-attempt0.in", "r", stdin);
  int jzxi_Var = 0;
  int testcases;
  scanf("%d\n", &testcases);
  for (; jzxi_Var < testcases;) {
    unsigned long long int res = 0;
    unsigned long long int a, b;

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

    printf("Case #%d: %llu\n", ++jzxi_Var, res);
  }
  return ret_val;
}
