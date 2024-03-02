#include <stdio.h>

char duac_Var[4][5];

int check(char c) {
  int cnt;

  cnt = 0;
  for (int i = 0; i < 4; i++)
    cnt += (duac_Var[i][i] == c || duac_Var[i][i] == 'T');
  if (cnt == 4)
    return 1;

  cnt = 0;
  for (int i = 0; i < 4; i++)
    cnt += (duac_Var[i][3 - i] == c || duac_Var[i][3 - i] == 'T');
  if (cnt == 4)
    return 1;

  for (int i = 0; i < 4; i++) {
    cnt = 0;
    for (int j = 0; j < 4; j++)
      cnt += (duac_Var[i][j] == c || duac_Var[i][j] == 'T');
    if (cnt == 4)
      return 1;

    cnt = 0;
    for (int j = 0; j < 4; j++)
      cnt += (duac_Var[j][i] == c || duac_Var[j][i] == 'T');
    if (cnt == 4)
      return 1;
  }
  return 0;
}

int main() {
  freopen("replace-me.in", "r", stdin);

  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 4; i++)
      scanf("%s", &duac_Var[i]);
    const char *msg = "Draw";
    if (check('X'))
      msg = "X won";
    else if (check('O'))
      msg = "O won";
    else {
      int cnt = 0;
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
          if (duac_Var[i][j] == '.')
            cnt++;
      if (cnt > 0)
        msg = "Game has not completed";
    }

    printf("Case #%d: %s\n", t, msg);
  }
}
