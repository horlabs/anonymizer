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

enum status_e { XPLYR, OPLYR, DRAW, INCOMPLETE };

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
    char *result_str[] = {"X won", "O won", "Draw", "Game has not completed"};
    enum status_e status = INCOMPLETE;
    unsigned char col[2][4] = {{0}};
    unsigned char row[2][4] = {{0}};
    unsigned char diag[2][2] = {{0}};
    unsigned char c;
    unsigned char i;
    unsigned char j;
    unsigned char empty = 0;

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        switch (c = getchar()) {
        case 'T':
          if (++row[OPLYR][i] == 4 || ++col[OPLYR][j] == 4) {
            status = OPLYR;
            break;
          }
          if (i == j && ++diag[OPLYR][0] == 4)
            status = OPLYR;
          else if (j == 3 - i && ++diag[OPLYR][1] == 4)
            status = OPLYR;
        case 'X':
          if (++row[XPLYR][i] == 4 || ++col[XPLYR][j] == 4) {
            status = XPLYR;
            break;
          }
          if (i == j && ++diag[XPLYR][0] == 4)
            status = XPLYR;
          else if (j == 3 - i && ++diag[XPLYR][1] == 4)
            status = XPLYR;
          break;
        case 'O':
          if (++row[OPLYR][i] == 4 || ++col[OPLYR][j] == 4) {
            status = OPLYR;
            break;
          }
          if (i == j && ++diag[OPLYR][0] == 4)
            status = OPLYR;
          else if (j == 3 - i && ++diag[OPLYR][1] == 4)
            status = OPLYR;
          break;
        case '.':
          empty++;
          break;
        }
      }
      getchar();
    }
    getchar();

    if (!empty && status == INCOMPLETE) {
      status = DRAW;
    }

    printf("Case #%d: %s\n", ++testcase, result_str[status]);
  }

  return 0;
}
