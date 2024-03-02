#include <assert.h>
#include <stdio.h>

void checkrows(int ysji_Var, int *a, int *ojyi_Var) {
  int aaei_Var;
  char answer, ymyc_Var;

  ymyc_Var = 0;
  for (int bfui_Var = 0; bfui_Var < 4; bfui_Var++) {
    {
      aaei_Var = 0;
      while (aaei_Var < 4) {

        if (a[bfui_Var] == ojyi_Var[aaei_Var]) {
          ymyc_Var++;
          answer = a[bfui_Var];
        }
        aaei_Var++;
      }
    }
  }
  if (ymyc_Var == 1)
    printf("Case #%d: %d\n", ysji_Var, answer);
  if (ymyc_Var == 0) {
    printf("Case #%d: Volunteer cheated!\n", ysji_Var);
  }
  if (ymyc_Var > 1) {
    printf("Case #%d: Bad magician!\n", ysji_Var);
  }
}

int main(int glti_Var, char **fqgc_Var) {
  freopen("replace-me.in", "r", stdin);

  int ret_val = 0;
  int mcwi_Var;
  int a[4][4];
  int ojyi_Var[4][4];
  int rowa, rowb;
  assert(scanf("%d ", &mcwi_Var) == 1);
  for (int bfui_Var = 1; bfui_Var <= mcwi_Var; bfui_Var++) {
    assert(scanf("%d ", &rowa) == 1);
    assert(scanf("%d%d%d%d ", &a[0][0], &a[0][1], &a[0][2], &a[0][3]) == 4);
    assert(scanf("%d%d%d%d ", &a[1][0], &a[1][1], &a[1][2], &a[1][3]) == 4);
    assert(scanf("%d%d%d%d ", &a[2][0], &a[2][1], &a[2][2], &a[2][3]) == 4);
    assert(scanf("%d%d%d%d ", &a[3][0], &a[3][1], &a[3][2], &a[3][3]) == 4);

    assert(scanf("%d ", &rowb) == 1);
    assert(scanf("%d%d%d%d ", &ojyi_Var[0][0], &ojyi_Var[0][1], &ojyi_Var[0][2],
                 &ojyi_Var[0][3]) == 4);
    assert(scanf("%d%d%d%d ", &ojyi_Var[1][0], &ojyi_Var[1][1], &ojyi_Var[1][2],
                 &ojyi_Var[1][3]) == 4);
    assert(scanf("%d%d%d%d ", &ojyi_Var[2][0], &ojyi_Var[2][1], &ojyi_Var[2][2],
                 &ojyi_Var[2][3]) == 4);
    assert(scanf("%d%d%d%d ", &ojyi_Var[3][0], &ojyi_Var[3][1], &ojyi_Var[3][2],
                 &ojyi_Var[3][3]) == 4);

    checkrows(bfui_Var, a[rowa - 1], ojyi_Var[rowb - 1]);
  }
  return ret_val;
}
