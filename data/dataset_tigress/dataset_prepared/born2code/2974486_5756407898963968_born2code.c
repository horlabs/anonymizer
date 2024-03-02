#include "superheader.h"

void intersec(int A[4], int B[4]) {
  int i, j, k, n = 0, x, y;
  for (i = 0; i < 4; i++) {
    x = A[i];
    for (j = 0; j < 4; j++) {
      if (x == B[j]) {
        y = x;
        n++;
      }
    }
  }
  if (n == 1)
    printf("%d", y);
  if (n > 1)
    printf("Bad magician!");
  if (n == 0)
    printf("Volunteer cheated!");
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, n1, n2, A[4], B[4], t, j, k, l, i;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    scanf("%d", &n1);
    k = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &l);
        if (i == n1 - 1) {
          A[k++] = l;
        }
      }
    }
    scanf("%d", &n1);
    k = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", &l);
        if (i == n1 - 1) {
          B[k++] = l;
        }
      }
    }
    printf("Case #%d: ", t);
    intersec(A, B);
    printf("\n");
  }
  return 0;
}
