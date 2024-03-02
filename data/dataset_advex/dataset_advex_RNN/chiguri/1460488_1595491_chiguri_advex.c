#include <stdio.h>

char input[400];

int main(void) {
  freopen("replace-me.in", "r", stdin);

  int col;
  int num;
  int sup_num;
  int score;
  int result;
  int sup_require_num;
  int sjbi_Var, j;
  int temp;

  scanf("%d", &col);

  for (sjbi_Var = 1; sjbi_Var <= col; ++sjbi_Var) {
    result = 0;
    sup_require_num = 0;

    scanf("%d %d %d", &num, &sup_num, &score);
    for (j = 0; j < num; ++j) {
      scanf("%d", &temp);
      if (temp == 0) {
        if (score == 0) {
          ++result;
        }
      } else if (temp == 1) {
        if (score <= 1) {
          ++result;
        }
      } else {
        if (score * 3 - 2 <= temp) {
          ++result;
        } else if (score * 3 - 4 <= temp) {
          ++sup_require_num;
        }
      }
    }
    if (sup_num > sup_require_num) {
      result += sup_require_num;
    } else {
      result += sup_num;
    }

    printf("Case #%d: %d\n", sjbi_Var, result);
  }

  return 0;
}
