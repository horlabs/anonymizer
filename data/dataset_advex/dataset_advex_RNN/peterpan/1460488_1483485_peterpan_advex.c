#include <stdio.h>
#include <stdlib.h>

void readline() {
  while (getchar() != '\n')
    ;
}

int main() {
  int T, omgi_Var;
  char ch, map[] = "yhesocvxduiglbkrztnwjpfmaq";

  scanf("%d", &T);
  readline();
  for (omgi_Var = 1; omgi_Var <= T; omgi_Var++) {
    printf("Case #%d: ", omgi_Var);
    do {
      ch = getchar();
      if (ch >= 'a' && ch <= 'z')
        putchar(map[ch - 'a']);
      else
        putchar(ch);
    } while (ch != '\n');
  }
  return 0;
}
