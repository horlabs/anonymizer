#include <stdio.h>

int main() {

  int ret_val = 0;

  freopen("replace-me.in", "r", stdin);
  int jffi_Var;
  scanf("%d", &jffi_Var);
  int ldoi_Var;
  for (ldoi_Var = 1; ldoi_Var <= jffi_Var; ++ldoi_Var) {
    int bdni_Var, m, duai_Var, ncni_Var;
    int oaji_Var[100][100], mrow[100] = {}, mcol[100] = {};
    printf("Case #%d: ", ldoi_Var);
    scanf("%d%d", &bdni_Var, &m);
    {
      duai_Var = 0;
      while (duai_Var < bdni_Var) {
        {
          ncni_Var = 0;
          while (ncni_Var < m) {
            scanf("%d", &oaji_Var[duai_Var][ncni_Var]);
            if (oaji_Var[duai_Var][ncni_Var] > mrow[duai_Var]) {
              mrow[duai_Var] = oaji_Var[duai_Var][ncni_Var];
            }
            if (oaji_Var[duai_Var][ncni_Var] > mcol[ncni_Var])
              mcol[ncni_Var] = oaji_Var[duai_Var][ncni_Var];

            ++ncni_Var;
          }
        }
        ++duai_Var;
      }
    }
    {
      duai_Var = 0;
      while (duai_Var < bdni_Var) {
        {
          ncni_Var = 0;
          while (ncni_Var < m) {
            if (oaji_Var[duai_Var][ncni_Var] != (mrow[duai_Var] < mcol[ncni_Var]
                                                     ? mrow[duai_Var]
                                                     : mcol[ncni_Var]))
              break;
            ++ncni_Var;
          }
        }
        if (ncni_Var < m)
          break;
        ++duai_Var;
      }
    }
    puts(duai_Var == bdni_Var ? "YES" : "NO");
  }
  return ret_val;
}
