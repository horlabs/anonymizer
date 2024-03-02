#include "superheader.h"

void readline() {
  while (getchar() != '\n')
    ;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, tcase;
  char ch, map[] = "yhesocvxduiglbkrztnwjpfmaq";

  scanf("%d", &T);
  readline();
  for (tcase = 1; tcase <= T; tcase++) {
    printf("Case #%d: ", tcase);
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
