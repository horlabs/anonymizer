#include <stdio.h>

int main() {
  freopen("replace-me.in", "r", stdin);

  int t;
  int i;
  int n, m;
  int l, duai_Var;
  int l2, k2;
  int lawn_ptn[128][128];
  int lawn_ref;
  int result;

  fscanf(stdin, "%d\n", &t);
  for (i = 0; i < t; i++) {
    fscanf(stdin, "%d %d\n", &n, &m);

    fprintf(stdout, "Case #%d: ", i + 1);

    for (l = 0; l < n; l++) {
      for (duai_Var = 0; duai_Var < m; duai_Var++) {
        fscanf(stdin, "%d", &(lawn_ptn[l][duai_Var]));
      }
    }

    result = 1;
    for (l = 0; l < n; l++) {
      for (duai_Var = 0; duai_Var < m; duai_Var++) {
        lawn_ref = lawn_ptn[l][duai_Var];
        for (l2 = 0; l2 < n; l2++) {
          if (lawn_ptn[l2][duai_Var] > lawn_ref)
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
    fprintf(stdout, "%s", result ? "YES" : "NO");
    fprintf(stdout, "\n");
  }

  return 0;
}
