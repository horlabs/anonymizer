#include "superheader.h"

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

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("C-small-attempt0.in", "r", stdin);

  int testcase = 0;
  int testcases;

  scanf("%d\n", &testcases);

  while (testcase < testcases) {
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

    printf("Case #%d: %llu\n", ++testcase, res);
  }

  return 0;
}
