#include <stdio.h>

int main() {
  int T, N, S, p, i, j;
  int score, ans;
  scanf("%d", &T);
  for (i = 1; i <= T; i++) {
    ans = 0;
    scanf("%d %d %d", &N, &S, &p);
    for (j = 0; j < N; j++) {
      scanf("%d", &score);
      if (score == 30) {
        ans++;
        continue;
      } else if (score == 29 && p <= 9) {
        ans++;
        continue;
      } else if (score == 0) {
        if (p == 0)
          ans++;
        continue;
      }
      switch (score % 3) {
      case 0:

        if (score / 3 >= p)
          ans++;
        else if (score / 3 + 1 >= p && S > 0) {
          ans++;
          S--;
        }
        break;

      case 1:

        if (score / 3 >= p || score / 3 + 1 >= p)
          ans++;

        break;

      case 2:
        if (score / 3 >= p || score / 3 + 1 >= p)
          ans++;
        else if (score / 3 + 2 >= p && S > 0) {
          ans++;
          S--;
        }
        break;
      }
    }
    printf("Case #%d: %d\n", i, ans);
  }
}
