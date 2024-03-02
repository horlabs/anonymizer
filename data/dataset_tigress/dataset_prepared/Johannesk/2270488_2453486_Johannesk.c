#include "superheader.h"

char b[4][4];

int checkwin(char s) {
  int i, j, c;
  for (i = 0; i < 4; i++) {
    c = 0;
    for (j = 0; j < 4; j++) {
      if ((b[i][j] == s) || (b[i][j] == 'T'))
        c++;
    }
    if (c == 4)
      return 1;
  }
  for (j = 0; j < 4; j++) {
    c = 0;
    for (i = 0; i < 4; i++) {
      if ((b[i][j] == s) || (b[i][j] == 'T'))
        c++;
    }
    if (c == 4)
      return 1;
  }

  c = 0;
  for (i = 0; i < 4; i++) {
    if ((b[i][i] == s) || (b[i][i] == 'T'))
      c++;
  }
  if (c == 4)
    return 1;

  c = 0;
  for (i = 0; i < 4; i++) {
    if ((b[3 - i][i] == s) || (b[3 - i][i] == 'T'))
      c++;
  }
  if (c == 4)
    return 1;

  return 0;
}

int checkdraw() {
  int i, j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (b[i][j] == '.')
        return 0;
    }
  }
  return 1;
}

void printinput() {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("%c", b[i][j]);
    }
    printf("\n");
  }
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, i;

  char line[10];

  (scanf("%d ", &t) == 1);
  for (i = 1; i <= t; i++) {
    (scanf("%c%c%c%c ", &b[0][0], &b[0][1], &b[0][2], &b[0][3]) == 4);
    (scanf("%c%c%c%c ", &b[1][0], &b[1][1], &b[1][2], &b[1][3]) == 4);
    (scanf("%c%c%c%c ", &b[2][0], &b[2][1], &b[2][2], &b[2][3]) == 4);
    (scanf("%c%c%c%c ", &b[3][0], &b[3][1], &b[3][2], &b[3][3]) == 4);

    if (checkwin('X'))
      printf("Case #%d: X won\n", i);
    else if (checkwin('O'))
      printf("Case #%d: O won\n", i);
    else if (checkdraw())
      printf("Case #%d: Draw\n", i);
    else
      printf("Case #%d: Game has not completed\n", i);
  }
  return 0;
}
