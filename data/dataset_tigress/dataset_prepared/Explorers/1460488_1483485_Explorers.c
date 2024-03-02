#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int ntest, i, j, len;
  char str[30][105];
  char output[30][105];
  int mapping[] = {25, 8,  5,  19, 15, 3,  22, 24, 4,  21, 9,  7, 12,
                   2,  11, 18, 26, 20, 14, 23, 10, 16, 6,  13, 1, 17};

  scanf("%d ", &ntest);
  for (i = 0; i < ntest; i++) {
    gets(str[i]);
    len = strlen(str[i]);
    for (j = 0; j < len; j++) {
      if (str[i][j] == ' ')
        continue;
      str[i][j] = 96 + mapping[str[i][j] - 'a'];
    }
  }

  for (i = 0; i < ntest; i++) {
    printf("Case #%d: ", i + 1);
    puts(str[i]);
  }
}
