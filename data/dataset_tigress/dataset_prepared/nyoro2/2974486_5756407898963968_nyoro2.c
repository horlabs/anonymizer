#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int ans[2];
  int board_ptn[2][4][4];
  int i, j, k, l;
  int num_match;
  int match_fig;

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {

    for (j = 0; j < 2; j++) {
      scanf("%d\n", ans + j);
      for (k = 0; k < 4; k++) {
        scanf("%d %d %d %d\n", board_ptn[j][k], board_ptn[j][k] + 1,
              board_ptn[j][k] + 2, board_ptn[j][k] + 3);
      }
    }
    num_match = 0;
    for (k = 0; k < 4; k++) {
      int tmp;
      tmp = board_ptn[0][ans[0] - 1][k];
      for (l = 0; l < 4; l++) {
        if (tmp == board_ptn[1][ans[1] - 1][l]) {
          match_fig = tmp;
          num_match++;
        }
      }
    }

    printf("Case #%d: ", i + 1);
    switch (num_match) {
    case 0:
      printf("Volunteer cheated!\n");
      break;
    case 1:
      printf("%d\n", match_fig);
      break;
    default:
      printf("Bad magician!\n");
      break;
    }
  }

  return 0;
}
