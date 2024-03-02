#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  char s[26] = "yhesocvxduiglbkrztnwjpfmaq";
  char d[105], e[105];
  int n, v, i, j, l;

  (scanf("%d ", &n) == 1);
  for (i = 1; i <= n; i++) {
    (fgets(d, 105, stdin) != NULL);
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
