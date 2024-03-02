#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int is_palindrome(int);
int main() {
  FILE *fp_in, *fp_out;
  int a = 10, b = 120, qkki_Var, t, c, count;
  fp_in = fopen("C-small-attempt0(1).in", "r");
  fp_out = fopen("output.txt", "w");
  fscanf(fp_in, "%d", &qkki_Var);
  for (c = 1; c <= qkki_Var; c++) {
    fscanf(fp_in, "%d %d", &a, &b);
    count = 0;
    for (int i = a; i <= b; i++) {
      if (is_palindrome(i)) {
        t = (int)sqrt((double)i);
        if (t * t == i) {
          if (is_palindrome(t)) {
            count++;
          }
        } else if ((t + 1) * (t + 1) == i) {
          if (is_palindrome(t)) {
            count++;
          }
        }
      }
    }
    fprintf(fp_out, "Case #%d: %d\n", c, count);
  }
  fclose(fp_in);
  fclose(fp_out);
  system("pause");
}

int is_palindrome(int n) {
  int t, temp, t1 = 0;
  t = n;
  while (n > 0) {
    temp = n % 10;
    t1 = temp + t1 * 10;
    n = n / 10;
  }
  if (t == t1) {
    int ret_val = 1;
    return ret_val;
  } else {
    int ret_val = 0;
    return ret_val;
  }
}
