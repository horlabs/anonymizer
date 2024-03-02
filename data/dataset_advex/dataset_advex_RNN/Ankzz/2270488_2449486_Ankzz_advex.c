#include <stdio.h>

int main() {
  int T = -1;
  int c = 0;
  char dummy[100];

  FILE *duaF_Var = fopen("B-small-attempt3.in", "r");

  FILE *fo = fopen("output.txt", "w");

  fscanf(duaF_Var, "%d", &T);

  while (++c <= T) {
    int x, y;
    int i, j;
    short sane = 1;
    int m[100][100];
    fscanf(duaF_Var, "%d %d", &x, &y);

    for (i = 0; i < x; i++) {
      int prev = -1;
      for (j = 0; j < y; j++) {
        int p;
        fscanf(duaF_Var, "%d", &p);
        m[i][j] = p;
        if (sane) {
          if (prev == -1)
            prev = p;
          else {
            if (i != 0 && j != 0 && i != x - 1 && j != y - 1 && p < prev) {
              sane = 0;
            }
          }
        }
      }
    }

    if (sane) {
      for (i = 0; i < x; i++) {
        int prev = -1;
        for (j = 0; j < y; j++) {
          int p = m[j][i];
          if (prev == -1)
            prev = p;
          else {
            if (i != 0 && j != 0 && i != x - 1 && j != y - 1 && p < prev) {
              sane = 0;
              break;
            }
          }
        }
      }
    }

    if (sane) {
      int prev = -1;
      i = 0;
      {
        for (j = 0; j < y; j++) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = i;
              for (; k < x; k++) {
                if (m[k][j] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }

      if (sane) {
        j--;
        for (; i < x; i++) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = j;
              for (; k >= 0; k--) {
                if (m[i][k] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }

      if (sane) {
        i--;
        for (; j >= 0; j--) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = i;
              for (; k >= 0; k--) {
                if (m[k][j] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }

      if (sane) {
        j = 0;
        for (; i > 0; i--) {
          int p = m[i][j];

          if (prev == -1)
            prev = p;
          else {
            if (prev != p) {
              int k = j;
              for (; k < y; k++) {
                if (m[i][k] != p) {
                  sane = 0;
                  break;
                }
              }
            }
          }
        }
      }
    }

    fprintf(fo, "Case #%d: %s\n", c, (sane) ? "YES" : "NO");
  }

  return 0;
}
