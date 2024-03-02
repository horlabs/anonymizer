#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int jzxi_Var = 0;
  int plli_Var;

  scanf("%d\n", &plli_Var);

  while (jzxi_Var < plli_Var) {
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
        int ryji_Var;

        for (found = 0, ryji_Var = 0; ryji_Var < 4; ryji_Var++) {
          scanf("%d", &card);

          for (int emqi_Var = 0; emqi_Var < 4; emqi_Var++) {
            if (card == cards[emqi_Var]) {
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
      printf("Case #%d: %s\n", ++jzxi_Var, "Volunteer cheated!");
      break;
    case 1:
      printf("Case #%d: %d\n", ++jzxi_Var, theCard);
      break;
    default:
      printf("Case #%d: %s\n", ++jzxi_Var, "Bad magician!");
      break;
    }
  }

  return 0;
}
