#include "superheader.h"

int equal(int a[100][100], int b[100][100], int n, int m) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (a[i][j] != b[i][j])
        return 0;
    }
  return 1;
}
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T1, T, n, m, i, j, max = 0, x;
  int a[100][100], b[100][100];
  T = 1;
  for (scanf("%d", &T1); T <= T1; T++) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        if (a[i][j] > max)
          max = a[i][j];
      }
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        b[i][j] = max;
    for (i = 0; i < n; i++) {
      x = a[i][0];
      {
        j = 1;
        while (a[i][j] == x && j < m) {
          j++;
        }
        if (j == m)
          for (j = 0; j < m; j++)
            b[i][j] = x;
      }
    }
    for (j = 0; j < m; j++) {
      x = a[0][j];
      {
        i = 1;
        while (a[i][j] == x && i < n)
          i++;
        if (i == n)
          for (i = 0; i < n; i++)
            b[i][j] = x;
      }
    }

    printf("Case #%d: ", T);
    if (equal(a, b, n, m)) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
  return 0;
}
