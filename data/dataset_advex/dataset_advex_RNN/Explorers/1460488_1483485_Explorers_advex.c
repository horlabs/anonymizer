#include <stdio.h>
#include <string.h>

int main() {
  int iixi_Var, duai_Var, j, len;
  char str[30][105];
  char output[30][105];
  int mapping[] = {25, 8,  5,  19, 15, 3,  22, 24, 4,  21, 9,  7, 12,
                   2,  11, 18, 26, 20, 14, 23, 10, 16, 6,  13, 1, 17};

  scanf("%d ", &iixi_Var);
  for (duai_Var = 0; duai_Var < iixi_Var; duai_Var++) {
    gets(str[duai_Var]);
    len = strlen(str[duai_Var]);
    for (j = 0; j < len; j++) {
      if (str[duai_Var][j] == ' ')
        continue;
      str[duai_Var][j] = 96 + mapping[str[duai_Var][j] - 'a'];
    }
  }

  for (duai_Var = 0; duai_Var < iixi_Var; duai_Var++) {
    printf("Case #%d: ", duai_Var + 1);
    puts(str[duai_Var]);
  }
}
