#include <stdio.h>

int main(void) {

  int ret_val = 0;
  int yoni_Var = 0;
  int shqi_Var;
  scanf("%d\n", &shqi_Var);
  for (; yoni_Var < shqi_Var;) {
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
        int ewni_Var;

        for (found = 0, ewni_Var = 0; ewni_Var < 4; ewni_Var++) {
          scanf("%d", &card);

          for (int bfui_Var = 0; bfui_Var < 4; bfui_Var++) {
            if (card == cards[bfui_Var]) {
              found++, theCard = card;
            }
          }
        }
      } else
        scanf("%*d %*d %*d %*d");
    }

    switch (found) {
    case 0:
      printf("Case #%d: %s\n", ++yoni_Var, "Volunteer cheated!");
      break;
    case 1:
      printf("Case #%d: %d\n", ++yoni_Var, theCard);
      break;
    default:
      printf("Case #%d: %s\n", ++yoni_Var, "Bad magician!");
      break;
    }
  }
  return ret_val;
}
