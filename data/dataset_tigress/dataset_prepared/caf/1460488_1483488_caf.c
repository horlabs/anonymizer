#include "superheader.h"
long most_sig_digit(long a) {
  long tens;

  for (tens = 1; a >= 10; a /= 10, tens *= 10)
    ;

  return tens;
}

long rotate(long m, long msd) { return m / 10 + msd * (m % 10); }

long pairs(long a, long b, long n) {
  const long msd = most_sig_digit(a);
  long count = 0;
  long m;

  for (m = rotate(n, msd); m != n; m = rotate(m, msd)) {
    if (m <= b && m > n) {
      count++;
      fprintf(stderr, "(%ld, %ld)\n", n, m);
    }
  }

  return count;
}
void do_test(int t) {
  long a, b, i;
  long count = 0;

  scanf("%ld %ld", &a, &b);

  for (i = a; i <= b; i++)
    count += pairs(a, b, i);

  printf("Case #%d: %ld\n", t + 1, count);
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, i;

  scanf("%d", &t);

  for (i = 0; i < t; i++)
    do_test(i);

  return 0;
}
