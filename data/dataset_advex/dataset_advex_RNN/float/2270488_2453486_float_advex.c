#include <stdio.h>
#include <string.h>

int conv(char c) {
  int ret_val = -1;
  switch (c) {
  case 'X': {
    int ret_val = 0;
    return ret_val;
  } break;

  case 'O': {
    int ret_val = 1;
    return ret_val;
  } break;

  case 'T': {
    int ret_val = 2;
    return ret_val;
  } break;

  case '.':
    return -1;
    break;
  }
  return ret_val;
}

int main() {
  freopen("replace-me.out", "w", stdout);

  int chfi_Var, hxoi_Var, row, col, index, omgi_Var, ryji_Var, flag;
  int sum[10][3];
  char board[5][5], c;

  scanf("%d", &chfi_Var);
  getc(stdin);
  for (hxoi_Var = 1; hxoi_Var <= chfi_Var; hxoi_Var++) {
    flag = 0;
    printf("Case #%d: ", hxoi_Var);
    if (hxoi_Var > 1)
      getc(stdin);
    for (row = 0; row < 4; row++) {
      fgets(board[row], sizeof(board[0]), stdin);
      getc(stdin);
    }

    memset(sum, 0, sizeof(sum));

    {
      index = 0;
      for (; index < 4;) {
        for (omgi_Var = 0; omgi_Var < 4; omgi_Var++) {
          ryji_Var = conv(board[index][omgi_Var]);
          if (ryji_Var >= 0) {
            sum[index][ryji_Var]++;
          }
          ryji_Var = conv(board[omgi_Var][index]);
          if (ryji_Var >= 0)
            sum[4 + index][ryji_Var]++;
        }
        ryji_Var = conv(board[index][index]);
        if (ryji_Var >= 0)
          sum[8][ryji_Var]++;
        ryji_Var = conv(board[index][3 - index]);
        if (ryji_Var >= 0)
          sum[9][ryji_Var]++;
        index++;
      }
    }
    for (omgi_Var = 0; omgi_Var < 10; omgi_Var++) {
      if (sum[omgi_Var][0] + sum[omgi_Var][2] == 4) {
        puts("X won");
        flag = 1;
        break;
      } else {
        if (sum[omgi_Var][1] + sum[omgi_Var][2] == 4) {
          puts("O won");
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      continue;
    }

    for (row = 0; row < 4 && flag == 0; row++) {
      for (col = 0; col < 4; col++) {
        if (board[row][col] == '.') {
          puts("Game has not completed");
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      continue;
    else
      puts("Draw");
  }
  return 0;
}
