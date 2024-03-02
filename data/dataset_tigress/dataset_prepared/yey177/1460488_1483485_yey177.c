#include "superheader.h"

char u[28] = "yhesocvxduiglbkrztnwjpfmaq";

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int n, i, k;
  char s[108];
  scanf("%d", &n);
  gets(s);
  for (k = 1; k <= n; k++) {
    gets(s);
    printf("Case #%d: ", k);
    for (i = 0; s[i]; i++)
      putchar(s[i] == 32 ? s[i] : u[(int)(s[i] - 'a')]);
    puts("");
  }
  return 0;
}
