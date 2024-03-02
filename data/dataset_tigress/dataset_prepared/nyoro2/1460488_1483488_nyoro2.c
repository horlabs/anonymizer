#include "superheader.h"

int get_digits(int n) {
  int i;
  int result = 0;
  while (n > 0) {
    n /= 10;
    result++;
  }
  return result;
}

void int2digits(int n, int *buf, int num) {
  int i;
  for (i = num - 1; i >= 0; i--) {
    buf[i] = n % 10;
    n /= 10;
  }
}

int comp_digits(int *buf1, int *buf2, int num) {
  int i;
  for (i = 0; i < num; i++) {
    if (buf1[i] > buf2[i])
      return 1;
    else if (buf1[i] < buf2[i])
      return -1;
  }
  return 0;
}

void disp_digits(int *buf, int num) {
  int i;
  for (i = 0; i < num; i++) {
    fputc('0' + buf[i], stderr);
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i, j, k, l, n;
  int a, b;
  int result;
  int result1, result2;
  int num_digits;
  int ref_buf[16];
  int recyc_buf[16];
  int a_buf[16];
  int b_buf[16];

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d\n", &a, &b);

    num_digits = get_digits(a);

    int2digits(a, a_buf, num_digits);
    int2digits(b, b_buf, num_digits);
    result1 = 0;
    result2 = 0;
    for (j = a; j <= b; j++) {
      int2digits(j, ref_buf, num_digits);
      for (n = 1; n <= (num_digits / 2); n++) {
        int ltmp = n;
        if (ref_buf[n] == 0)
          continue;
        for (l = 0; l < num_digits; l++) {
          recyc_buf[l] = ref_buf[ltmp++];
          if (ltmp >= num_digits)
            ltmp = 0;
        }
        if (comp_digits(ref_buf, recyc_buf, num_digits) != 0) {
          if ((comp_digits(recyc_buf, a_buf, num_digits) >= 0) &&
              (comp_digits(recyc_buf, b_buf, num_digits) <= 0)) {

            if (n * 2 == num_digits) {
              result1++;

            } else {
              result2++;
            }
          }
        }
      }
    }
    result = result1 / 2 + result2;

    printf("Case #%d: %d\n", i + 1, result);
  }

  return 0;
}
