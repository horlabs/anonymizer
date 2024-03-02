#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  char c[26] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k',
                'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p',
                'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'},
       i, j, ch, cs = 0, T;
  FILE *f1, *f2;
  f1 = fopen("A-small-attempt1.in", "r");
  f2 = fopen("output.txt", "w");
  fscanf(f1, "%d", &T);
  while ((ch = getc(f1)) != EOF) {
    if (ch == '\n') {
      cs++;
      if (cs != 1)
        putc(ch, f2);
      if (cs != T + 1)
        fprintf(f2, "Case #%d: ", cs);
    }

    if (ch == ' ')
      putc(ch, f2);
    else {
      for (i = 0; i < 26; i++) {
        if (ch == c[i])
          putc((i + 'a'), f2);
      }
    }
  }
  fclose(f1);
  fclose(f2);
  return 0;
}
