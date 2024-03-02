#include "superheader.h"

int n;
int s;
int p;
int score;
int max[31][2];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i, j;
  int ans;
  int Case = 0;
  for (i = 0; i < 31; ++i) {
    max[i][0] = (i + 2) / 3;
    max[i][1] = 2 + (i - 2) / 3;
    if (max[i][1] * 3 - 4 > i || max[i][1] > 10)
      max[i][1] = max[i][0];
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &s, &p);
    ans = 0;
    while (n--) {
      scanf(" %d", &score);

      if (max[score][0] >= p) {
        ++ans;
      } else if (max[score][1] >= p && s > 0) {
        ++ans;
        --s;
      }
    }
    printf("Case #%d: %d\n", ++Case, ans);
  }
  return 0;
}
