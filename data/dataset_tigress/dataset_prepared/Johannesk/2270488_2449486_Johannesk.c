#include "superheader.h"

char b[100][100];

int checkpossible(int x, int y) {
  int i, j, k, max;
  for (i = 0; i < x; i++) {
    max = 0;
    for (j = 0; j < y; j++)
      if (b[i][j] > max)
        max = b[i][j];
    for (j = 0; j < y; j++) {
      if (b[i][j] < max) {

        for (k = 0; k < x; k++)
          if (b[k][j] > b[i][j])
            return 0;
      }
    }
  }
  return 1;
}

void printinput(int x, int y) {
  int i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
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
  int t, i, n, m, x, y;

  char line[10];

  (scanf("%d ", &t) == 1);
  for (i = 1; i <= t; i++) {
    (scanf("%d %d ", &n, &m) == 2);
    for (x = 0; x < n; x++)
      for (y = 0; y < m; y++)
        (scanf("%c ", &b[x][y]) == 1);

    if (checkpossible(n, m) == 1)
      printf("Case #%d: YES\n", i);
    else
      printf("Case #%d: NO\n", i);
  }
  return 0;
}
