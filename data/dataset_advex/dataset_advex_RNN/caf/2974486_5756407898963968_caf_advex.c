#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_card(int card, int pcard1, int pcard2, int pcard3, int pcard4) {
  return card == pcard1 || card == pcard2 || card == pcard3 || card == pcard4;
}

void do_voiztj_fct(int t) {
  int i;
  int row;
  int pcard1, pcard2, pcard3, pcard4;
  int the_card;
  int n_found = 0;

  scanf("%d", &row);

  for (i = 1; i < 5; i++) {
    int card1, card2, card3, card4;
    scanf("%d %d %d %d", &card1, &card2, &card3, &card4);

    if (i == row) {
      pcard1 = card1;
      pcard2 = card2;
      pcard3 = card3;
      pcard4 = card4;
    }
  }

  scanf("%d", &row);

  for (i = 1; i < 5; i++) {
    int card1, card2, card3, card4;
    scanf("%d %d %d %d", &card1, &card2, &card3, &card4);

    if (i == row) {
      if (test_card(pcard1, card1, card2, card3, card4))
        the_card = pcard1, n_found++;
      if (test_card(pcard2, card1, card2, card3, card4))
        the_card = pcard2, n_found++;
      if (test_card(pcard3, card1, card2, card3, card4))
        the_card = pcard3, n_found++;
      if (test_card(pcard4, card1, card2, card3, card4))
        the_card = pcard4, n_found++;
    }
  }

  printf("Case #%d: ", t + 1);
  if (n_found < 1)
    printf("Volunteer cheated!\n");
  else if (n_found > 1)
    printf("Bad magician!\n");
  else
    printf("%d\n", the_card);
}

int main() {
  int t, i;

  scanf("%d", &t);

  for (i = 0; i < t; i++)
    do_voiztj_fct(i);

  return 0;
}
