#include <stdio.h>
#include <string.h>

int main() {
  int t, T, N, S, P, i, result, x;

  freopen("B-small-attempt4.out", "w", stdout);
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    result = 0;
    scanf("%d%d%d", &N, &S, &P);
    for (i = 0; i < N; i++) {
      scanf("%d", &x);
      if (x >= P * 3 - 2 && P - 1 >= 0) {
        result++;
      } else if (x >= P * 3 - 4 && S > 0 && P - 2 >= 0 && x <= 28) {
        result++;
        S--;
      }
    }
    printf("Case #%d: %d\n", t, result);
  }
}
