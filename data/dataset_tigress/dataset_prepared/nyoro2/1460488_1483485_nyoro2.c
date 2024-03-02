#include "superheader.h"

char letter_map[] = {

    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u',

    'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w',

    'j', 'p', 'f', 'm', 'a', 'q'};

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  char cbuf[128];
  char *p;

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {
    fgets(cbuf, 120, stdin);

    printf("Case #%d: ", i + 1);
    p = cbuf;
    while (*p) {

      if (*p == ' ')
        printf(" ");
      else if ((*p >= 'a') && (*p <= 'z')) {
        printf("%c", letter_map[*p - 'a']);
      }
      p++;
    }
    printf("\n");
  }

  return 0;
}
