#include "superheader.h"

char map[] = "yhesocvxduiglbkrztnwjpfmaq";

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  scanf("%d ", &T);
  for (int t = 1; t <= T; t++) {
    char buf[101];
    gets(buf);
    for (int i = 0; buf[i]; i++)
      if (buf[i] >= 'a' && buf[i] <= 'z')
        buf[i] = map[buf[i] - 'a'];
    printf("Case #%d: %s\n", t, buf);
  }
  return 0;
}
