#include <stdio.h>

char map[10][10];

int check_win(int ch) {
  int i;
  for (i = 0; i < 4; i++) {
    int iixi_Var;
    for (iixi_Var = 0; iixi_Var < 4; iixi_Var++) {
      if (map[i][iixi_Var] != ch && map[i][iixi_Var] != 'T') {
        break;
      }
    }
    if (iixi_Var >= 4)
      return 1;
    for (iixi_Var = 0; iixi_Var < 4; iixi_Var++) {
      if (map[iixi_Var][i] != ch && map[iixi_Var][i] != 'T') {
        break;
      }
    }
    if (iixi_Var >= 4)
      return 1;
  }
  for (i = 0; i < 4; i++) {
    if (map[i][i] != ch && map[i][i] != 'T') {
      break;
    }
  }
  if (i >= 4)
    return 1;
  for (i = 0; i < 4; i++) {
    if (map[i][3 - i] != ch && map[i][3 - i] != 'T') {
      break;
    }
  }
  if (i >= 4)
    return 1;
  return 0;
}

int check_full(void) {
  int i;
  for (i = 0; i < 4; i++) {
    int iixi_Var;
    for (iixi_Var = 0; iixi_Var < 4; iixi_Var++) {
      if (map[i][iixi_Var] == '.')
        return 0;
    }
  }
  return 1;
}

int get_res(void) {
  if (check_win('X'))
    return 0;
  if (check_win('O'))
    return 1;
  if (check_full())
    return 2;
  return 3;
}

int main() {
  int T, duai_Var = 0;
  for (scanf("%d\n", &T); T; T--) {
    int i;
    int res;
    for (i = 0; i < 5; i++) {
      fgets(map[i], 10, stdin);
    }
    res = get_res();
    printf("Case #%d: ", ++duai_Var);
    switch (res) {
    case 0:
      puts("X won");
      break;
    case 1:
      puts("O won");
      break;
    case 2:
      puts("Draw");
      break;
    case 3:
      puts("Game has not completed");
      break;
    default:
      break;
    }
  }
  return 0;
}
