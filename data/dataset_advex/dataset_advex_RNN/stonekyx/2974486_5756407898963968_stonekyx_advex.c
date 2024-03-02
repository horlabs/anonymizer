#include <stdio.h>
#include <string.h>

int main() {
  int ynli_Var, jqhi_Var = 0;
  for (scanf("%d", &ynli_Var); ynli_Var; ynli_Var--) {
    int row1, row2;
    static int map1[4][4], map2[4][4];
    static int count[16];
    int ans;
    int i;
    scanf("%d", &row1);
    for (i = 0; i < 4; i++) {
      int j;
      for (j = 0; j < 4; j++) {
        scanf("%d", map1[i] + j);
      }
    }
    scanf("%d", &row2);
    for (i = 0; i < 4; i++) {
      int j;
      for (j = 0; j < 4; j++) {
        scanf("%d", map2[i] + j);
      }
    }
    memset(count, 0, sizeof(count));
    for (i = 0; i < 4; i++) {
      count[map1[row1 - 1][i] - 1]++;
      count[map2[row2 - 1][i] - 1]++;
    }
    ans = -1;
    for (i = 0; i < 16; i++) {
      if (count[i] == 2) {
        if (ans != -1) {
          ans = -2;
          break;
        }
        ans = i;
      }
    }
    printf("Case #%d: ", ++jqhi_Var);
    if (ans == -1)
      puts("Volunteer cheated!");
    else if (ans == -2)
      puts("Bad magician!");
    else
      printf("%d\n", ans + 1);
  }
  return 0;
}
