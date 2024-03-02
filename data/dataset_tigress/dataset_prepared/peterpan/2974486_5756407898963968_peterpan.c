#include "superheader.h"
void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T, tcase, i, j, jj, counter, resj, r1, r2, arr1[4][4], arr2[4][4];

  scanf("%d", &T);
  for (tcase = 1; tcase <= T; tcase++) {
    scanf("%d", &r1);
    r1--;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        scanf("%d", &(arr1[i][j]));
    scanf("%d", &r2);
    r2--;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        scanf("%d", &(arr2[i][j]));
    counter = 0;
    resj = -1;
    for (j = 0; j < 4; j++)
      for (jj = 0; jj < 4; jj++)
        if (arr1[r1][j] == arr2[r2][jj]) {
          counter++;
          resj = j;
        }
    printf("Case #%d: ", tcase);
    if (counter == 1)
      printf("%d\n", arr1[r1][resj]);
    else
      printf("%s\n", counter ? "Bad magician!" : "Volunteer cheated!");
  }

  return 0;
}
