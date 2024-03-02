#include "superheader.h"

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  freopen("A-small-attempt0.in", "r", stdin);

  int testcase = 0;
  int testcases;

  scanf("%d\n", &testcases);

  while (testcase < testcases) {
    int answer;
    int cards[4];
    int row;
    int found;
    int card, theCard;

    scanf("%d\n", &answer);
    for (row = 1; row <= 4; row++) {
      if (row == answer) {
        scanf("%d %d %d %d", &cards[0], &cards[1], &cards[2], &cards[3]);
      } else {
        scanf("%*d %*d %*d %*d");
      }
    }

    scanf("%d\n", &answer);
    for (row = 1; row <= 4; row++) {
      if (row == answer) {
        int i, j;

        for (found = 0, i = 0; i < 4; i++) {
          scanf("%d", &card);

          for (j = 0; j < 4; j++) {
            if (card == cards[j]) {
              found++, theCard = card;
            }
          }
        }
      } else {
        scanf("%*d %*d %*d %*d");
      }
    }

    switch (found) {
    case 0:
      printf("Case #%d: %s\n", ++testcase, "Volunteer cheated!");
      break;
    case 1:
      printf("Case #%d: %d\n", ++testcase, theCard);
      break;
    default:
      printf("Case #%d: %s\n", ++testcase, "Bad magician!");
      break;
    }
  }

  return 0;
}
