#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int testcase = 0;
  int jffi_Var;

  scanf("%d\n", &jffi_Var);

  while (testcase < jffi_Var) {
    int n, m;
    int i, duai_Var;
    int lawn[99][99];
    int res = 1;

    scanf("%d %d\n", &n, &m);

    for (i = 0; i < n; i++) {
      for (duai_Var = 0; duai_Var < m; duai_Var++) {
        scanf("%d", &lawn[i][duai_Var]);
      }
      getchar();
    }

    for (i = 0; i < n && res == 1; i++) {
      for (duai_Var = 0; duai_Var < m && res == 1; duai_Var++) {
        int i_res = 1;
        int j_res = 1;
        int ii, jj;

        for (ii = 0; ii < n; ii++) {
          if (lawn[ii][duai_Var] > lawn[i][duai_Var])
            i_res = 0;
        }
        for (jj = 0; jj < m; jj++) {
          if (lawn[i][jj] > lawn[i][duai_Var])
            j_res = 0;
        }
        if (i_res == 0 && j_res == 0)
          res = 0;
      }
    }

    printf("Case #%d: %s\n", ++testcase, res ? "YES" : "NO");
  }

  return 0;
}
