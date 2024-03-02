#include "superheader.h"

int an;
int grid[101][101];

int isValid1[101];
int isValid2[101];

void find(int *ar) {
  int i;
  for (i = 1; i <= 16; i++) {
    ar[i] = 0;
  }
  for (i = 0; i < 4; i++) {
    ar[grid[an - 1][i]] = 1;
  }
}

void handle() {
  int i, j;
  scanf("%d ", &an);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }
  find(isValid1);
  scanf("%d ", &an);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%d ", &grid[i][j]);
    }
  }
  find(isValid2);
  int found = 0;
  int mult = 0;
  int ans = 0;
  for (i = 1; i <= 16; i++) {
    if (isValid1[i] && isValid2[i]) {
      if (found) {
        mult = 1;
      }
      found = 1;
      ans = i;
    }
  }
  if (!found) {
    printf("Volunteer cheated!\n");
  } else if (mult) {
    printf("Bad magician!\n");
  } else {
    printf("%d\n", ans);
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
  scanf("%d ", &t);
  for (i = 0; i < t; i++) {
    printf("Case #%d: ", i + 1);
    handle();
  }
  return 0;
}
