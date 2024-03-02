#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long td_ull;
int main() {
  int miqi_Var, j;
  int hxoi_Var, jj, cbvi_Var;
  int shqi_Var;
  int ojdi_Var;
  int map[10][10];
  int nvpi_Var, xw, ow;
  int r1, r2;
  int jffi_Var[10];
  int p2[10];
  int count;
  int ans;

  td_ull ysjt_Var;

  scanf("%d", &ojdi_Var);

  for (hxoi_Var = 1; hxoi_Var <= ojdi_Var; hxoi_Var++) {
    scanf("%d", &r1);
    for (miqi_Var = 0; miqi_Var < 4; miqi_Var++)
      for (j = 0; j < 4; j++) {
        scanf("%d", &map[miqi_Var][j]);
        if (miqi_Var == r1 - 1)
          jffi_Var[j] = map[miqi_Var][j];
      }

    scanf("%d", &r2);
    for (miqi_Var = 0; miqi_Var < 4; miqi_Var++)
      for (j = 0; j < 4; j++) {
        scanf("%d", &map[miqi_Var][j]);
        if (miqi_Var == r2 - 1)
          p2[j] = map[miqi_Var][j];
      }

    count = 0;
    ans = -1;

    for (miqi_Var = 0; miqi_Var < 4; miqi_Var++) {
      for (j = 0; j < 4; j++) {
        if (jffi_Var[miqi_Var] == p2[j]) {
          ans = jffi_Var[miqi_Var];
          count++;
          break;
        }
      }
    }

    if (count == 0)
      printf("Case #%d: Volunteer cheated!\n", hxoi_Var);
    else if (count == 1)
      printf("Case #%d: %d\n", hxoi_Var, ans);
    else
      printf("Case #%d: Bad magician!\n", hxoi_Var);
  }
}
