#include <stdio.h>
#include <stdlib.h>

void do_voizbu_fct();

int h, w;

int grid[100][100];

int doesWork(int y, int x);

int main() {
  freopen("bin.txt", "r", stdin);
  freopen("bout.txt", "w", stdout);
  int n;
  scanf("%d ", &n);

  for (int i = 0; i < n; i++) {
    printf("Case #%d: ", i + 1);
    do_voizbu_fct();
  }
  return 0;
}

void do_voizbu_fct() {
  int i, j;
  scanf("%d %d ", &h, &w);
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++)
      scanf("%d ", &grid[i][j]);
  }
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      if (!doesWork(i, j)) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
}

int doesWork(int y, int x) {
  int num = grid[y][x];
  int i;
  int allLess = 1;
  for (i = 0; i < h && allLess; i++) {
    if (grid[i][x] > num) {
      allLess = 0;
    }
  }
  if (allLess) {
    return 1;
  }
  allLess = 1;
  for (i = 0; i < w && allLess; i++) {
    if (grid[y][i] > num) {
      allLess = 0;
    }
  }
  return allLess;
}
