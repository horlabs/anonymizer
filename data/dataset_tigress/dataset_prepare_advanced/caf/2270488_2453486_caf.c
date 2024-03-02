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

static int is_x(char tile) { return tile == 'X' || tile == 'T'; }

static int is_o(char tile) { return tile == 'O' || tile == 'T'; }

static void do_test(int t) {
  char board[4][4];
  int i;
  int j;

  int unfinished = 0;
  int x_won = 0;
  int o_won = 0;

  int x_won_diag_1 = 1;
  int o_won_diag_1 = 1;
  int x_won_diag_2 = 1;
  int o_won_diag_2 = 1;

  scanf(" %4c %4c %4c %4c", board[0], board[1], board[2], board[3]);

  for (i = 0; i < 4; i++) {

    int x_won_col = 1;
    int o_won_col = 1;
    int x_won_row = 1;
    int o_won_row = 1;

    for (j = 0; j < 4; j++) {
      unfinished = unfinished || board[i][j] == '.';

      x_won_col = x_won_col && is_x(board[j][i]);
      o_won_col = o_won_col && is_o(board[j][i]);

      x_won_row = x_won_row && is_x(board[i][j]);
      o_won_row = o_won_row && is_o(board[i][j]);
    }

    x_won = x_won || x_won_col || x_won_row;
    o_won = o_won || o_won_col || o_won_row;

    x_won_diag_1 = x_won_diag_1 && is_x(board[i][i]);
    o_won_diag_1 = o_won_diag_1 && is_o(board[i][i]);

    x_won_diag_2 = x_won_diag_2 && is_x(board[3 - i][i]);
    o_won_diag_2 = o_won_diag_2 && is_o(board[3 - i][i]);
  }

  x_won = x_won || x_won_diag_1 || x_won_diag_2;
  o_won = o_won || o_won_diag_1 || o_won_diag_2;

  printf("Case #%d: %s\n", t + 1,
         x_won ? "X won"
               : o_won ? "O won"
                       : unfinished ? "Game has not completed" : "Draw");
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
