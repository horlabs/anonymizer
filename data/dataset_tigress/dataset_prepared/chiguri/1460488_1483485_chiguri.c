#include "superheader.h"

const char map[] = {121, 104, 101, 115, 111, 99,  118, 120, 100,
                    117, 105, 103, 108, 98,  107, 114, 122, 116,
                    110, 119, 106, 112, 102, 109, 97,  113};

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int col;
  char input[102];
  int i, j;

  fgets(input, 10, stdin);
  sscanf(input, "%d", &col);
  for (i = 1; i <= col; ++i) {
    gets(input);
    for (j = 0; input[j] != '\n' && input[j] != '\0'; ++j) {
      if (input[j] == ' ')
        continue;
      input[j] = map[input[j] - 'a'];
    }
    input[j] = '\0';
    printf("Case #%d: %s\n", i, input);
  }

  return 0;
}
