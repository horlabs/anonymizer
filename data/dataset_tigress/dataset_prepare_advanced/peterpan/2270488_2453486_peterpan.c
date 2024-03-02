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
void readline() {
  while (getchar() != '\n')
    ;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int i;
  int j;
  int tcase;
  int T;
  int xs;
  int os;
  int ts;
  int winner;

  char board[5][5];
  char last;

  scanf("%d", &T);
  for (tcase = 1; tcase <= T; tcase++) {
    xs = os = ts = 0;
    readline();
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        board[i][j] = getchar();
        if (board[i][j] == 'X')
          xs++;
        else if (board[i][j] == 'O')
          os++;
        else if (board[i][j] == 'T')
          ts++;
        else if (board[i][j] != '.') {
          fprintf(stderr, "Error reading input!\n");
          exit(1);
        }
      }
      readline();
    }
    if (xs > os)
      last = 'X';
    else
      last = 'O';
    for (i = 0; i < 4; i++) {
      winner = 1;
      for (j = 0; j < 4; j++) {
        if (board[i][j] != last && board[i][j] != 'T') {
          winner = 0;
          break;
        }
      }
      if (winner)
        break;
      winner = 1;
      for (j = 0; j < 4; j++) {
        if (board[j][i] != last && board[j][i] != 'T') {
          winner = 0;
          break;
        }
      }
      if (winner)
        break;
    }
    if (winner) {
      printf("Case #%d: %c won\n", tcase, last);
      continue;
    }
    winner = 1;
    for (j = 0; j < 4; j++) {
      if (board[j][j] != last && board[j][j] != 'T') {
        winner = 0;
        break;
      }
    }
    if (winner) {
      printf("Case #%d: %c won\n", tcase, last);
      continue;
    }
    winner = 1;
    for (j = 0; j < 4; j++) {
      if (board[4 - 1 - j][j] != last && board[4 - 1 - j][j] != 'T') {
        winner = 0;
        break;
      }
    }
    if (winner) {
      printf("Case #%d: %c won\n", tcase, last);
      continue;
    }
    if (xs + os + ts == 4 * 4)
      printf("Case #%d: Draw\n", tcase);
    else
      printf("Case #%d: Game has not completed\n", tcase);
  }

  return 0;
}
