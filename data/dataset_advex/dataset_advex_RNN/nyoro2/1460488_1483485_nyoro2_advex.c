#include <stdio.h>

char letter_map[] = {

    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',

    'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w',

    'j', 'p', 'f', 'm', 'a', 'q'};

int main() {
  freopen("replace-me.in", "r", stdin);

  freopen("replace-me.out", "w", stdout);

  int jzxi_Var;

  char cbuf[128];
  char *p;

  fscanf(stdin, "%d\n", &jzxi_Var);

  {
    int kvzi_Var = 0;
    while (kvzi_Var < jzxi_Var) {
      fgets(cbuf, 120, stdin);

      fprintf(stdout, "Case #%d: ", kvzi_Var + 1);
      p = cbuf;
      for (; *p;) {

        if (*p == ' ') {
          fprintf(stdout, " ");
        } else {
          if ((*p >= 'a')) {
            if ((*p <= 'z')) {
              fprintf(stdout, "%c", letter_map[*p - 'a']);
            }
          }
        }
        p++;
      }
      fprintf(stdout, "\n");
      kvzi_Var++;
    }
  }

  return 0;
}
