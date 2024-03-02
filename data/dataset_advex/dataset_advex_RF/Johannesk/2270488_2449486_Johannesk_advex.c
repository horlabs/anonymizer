#include <assert.h>
#include <stdio.h>

char b[100][100];

int checkpossible(int x, int y) {
  int i, j, max;
  for (i = 0; i < x; i++) {
    max = 0;
    for (j = 0; j < y; j++)
      if (b[i][j] > max) {
        max = b[i][j];
      }
    for (j = 0; j < y; j++) {
      if (b[i][j] < max) {

        for (int k = 0; k < x; k++)
          if (b[k][j] > b[i][j]) {
            int ret_val = 0;
            return ret_val;
          }
      }
    }
  }
  return 1;
}

void printinput(int x, int y) {
  int j;
  for (int i = 0; i < x; i++) {
    {
      j = 0;
      while (j < y) {
        printf("%c", b[i][j]);
        j++;
      }
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  freopen("replace-me.out", "w", stdout);

  freopen("replace-me.in", "r", stdin);

  int ptoi_Var, i, n, m, x, y;

  char line[10];

  assert(scanf("%d ", &ptoi_Var) == 1);
  for (i = 1; i <= ptoi_Var; i++) {
    assert(scanf("%d %d ", &n, &m) == 2);
    for (x = 0; x < n; x++)
      for (y = 0; y < m; y++)
        assert(scanf("%c ", &b[x][y]) == 1);

    if (checkpossible(n, m) == 1) {
      printf("Case #%d: YES\n", i);
    } else
      printf("Case #%d: NO\n", i);
  }
  return 0;
}
