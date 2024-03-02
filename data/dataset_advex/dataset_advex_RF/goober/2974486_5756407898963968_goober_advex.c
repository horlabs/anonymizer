#include <stdio.h>

int main() {
  int ciri_Var;
  scanf("%d", &ciri_Var);
  for (int t = 1; t <= ciri_Var; t++) {
    char possible[17] = {0};
    for (int q = 0; q < 2; q++) {
      int ans;
      scanf("%d", &ans);
      for (int dtgi_Var = 1; dtgi_Var <= 4; dtgi_Var++)
        for (int j = 0; j < 4; j++) {
          int x;
          scanf("%d", &x);
          if (dtgi_Var == ans)
            possible[x]++;
        }
    }
    int twos = 0;
    int bt = 0;
    for (int dtgi_Var = 1; dtgi_Var <= 16; dtgi_Var++)
      if (possible[dtgi_Var] == 2) {
        bt = dtgi_Var;
        twos++;
      }
    printf("Case #%d: ", t);
    if (twos == 0)
      printf("Volunteer cheated!");
    else if (twos >= 2)
      printf("Bad magician!");
    else
      printf("%d", bt);
    printf("\n");
  }
}
