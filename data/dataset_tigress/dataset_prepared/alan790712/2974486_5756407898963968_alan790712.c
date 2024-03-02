#include "superheader.h"

int t, T;
int card[2][5];
int a[2];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i, j, k;
  int ans;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    for (i = 0; i < 2; ++i) {
      scanf("%d", &a[i]);
      for (j = 1; j <= 4; ++j) {
        for (k = 1; k <= 4; ++k) {
          if (j == a[i])
            scanf("%d", &card[i][k]);
          else
            scanf("%*d");
        }
      }
    }
    for (i = 1, ans = -1; i <= 4; ++i) {
      for (j = 1; j <= 4; ++j) {
        if (card[0][i] == card[1][j]) {
          if (ans == -1) {
            ans = card[0][i];
          } else {
            break;
          }
        }
      }
      if (j <= 4)
        break;
    }
    printf("Case #%d: ", t);
    if (ans != -1 && i > 4) {
      printf("%d\n", ans);
    } else if (ans != -1 && i <= 4) {
      printf("Bad magician!\n");
    } else {
      printf("Volunteer cheated!\n");
    }
  }

  return 0;
}
