#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int n, m;
  int l, k;
  int l2, k2;
  int lawn_ptn[128][128];
  int lawn_ref;
  int result;

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    scanf("%d %d\n", &n, &m);

    printf("Case #%d: ", i + 1);

    for (l = 0; l < n; l++) {
      for (k = 0; k < m; k++) {
        scanf("%d", &(lawn_ptn[l][k]));
      }
    }

    result = 1;
    for (l = 0; l < n; l++) {
      for (k = 0; k < m; k++) {
        lawn_ref = lawn_ptn[l][k];
        for (l2 = 0; l2 < n; l2++) {
          if (lawn_ptn[l2][k] > lawn_ref)
            break;
        }
        if (l2 < n) {
          for (k2 = 0; k2 < m; k2++) {
            if (lawn_ptn[l][k2] > lawn_ref)
              break;
          }
          if (k2 < m) {
            result = 0;
            goto out_result;
          }
        }
      }
    }
  out_result:
    printf("%s", result ? "YES" : "NO");
    printf("\n");
  }

  return 0;
}
