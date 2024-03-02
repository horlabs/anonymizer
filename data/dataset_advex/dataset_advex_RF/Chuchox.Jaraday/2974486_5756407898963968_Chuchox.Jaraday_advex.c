#include <stdio.h>

int main(void) {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int vcmi_Var, n, m, ojzi_Var, dvci_Var, coincidencias, ganador;
  int c1[4][4], c2[4][4];

  scanf("%d", &vcmi_Var);
  {
    int casos = 1;
    for (; casos <= vcmi_Var;) {

      scanf("%d", &n);
      for (ojzi_Var = 0; ojzi_Var < 4; ojzi_Var++) {
        for (dvci_Var = 0; dvci_Var < 4; dvci_Var++)
          scanf("%d", &c1[ojzi_Var][dvci_Var]);
      }
      scanf("%d", &m);
      for (ojzi_Var = 0; ojzi_Var < 4; ojzi_Var++) {
        for (dvci_Var = 0; dvci_Var < 4; dvci_Var++)
          scanf("%d", &c2[ojzi_Var][dvci_Var]);
      }

      coincidencias = 0;
      for (ojzi_Var = 0; ojzi_Var < 4; ojzi_Var++) {
        for (dvci_Var = 0; dvci_Var < 4; dvci_Var++) {

          if (c1[n - 1][ojzi_Var] == c2[m - 1][dvci_Var]) {
            ganador = c1[n - 1][ojzi_Var];
            coincidencias++;
          }
        }
      }

      if (coincidencias == 0)
        printf("Case #%d: Volunteer cheated!\n", casos);
      else {
        if (coincidencias == 1)
          printf("Case #%d: %d\n", casos, ganador);
        else
          printf("Case #%d: Bad magician!\n", casos);
      }

      casos++;
    }
  }

  return (0);
}
