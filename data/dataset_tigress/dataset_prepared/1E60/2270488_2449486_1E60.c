#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t, T;
  int M, N;
  int x, y;
  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
    scanf("%d %d\n", &N, &M);
    int Goal[M][100], Board[M][100];
    for (y = 0; y < N; y++) {
      for (x = 0; x < M; x++) {
        scanf("%d ", &Goal[x][y]);
        Board[x][y] = 100;
      }
    }

    for (y = 0; y < N; y++) {
      int setting = 0;
      for (x = 0; x < M; x++) {
        if (setting < Goal[x][y]) {
          setting = Goal[x][y];
        }
      }
      for (x = 0; x < M; x++) {
        if (setting < Board[x][y]) {
          Board[x][y] = setting;
        }
      }
    }

    for (x = 0; x < M; x++) {
      int setting = 0;
      for (y = 0; y < N; y++) {
        if (setting < Goal[x][y]) {
          setting = Goal[x][y];
        }
      }
      for (y = 0; y < N; y++) {
        if (setting < Board[x][y]) {
          Board[x][y] = setting;
        }
      }
    }

    int possible = 1;
    for (y = 0; y < N; y++) {
      for (x = 0; x < M; x++) {
        if (Board[x][y] != Goal[x][y])
          possible = 0;
      }
    }
    printf("Case #%d: %s\n", t, (possible) ? "YES" : "NO");
  }
  return 0;
}
