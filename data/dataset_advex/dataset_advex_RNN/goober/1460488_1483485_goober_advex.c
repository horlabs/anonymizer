#include <stdio.h>

char map[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  freopen("replace-me.in", "r", stdin);

  int duai_Var;
  scanf("%d ", &duai_Var);
  for (int t = 1; t <= duai_Var; t++) {
    char buf[101];
    gets(buf);
    for (int i = 0; buf[i]; i++)
      if (buf[i] >= 'a' && buf[i] <= 'z')
        buf[i] = map[buf[i] - 'a'];
    printf("Case #%d: %s\n", t, buf);
  }
  return 0;
}
