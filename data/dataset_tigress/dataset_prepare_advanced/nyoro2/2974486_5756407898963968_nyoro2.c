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
  int t;
  int ans[2];
  int board_ptn[2][4][4];
  int i;
  int j;
  int k;
  int l;

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
