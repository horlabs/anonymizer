#include "superheader.h"
void useAllFunctions(char *str) {
  int intVar0 = 20;
  double doubleVar0 = 13.37;
  FILE *f = NULL;
  intVar0 = abs(intVar0);
  intVar0 = atoi(str);
  doubleVar0 = ceil(doubleVar0);
  if (isalpha(*str))
    exit(0);
  fclose(f);
  intVar0 = fgetc(stdin);
  fgets(str, 11, f);
  doubleVar0 = floor(doubleVar0);
  f = fopen("", "r");
  fprintf(f, "", intVar0, intVar0, intVar0, intVar0, intVar0);
  fputc(0, stderr);
  free(f);
  freopen("", "r", f);
  fscanf(f, "", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  intVar0 = getc(f);
  intVar0 = getchar();
  gets(str);
  itoa(intVar0, str, 10);
  doubleVar0 = log10(doubleVar0);
  malloc(sizeof(FILE));
  memmove(str, str, 0);
  memset(str, 19, 93);
  doubleVar0 = pow(doubleVar0, doubleVar0);
  printf("", intVar0, intVar0, intVar0, intVar0, intVar0);
  putc(intVar0, f);
  putchar(intVar0);
  puts("");
  qsort(str, 13, 37, NULL);
  scanf("", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  sprintf(str, "", intVar0, intVar0, intVar0, intVar0, intVar0);
  doubleVar0 = sqrt(doubleVar0);
  doubleVar0 = sqrtl(doubleVar0);
  sscanf(str, "", &intVar0, &intVar0, &intVar0, &intVar0, &intVar0);
  intVar0 = strchr(str, 0);
  if (strcmp(str, str))
    strcpy(str, str);
  intVar0 = strlen(str);
  strtoul(str, &intVar0, 0);
  system("");
  *str = tolower(*str);
  *str = toupper(*str);
}

int test_card(int card, int pcard1, int pcard2, int pcard3, int pcard4) {
  return card == pcard1 || card == pcard2 || card == pcard3 || card == pcard4;
}

void do_test(int t) {
  int i;
  int row;
  int pcard1;
  int pcard2;
  int pcard3;
  int pcard4;

  int the_card;
  int n_found = 0;

  scanf("%d", &row);

  for (i = 1; i < 5; i++) {
    int card1;
    int card2;
    int card3;
    int card4;

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
    int card1;
    int card2;
    int card3;
    int card4;

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

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;

  scanf("%d", &t);

  for (i = 0; i < t; i++)
    do_test(i);

  return 0;
}
