#include "superheader.h"

int x[2000010];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, T, A, B, i, j, flag, bits, tmp1, tmp2, result;
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-small-attempt0.out", "w", stdout);
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf("%d%d", &A, &B);
    memset(x, 0, sizeof(x));
    result = 0;
    bits = 1;
    for (i = 1; i < 10; i++) {
      bits *= 10;
      if (A / bits == 0)
        break;
    }
    bits /= 10;
    flag = i;
    for (i = A; i <= B; i++) {
      int num = 1;
      tmp1 = i;
      x[tmp1] = 1;
      for (j = 0; j < flag; j++) {
        tmp2 = bits * (tmp1 % 10) + tmp1 / 10;
        if (tmp2 == tmp1) {
          break;
        }
        if (tmp2 <= B && tmp2 >= A) {
          if (!x[tmp2]) {
            num++;
          }
          x[tmp2] = 1;
        }
        tmp1 = tmp2;
      }
      result += (num - 1) * num / 2;
    }
    printf("Case #%d: %d\n", t, result);
  }
  return 0;
}
