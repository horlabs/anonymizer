#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_voiztj_fct(int t) {
  int n, m;
  int a[100][100];
  int i, j;
  int failed = 1;

  scanf("%d%d", &n, &m);

  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &a[i][j]);

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int ii;

      for (ii = 0; ii < n; ii++) {
        if (a[i][j] < a[ii][j]) {

          int jj;

          for (jj = 0; jj < m; jj++) {
            if (a[i][j] < a[i][jj])
              goto done;
          }
          break;
        }
      }
    }
  }

  failed = 0;
done:

  printf("Case #%d: %s\n", t + 1, failed ? "NO" : "YES");
}

int main() {
  int t, i;

  scanf("%d", &t);

  for (i = 0; i < t; i++)
    do_voiztj_fct(i);

  return 0;
}