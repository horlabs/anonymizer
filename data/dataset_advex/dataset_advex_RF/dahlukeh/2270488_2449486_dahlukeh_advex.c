#include <stdio.h>

void do_voiiod_fct();

int h, w;

int lrfi_Var[100][100];

int doesWork(int y, int x);

int main() {

  int brpi_Var;
  scanf("%d ", &brpi_Var);

  for (int ryfi_Var = 0; ryfi_Var < brpi_Var; ryfi_Var++) {
    printf("Case #%d: ", ryfi_Var + 1);
    do_voiiod_fct();
  }
  return 0;
}

void do_voiiod_fct() {
  int ryfi_Var, ceti_Var;
  scanf("%d %d ", &h, &w);
  {
    ryfi_Var = 0;
    while (ryfi_Var < h) {
      {
        ceti_Var = 0;
        while (ceti_Var < w) {
          scanf("%d ", &lrfi_Var[ryfi_Var][ceti_Var]);
          ceti_Var++;
        }
      }
      ryfi_Var++;
    }
  }
  {
    ryfi_Var = 0;
    while (ryfi_Var < h) {
      {
        ceti_Var = 0;
        while (ceti_Var < w) {
          if (!doesWork(ryfi_Var, ceti_Var)) {
            printf("NO\n");
            return;
          }
          ceti_Var++;
        }
      }
      ryfi_Var++;
    }
  }
  printf("YES\n");
}

int doesWork(int y, int x) {
  int num = lrfi_Var[y][x];
  int ryfi_Var;
  int allLess = 1;
  {
    ryfi_Var = 0;
    while (ryfi_Var < h && allLess) {
      if (lrfi_Var[ryfi_Var][x] > num) {
        allLess = 0;
      }
      ryfi_Var++;
    }
  }
  if (allLess)
    return 1;

  allLess = 1;
  {
    ryfi_Var = 0;
    for (; ryfi_Var < w && allLess;) {
      if (lrfi_Var[y][ryfi_Var] > num) {
        allLess = 0;
      }
      ryfi_Var++;
    }
  }
  return allLess;
}
