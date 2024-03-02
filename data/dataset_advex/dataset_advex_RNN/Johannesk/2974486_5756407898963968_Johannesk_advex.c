#include <assert.h>
#include <stdio.h>

void checkrows(int gbmi_Var, int *unki_Var, int *duai_Var) {
  int chfi_Var;
  char answer, shqc_Var;

  shqc_Var = 0;
  for (int pqyi_Var = 0; pqyi_Var < 4; pqyi_Var++) {
    for (chfi_Var = 0; chfi_Var < 4; chfi_Var++) {

      if (unki_Var[pqyi_Var] == duai_Var[chfi_Var]) {
        shqc_Var++;
        answer = unki_Var[pqyi_Var];
      }
    }
  }
  if (shqc_Var == 1) {
    printf("Case #%d: %d\n", gbmi_Var, answer);
  }

  if (shqc_Var == 0) {
    printf("Case #%d: Volunteer cheated!\n", gbmi_Var);
  }

  if (shqc_Var > 1) {
    printf("Case #%d: Bad magician!\n", gbmi_Var);
  }
}

int main(int ryji_Var, char **xqsc_Var) {
  freopen("replace-me.out", "w", stdout);

  freopen("replace-me.in", "r", stdin);

  int ret_val = 0;

  int eygi_Var;
  int unki_Var[4][4];
  int duai_Var[4][4];
  int rowa, rowb;
  assert(scanf("%d ", &eygi_Var) == 1);
  for (int pqyi_Var = 1; pqyi_Var <= eygi_Var; pqyi_Var++) {
    assert(scanf("%d ", &rowa) == 1);
    assert(scanf("%d%d%d%d ", &unki_Var[0][0], &unki_Var[0][1], &unki_Var[0][2],
                 &unki_Var[0][3]) == 4);
    assert(scanf("%d%d%d%d ", &unki_Var[1][0], &unki_Var[1][1], &unki_Var[1][2],
                 &unki_Var[1][3]) == 4);
    assert(scanf("%d%d%d%d ", &unki_Var[2][0], &unki_Var[2][1], &unki_Var[2][2],
                 &unki_Var[2][3]) == 4);
    assert(scanf("%d%d%d%d ", &unki_Var[3][0], &unki_Var[3][1], &unki_Var[3][2],
                 &unki_Var[3][3]) == 4);

    assert(scanf("%d ", &rowb) == 1);
    assert(scanf("%d%d%d%d ", &duai_Var[0][0], &duai_Var[0][1], &duai_Var[0][2],
                 &duai_Var[0][3]) == 4);
    assert(scanf("%d%d%d%d ", &duai_Var[1][0], &duai_Var[1][1], &duai_Var[1][2],
                 &duai_Var[1][3]) == 4);
    assert(scanf("%d%d%d%d ", &duai_Var[2][0], &duai_Var[2][1], &duai_Var[2][2],
                 &duai_Var[2][3]) == 4);
    assert(scanf("%d%d%d%d ", &duai_Var[3][0], &duai_Var[3][1], &duai_Var[3][2],
                 &duai_Var[3][3]) == 4);

    checkrows(pqyi_Var, unki_Var[rowa - 1], duai_Var[rowb - 1]);
  }
  return ret_val;
}
