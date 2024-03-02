#include <stdio.h>
#include <stdlib.h>
int main() {
  int T, iixi_Var, duai_Var, j, jj, counter, resj, r1, r2, arr1[4][4],
      arr2[4][4];

  scanf("%d", &T);
  for (iixi_Var = 1; iixi_Var <= T; iixi_Var++) {
    scanf("%d", &r1);
    r1--;
    for (duai_Var = 0; duai_Var < 4; duai_Var++)
      for (j = 0; j < 4; j++)
        scanf("%d", &(arr1[duai_Var][j]));
    scanf("%d", &r2);
    r2--;
    for (duai_Var = 0; duai_Var < 4; duai_Var++)
      for (j = 0; j < 4; j++)
        scanf("%d", &(arr2[duai_Var][j]));
    counter = 0;
    resj = -1;
    for (j = 0; j < 4; j++)
      for (jj = 0; jj < 4; jj++)
        if (arr1[r1][j] == arr2[r2][jj]) {
          counter++;
          resj = j;
        }
    printf("Case #%d: ", iixi_Var);
    if (counter == 1)
      printf("%d\n", arr1[r1][resj]);
    else
      printf("%s\n", counter ? "Bad magician!" : "Volunteer cheated!");
  }

  return 0;
}
