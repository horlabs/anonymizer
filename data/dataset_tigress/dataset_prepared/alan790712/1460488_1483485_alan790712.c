#include "superheader.h"

char str[1234567];
char trans[256];
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i, j;
  for (i = 0; i < 256; ++i) {
    trans[i] = i;
  }
  trans['a'] = 'y';
  trans['b'] = 'h';
  trans['c'] = 'e';
  trans['d'] = 's';
  trans['e'] = 'o';
  trans['f'] = 'c';
  trans['g'] = 'v';
  trans['h'] = 'x';
  trans['i'] = 'd';
  trans['j'] = 'u';
  trans['k'] = 'i';
  trans['l'] = 'g';
  trans['m'] = 'l';
  trans['n'] = 'b';
  trans['o'] = 'k';
  trans['p'] = 'r';
  trans['q'] = 'z';
  trans['r'] = 't';
  trans['s'] = 'n';
  trans['t'] = 'w';
  trans['u'] = 'j';
  trans['v'] = 'p';
  trans['w'] = 'f';
  trans['x'] = 'm';
  trans['y'] = 'a';
  trans['z'] = 'q';

  scanf("%d", &t);
  gets(str);

  for (i = 1; i <= t; ++i) {
    gets(str);
    printf("Case #%d: ", i);
    for (j = 0; str[j] != '\0'; ++j) {
      putchar(trans[str[j]]);
    }
    puts("");
  }

  return 0;
}
