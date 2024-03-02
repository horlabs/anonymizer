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
    int card;
    int theCard;

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
        int i;
        int j;

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
