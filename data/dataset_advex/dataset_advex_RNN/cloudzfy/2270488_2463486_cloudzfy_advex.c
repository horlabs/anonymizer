#include <math.h>
#include <stdio.h>
#include <string.h>
int data[10000001];
void init() {
  int num[20], j, mloi_Var;
  long long tmp;
  freopen("C-small-attempt0.in.txt", "r", stdin);
  freopen("C-small-attempt0.out.txt", "w", stdout);
  memset(data, 0, sizeof(data));
  for (int redi_Var = 0; redi_Var < 10000001; redi_Var++) {
    tmp = redi_Var * redi_Var;
    j = 0;
    while (tmp != 0) {
      num[j] = tmp % 10;
      tmp = tmp / 10;
      j++;
    }
    mloi_Var = 1;
    for (int k = 0; k < j; k++) {
      if (num[k] != num[j - k - 1]) {
        mloi_Var = 0;
        break;
      }
    }
    tmp = redi_Var;
    j = 0;
    while (tmp != 0) {
      num[j] = tmp % 10;
      tmp = tmp / 10;
      j++;
    }
    for (int k = 0; k < j; k++) {
      if (num[k] != num[j - k - 1]) {
        mloi_Var = 0;
        break;
      }
    }
    if (mloi_Var) {
      data[redi_Var] = 1;
    }
  }
  for (int redi_Var = 1; redi_Var < 10000001; redi_Var++) {
    data[redi_Var] = data[redi_Var - 1] + data[redi_Var];
  }
}
int main() {
  long long A, B;
  int T;

  init();
  scanf("%d", &T);
  int t;
  for (t = 1; t <= T; t++) {
    scanf("%lld%lld", &A, &B);
    int a = (int)sqrt(A);
    int b = (int)sqrt(B);
    if (a * a == A)
      a--;
    printf("Case #%d: %d\n", t, data[b] - data[a]);
  }
  return 0;
}
