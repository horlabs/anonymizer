#include "superheader.h"
int data[100][100];
int N, M;

int check(int x, int y) {
  int i, j;
  int t = data[x][y];
  int result = 1;

  for (i = 0; i < N; ++i) {
    if (t < data[i][y]) {
      result = 0;
      break;
    }
  }
  if (result)
    return 1;

  for (i = 0; i < M; ++i) {
    if (t < data[x][i]) {
      return 0;
    }
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
  int num;
  int i, j, k;
  int result;

  scanf("%d", &num);
  for (i = 1; i <= num; ++i) {
    scanf("%d %d", &N, &M);
    for (j = 0; j < N; ++j) {
      for (k = 0; k < M; ++k) {
        scanf("%d", &(data[j][k]));
      }
    }

    result = 1;

    for (j = 0; j < N; ++j) {
      for (k = 0; k < M; ++k) {
        if (!check(j, k)) {
          result = 0;
          goto LAST;
        }
      }
    }
  LAST:
    printf("Case #%d: ", i);
    if (result) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
