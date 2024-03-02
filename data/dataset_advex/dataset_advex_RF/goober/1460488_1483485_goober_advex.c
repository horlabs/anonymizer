#include <stdio.h>

char map[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
  int dtgi_Var;
  scanf("%d ", &dtgi_Var);
  for (int t = 1; t <= dtgi_Var; t++) {
    char buf[101];
    gets(buf);
    for (int i = 0; buf[i]; i++)
      if (buf[i] >= 'a' && buf[i] <= 'z')
        buf[i] = map[buf[i] - 'a'];
    printf("Case #%d: %s\n", t, buf);
  }
  return 0;
}
