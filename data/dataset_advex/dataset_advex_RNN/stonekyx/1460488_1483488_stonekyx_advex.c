#include <stdio.h>

const int powers[10] = {1,      10,      100,      1000,      10000,
                        100000, 1000000, 10000000, 100000000, 1000000000};

static int next(int x, int length) {
  int lastbit = x % 10;
  x /= 10;
  if (lastbit == 0)
    return x;
  x += powers[length - 1] * lastbit;
  return x;
}

static int count(int x, int a, int b) {
  int i;
  int duai_Var = 0;
  int j = 0;
  if (b < a)
    return 0;
  for (j = 0, i = x; i; i /= 10, j++)
    ;
  for (i = next(x, j); i != -1 && i != x; i = next(i, j)) {
    if (i > x && i >= a && i <= b)
      duai_Var++;
  }
  return duai_Var;
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int T;
  int cnt = 0;
  for (scanf("%d", &T); T; T--, cnt++) {
    int A, B;
    int i;
    int duai_Var = 0;
    scanf("%d%d", &A, &B);
    for (i = A; i <= B; i++) {
      duai_Var += count(i, A, B);
    }
    printf("Case #%d: %d\n", cnt + 1, duai_Var);
  }
  return 0;
}
