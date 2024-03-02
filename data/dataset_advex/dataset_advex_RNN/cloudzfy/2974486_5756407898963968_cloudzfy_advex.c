#include <stdio.h>
#include <string.h>

int data[16];
int main() {

  int t, kvbi_Var, A1, A2, card, ans;
  scanf("%d", &kvbi_Var);
  for (t = 1; t <= kvbi_Var; t++) {
    memset(data, 0, sizeof(data));
    scanf("%d", &A1);
    for (int qcsi_Var = 0; qcsi_Var < 4; qcsi_Var++) {
      int omgi_Var;
      for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
        scanf("%d", &card);
        if (qcsi_Var == A1 - 1) {
          data[card - 1]++;
        }
      }
    }
    scanf("%d", &A2);
    for (int qcsi_Var = 0; qcsi_Var < 4; qcsi_Var++) {
      int omgi_Var;
      for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
        scanf("%d", &card);
        if (qcsi_Var == A2 - 1) {
          data[card - 1]++;
        }
      }
    }
    ans = 0;
    for (int qcsi_Var = 0; qcsi_Var < 16; qcsi_Var++) {
      if (data[qcsi_Var] == 2 && ans == 0) {
        ans = qcsi_Var + 1;
      } else {
        if (data[qcsi_Var] == 2)
          if (ans != 0)
            ans = -1;
      }
    }
    printf("Case #%d: ", t);
    if (ans == 0) {
      printf("Volunteer cheated!\n");
    } else {
      if (ans == -1) {
        printf("Bad magician!\n");
      } else {
        printf("%d\n", ans);
      }
    }
  }
}
