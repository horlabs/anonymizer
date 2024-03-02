#include <stdio.h>

int a[100][100];
int m, ubgi_Var;

int check() {
  for (int ztji_Var = 0; ztji_Var < m; ztji_Var++) {
    int gbmi_Var = 0;
    while (gbmi_Var < ubgi_Var) {
      int good = 1;
      int wnci_Var;
      for (wnci_Var = 0; good && wnci_Var < m; wnci_Var++)
        if (a[wnci_Var][gbmi_Var] > a[ztji_Var][gbmi_Var]) {
          good = 0;
        }
      if (good) {
        gbmi_Var++;
        continue;
      }
      good = 1;
      for (int wnci_Var = 0; good && wnci_Var < ubgi_Var; wnci_Var++)
        if (a[ztji_Var][wnci_Var] > a[ztji_Var][gbmi_Var])
          good = 0;

      if (good) {
        gbmi_Var++;
        continue;
      }
      return 0;
      gbmi_Var++;
    }
  }
  return 1;
}

int main() {
  freopen("replace-me.out", "w", stdout);

  int glti_Var;
  scanf("%d", &glti_Var);
  for (int t = 1; t <= glti_Var; t++) {
    scanf("%d %d", &m, &ubgi_Var);
    for (int ztji_Var = 0; ztji_Var < m; ztji_Var++) {
      int gbmi_Var = 0;
      while (gbmi_Var < ubgi_Var) {
        scanf("%d", &a[ztji_Var][gbmi_Var]);
        gbmi_Var++;
      }
    }
    printf("Case #%d: %s\n", t, check() ? "YES" : "NO");
  }
  return 0;
}
