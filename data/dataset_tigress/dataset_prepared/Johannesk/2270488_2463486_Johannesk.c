#include "superheader.h"

int ispalindrome(unsigned long num) {
  char s[100];
  int i, len, mid;

  sprintf(s, "%lu ", num);
  len = strlen(s) - 1;
  mid = len / 2;

  for (i = 0; i < mid; i++) {
    if (s[i] != s[len - 1 - i])
      return 0;
  }
  return 1;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, i, count;
  char line[10];
  unsigned long a, b, start, stop, p;

  (scanf("%d ", &t) == 1);
  for (i = 1; i <= t; i++) {
    count = 0;
    (scanf("%lu %lu ", &a, &b) == 2);
    start = ceil(sqrt(a));
    stop = floor(sqrt(b));

    for (p = start; p <= stop; p++) {
      if (ispalindrome(p) && ispalindrome(p * p))
        count++;
    }

    printf("Case #%d: %d\n", i, count);
  }
  return 0;
}
