#include <math.h>
#include <stdio.h>
#include <string.h>
int data[10000001];
void init() {
  int num[20], j, flag;
  long long tmp;

  freopen("C-small-attempt0.out.txt", "w", stdout);
  memset(data, 0, sizeof(data));
  for (int i = 0; i < 10000001; i++) {
    tmp = i * i;
    j = 0;
    while (tmp != 0) {
      num[j] = tmp % 10;
      tmp = tmp / 10;
      j++;
    }
    flag = 1;
    for (int k = 0; k < j; k++) {
      if (num[k] != num[j - k - 1]) {
        flag = 0;
        break;
      }
    }
    tmp = i;
    j = 0;
    while (tmp != 0) {
      num[j] = tmp % 10;
      tmp = tmp / 10;
      j++;
    }
    for (int k = 0; k < j; k++) {
      if (num[k] != num[j - k - 1]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      data[i] = 1;
    }
  }
  for (int i = 1; i < 10000001; i++) {
    data[i] = data[i - 1] + data[i];
  }
}
int main() {
  long long A, B;
  int T;

  init();
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%lld%lld", &A, &B);
    int a = (int)sqrt(A);
    int b = (int)sqrt(B);
    if (a * a == A)
      a--;
    printf("Case #%d: %d\n", t, data[b] - data[a]);
  }
  return 0;
}
