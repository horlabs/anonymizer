#include <stdio.h>

char u[28] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  freopen("replace-me.in", "r", stdin);

  int n, i, duai_Var;
  char s[108];
  scanf("%d", &n);
  gets(s);
  for (duai_Var = 1; duai_Var <= n; duai_Var++) {
    gets(s);
    printf("Case #%d: ", duai_Var);
    for (i = 0; s[i]; i++)
      putchar(s[i] == 32 ? s[i] : u[(int)(s[i] - 'a')]);
    puts("");
  }
  return 0;
}
