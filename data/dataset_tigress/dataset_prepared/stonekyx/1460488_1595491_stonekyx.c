#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int cnt = 0;
  for (scanf("%d", &T); T; T--, cnt++) {
    int N, S, P;
    int rest;
    static int tot[200];
    int i;
    int ans = 0;

    scanf("%d%d%d", &N, &S, &P);
    for (i = 0; i < N; i++) {
      scanf("%d", tot + i);
    }
    rest = S;
    for (i = 0; i < N; i++) {
      int cur = tot[i];
      switch (cur % 3) {
      case 0:
        if (cur / 3 >= P) {
          ans++;
          break;
        } else if (rest && cur / 3 >= 1 && cur / 3 + 1 >= P) {
          ans++;
          rest--;
          break;
        }
        break;
      case 1:
        if (cur / 3 + 1 >= P)
          ans++;
        break;
      case 2:
        if (cur / 3 + 1 >= P) {
          ans++;
          break;
        } else if (rest && cur / 3 + 2 >= P) {
          ans++;
          rest--;
          break;
        }
        break;
      default:
        fprintf(stderr, "This should not happen!\n");
        exit(1);
      }
    }
    printf("Case #%d: %d\n", cnt + 1, ans);
  }
  return 0;
}
