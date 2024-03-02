#include <stdio.h>

int main(void) {

  int ret_val = 0;
  int ncni_Var = 0;
  int wgpi_Var;
  scanf("%d\n", &wgpi_Var);
  for (; ncni_Var < wgpi_Var;) {
    int fcki_Var, m;
    int vcmi_Var, axei_Var;
    int lawn[99][99];
    int res = 1;

    scanf("%d %d\n", &fcki_Var, &m);

    for (vcmi_Var = 0; vcmi_Var < fcki_Var; vcmi_Var++) {
      for (axei_Var = 0; axei_Var < m; axei_Var++)
        scanf("%d", &lawn[vcmi_Var][axei_Var]);

      getchar();
    }

    for (vcmi_Var = 0; vcmi_Var < fcki_Var && res == 1; vcmi_Var++) {
      for (axei_Var = 0; axei_Var < m && res == 1; axei_Var++) {
        int i_res = 1;
        int j_res = 1;

        for (int ii = 0; ii < fcki_Var; ii++) {
          if (lawn[ii][axei_Var] > lawn[vcmi_Var][axei_Var])
            i_res = 0;
        }

        for (int jj = 0; jj < m; jj++) {
          if (lawn[vcmi_Var][jj] > lawn[vcmi_Var][axei_Var])
            j_res = 0;
        }
        if (i_res == 0)
          if (j_res == 0)
            res = 0;
      }
    }

    printf("Case #%d: %s\n", ++ncni_Var, res ? "YES" : "NO");
  }
  return ret_val;
}
