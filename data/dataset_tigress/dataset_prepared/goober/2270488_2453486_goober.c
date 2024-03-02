#include "superheader.h"

char a[4][5];

int check(char c) {
  int cnt;

  cnt = 0;
  for (int i = 0; i < 4; i++)
    cnt += (a[i][i] == c || a[i][i] == 'T');
  if (cnt == 4)
    return 1;

  cnt = 0;
  for (int i = 0; i < 4; i++)
    cnt += (a[i][3 - i] == c || a[i][3 - i] == 'T');
  if (cnt == 4)
    return 1;

  for (int i = 0; i < 4; i++) {
    cnt = 0;
    for (int j = 0; j < 4; j++)
      cnt += (a[i][j] == c || a[i][j] == 'T');
    if (cnt == 4)
      return 1;

    cnt = 0;
    for (int j = 0; j < 4; j++)
      cnt += (a[j][i] == c || a[j][i] == 'T');
    if (cnt == 4)
      return 1;
  }
  return 0;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 4; i++)
      scanf("%s", &a[i]);
    const char *msg = "Draw";
    if (check('X'))
      msg = "X won";
    else if (check('O'))
      msg = "O won";
    else {
      int cnt = 0;
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
          if (a[i][j] == '.')
            cnt++;
      if (cnt > 0)
        msg = "Game has not completed";
    }

    printf("Case #%d: %s\n", t, msg);
  }
}
