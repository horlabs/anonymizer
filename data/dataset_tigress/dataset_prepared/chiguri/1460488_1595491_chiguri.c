#include "superheader.h"

char input[400];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int col;
  int num;
  int sup_num;
  int score;
  int result;
  int sup_require_num;
  int i, j;
  int temp;

  scanf("%d", &col);

  for (i = 1; i <= col; ++i) {
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
      } else if (score * 3 - 2 <= temp) {
        ++result;
      } else if (score * 3 - 4 <= temp) {
        ++sup_require_num;
      }
    }
    if (sup_num > sup_require_num) {
      result += sup_require_num;
    } else {
      result += sup_num;
    }

    printf("Case #%d: %d\n", i, result);
  }

  return 0;
}
