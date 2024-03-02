#include <stdio.h>

int main(void) {
  freopen("replace-me.in", "r", stdin);

  int set[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
               'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
  int c;
  int duai_Var, i;
  duai_Var = 0;
  while ((c = getchar()) != '\n') {
    duai_Var *= 10;
    duai_Var += c - '0';
  }
  for (i = 1; i <= duai_Var; i++) {
    printf("Case #%d: ", i);
    while (((c = getchar()) != '\n') && (c != EOF)) {

      if (c == ' ') {
        putchar(c);
      } else {
        putchar(set[c - 'a']);
      }
    }
    putchar(c);
  }
  return 0;
}
