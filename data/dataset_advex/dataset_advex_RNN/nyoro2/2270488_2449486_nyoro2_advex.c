#include <stdio.h>

int main() {

  freopen("replace-me.out", "w", stdout);

  int ycoi_Var;

  int pcli_Var, m;
  int ojdi_Var, duai_Var;
  int l2, k2;
  int lawn_ptn[128][128];
  int lawn_ref;
  int pcei_Var;

  fscanf(stdin, "%d\n", &ycoi_Var);
  {
    int jkei_Var = 0;
    while (jkei_Var < ycoi_Var) {
      fscanf(stdin, "%d %d\n", &pcli_Var, &m);

      fprintf(stdout, "Case #%d: ", jkei_Var + 1);

      {
        ojdi_Var = 0;
        while (ojdi_Var < pcli_Var) {
          for (duai_Var = 0; duai_Var < m; duai_Var++) {
            fscanf(stdin, "%d", &(lawn_ptn[ojdi_Var][duai_Var]));
          }

          ojdi_Var++;
        }
      }

      pcei_Var = 1;
      {
        ojdi_Var = 0;
        while (ojdi_Var < pcli_Var) {
          {
            duai_Var = 0;
            while (duai_Var < m) {
              lawn_ref = lawn_ptn[ojdi_Var][duai_Var];
              for (l2 = 0; l2 < pcli_Var; l2++) {
                if (lawn_ptn[l2][duai_Var] > lawn_ref) {
                  break;
                }
              }
              if (l2 < pcli_Var) {
                {
                  k2 = 0;
                  while (k2 < m) {
                    if (lawn_ptn[ojdi_Var][k2] > lawn_ref) {
                      break;
                    }
                    k2++;
                  }
                }
                if (k2 < m) {
                  pcei_Var = 0;
                  goto out_result;
                }
              }
              duai_Var++;
            }
          }
          ojdi_Var++;
        }
      }
    out_result:
      fprintf(stdout, "%s", pcei_Var ? "YES" : "NO");
      fprintf(stdout, "\n");
      jkei_Var++;
    }
  }

  return 0;
}
