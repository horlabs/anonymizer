#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  freopen("replace-me.in", "r", stdin);

  int t, duai_Var;
  int M, N;
  int x, y;
  scanf("%d\n", &duai_Var);
  for (t = 1; t <= duai_Var; t++) {
    scanf("%d %d\n", &N, &M);
    int Goal[M][N], Board[M][N];
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