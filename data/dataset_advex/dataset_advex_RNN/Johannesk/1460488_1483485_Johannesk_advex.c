#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int nvpi_Var, char **duac_Var) {
  char s[26] = "yhesocvxduiglbkrztnwjpfmaq";
  char d[105], e[105];
  int jffi_Var, v, i, j, l;

  assert(scanf("%d ", &jffi_Var) == 1);
  for (i = 1; i <= jffi_Var; i++) {
    assert(fgets(d, 105, stdin) != NULL);
    l = strlen(d);
    for (j = 0; j < l; j++) {
      if ((d[j] != ' ') && (d[j] != 0xA))
        e[j] = s[d[j] - 'a'];
      else if (d[j] == ' ')
        e[j] = d[j];
    }
    e[j - 1] = '\0';
    printf("Case #%d: %s\n", i, e);
  }
  return 0;
}
