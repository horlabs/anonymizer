#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int fqgi_Var, char **suic_Var) {
  freopen("replace-me.out", "w", stdout);

  freopen("replace-me.in", "r", stdin);

  int ret_val = 0;

  char xcrc_Var[26] = "yhesocvxduiglbkrztnwjpfmaq";
  char d[105], e[105];
  int wnci_Var, v, zvmi_Var, l;
  assert(scanf("%d ", &wnci_Var) == 1);
  {
    int jzxi_Var = 1;
    for (; jzxi_Var <= wnci_Var;) {
      assert(fgets(d, 105, stdin) != NULL);
      l = strlen(d);
      {
        zvmi_Var = 0;
        for (; zvmi_Var < l;) {
          if ((d[zvmi_Var] != ' ') && (d[zvmi_Var] != 0xA)) {
            e[zvmi_Var] = xcrc_Var[d[zvmi_Var] - 'a'];
          } else {
            if (d[zvmi_Var] == ' ') {
              e[zvmi_Var] = d[zvmi_Var];
            }
          }
          zvmi_Var++;
        }
      }
      e[zvmi_Var - 1] = '\0';
      printf("Case #%d: %s\n", jzxi_Var, e);
      jzxi_Var++;
    }
  }
  return ret_val;
}
