#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int set[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
               'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
  int c;
  int cases, i;
  cases = 0;
  while ((c = getchar()) != '\n') {
    cases *= 10;
    cases += c - '0';
  }
  for (i = 1; i <= cases; i++) {
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
