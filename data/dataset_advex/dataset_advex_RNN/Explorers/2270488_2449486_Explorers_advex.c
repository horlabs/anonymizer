#include <stdio.h>

int main() {
  int jffi_Var;
  int duai_Var, k, j;
  char *res[100];
  int data[10][10];
  int row, col;
  int flagNo = 0;

  scanf("%d", &jffi_Var);

  for (duai_Var = 0; duai_Var < jffi_Var; duai_Var++) {
    flagNo = 0;
    scanf("%d %d", &row, &col);

    for (j = 0; j < row; j++) {
      for (k = 0; k < col; k++)
        scanf("%d", &data[j][k]);
    }

    for (j = 0; j < row; j++) {
      for (k = 0; k < col; k++) {
        if (data[j][k] == 1) {
          if (horizCheck(j, k, row, col, data) == 1 ||
              vertCheck(j, k, row, col, data) == 1)
            continue;
          else {
            flagNo = 1;
            break;
          }
        }
      }
      if (flagNo == 1)
        break;
    }

    if (flagNo == 1)
      res[duai_Var] = "NO";
    else
      res[duai_Var] = "YES";
  }

  for (duai_Var = 0; duai_Var < jffi_Var; duai_Var++)
    printf("Case #%d: %s\n", duai_Var + 1, res[duai_Var]);
}

int horizCheck(int r, int c, int row, int col, int data[10][10]) {
  int duai_Var;

  for (duai_Var = 0; duai_Var < col; duai_Var++) {
    if (data[r][duai_Var] != 1)
      return 0;
  }
  return 1;
}

int vertCheck(int r, int c, int row, int col, int data[10][10]) {
  int duai_Var;

  for (duai_Var = 0; duai_Var < row; duai_Var++) {
    if (data[duai_Var][c] != 1)
      return 0;
  }
  return 1;
}
