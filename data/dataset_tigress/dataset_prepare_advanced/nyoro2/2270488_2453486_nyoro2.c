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
  int i;
  int k;
  int l;

  int board_ptn[4][4];
  char cbuf[8];
  int result;
  int j;
  int line_result[10];
  int chk_dot;

  scanf("%d\n", &t);
  for (i = 0; i < t; i++) {

    chk_dot = 0;
    for (l = 0; l < 4; l++) {
      fgets(cbuf, sizeof(cbuf), stdin);

      for (k = 0; k < 4; k++) {
        switch (cbuf[k]) {
        case 'O':
          board_ptn[l][k] = 1;
          break;
        case 'X':
          board_ptn[l][k] = 2;
          break;
        case 'T':
          board_ptn[l][k] = 3;
          break;
        default:
          board_ptn[l][k] = 0;
          chk_dot = 1;
          break;
        }
      }
    }
    fgets(cbuf, sizeof(cbuf), stdin);

    for (j = 0; j < 10; j++)
      line_result[j] = 3;
    for (l = 0; l < 4; l++) {
      for (k = 0; k < 4; k++) {
        line_result[l] &= board_ptn[l][k];
        line_result[l + 4] &= board_ptn[k][l];
      }
      line_result[8] &= board_ptn[l][l];
      line_result[9] &= board_ptn[l][3 - l];
    }
    result = 0;
    for (j = 0; j < 10; j++) {

      result |= line_result[j];
    }

    printf("Case #%d: ", i + 1);
    if (result & 1) {
      printf("O won");
    } else if (result & 2) {
      printf("X won");
    } else if (chk_dot) {
      printf("Game has not completed");
    } else {
      printf("Draw");
    }
    printf("\n");
  }

  return 0;
}
