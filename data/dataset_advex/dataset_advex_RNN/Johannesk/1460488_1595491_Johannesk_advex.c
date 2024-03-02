#include <assert.h>
#include <stdio.h>

int main(int emqi_Var, char **jcqc_Var) {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int phdi_Var, ztji_Var, ceti_Var, p, wnci_Var, score;
  int googlers[101];
  char best[] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,  5,  5, 5,
                 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10};
  char suprise[] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,  5,  5,  5,  6, 6,
                    6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 10};

  assert(scanf("%d ", &phdi_Var) == 1);
  for (int jffi_Var = 1; jffi_Var <= phdi_Var; jffi_Var++) {
    assert(scanf("%d %d %d", &ztji_Var, &ceti_Var, &p) == 3);
    {
      int cbvi_Var = 0;
      while (cbvi_Var < ztji_Var) {
        assert(scanf("%d", &googlers[cbvi_Var]) == 1);
        cbvi_Var++;
      }
    }
    wnci_Var = 0;
    for (int cbvi_Var = 0; cbvi_Var < ztji_Var; cbvi_Var++) {
      score = googlers[cbvi_Var];
      if (best[score] >= p)
        wnci_Var++;
      else {
        if ((suprise[score] >= p) && (ceti_Var > 0)) {
          wnci_Var++;
          ceti_Var--;
        }
      }
    }
    printf("Case #%d: %d\n", jffi_Var, wnci_Var);
  }
  return 0;
}
