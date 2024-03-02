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

int check_win(char Board[4][4], char c) {
  int x;
  int y;

  for (y = 0; y < 4; y++) {

    for (x = 0; x < 4; x++) {
      if (Board[x][y] != 'T' && Board[x][y] != c)
        break;
    }
    if (x == 4)
      return 1;
  }
  for (x = 0; x < 4; x++) {

    for (y = 0; y < 4; y++) {
      if (Board[x][y] != 'T' && Board[x][y] != c)
        break;
    }
    if (y == 4)
      return 1;
  }

  for (x = 0; x < 4; x++) {
    if (Board[x][x] != 'T' && Board[x][x] != c)
      break;
  }
  if (x == 4)
    return 1;
  for (x = 0; x < 4; x++) {
    if (Board[x][3 - x] != 'T' && Board[x][3 - x] != c)
      break;
  }
  if (x == 4)
    return 1;
  return 0;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int T;

  int x;
  int y;

  scanf("%d\n", &T);
  for (t = 1; t <= T; t++) {
    char Board[4][4];
    for (y = 0; y < 4; y++) {
      for (x = 0; x < 4; x++) {
        scanf("%c ", &Board[x][y]);
      }
    }

    int has_empty = 0;
    for (y = 0; y < 4; y++) {
      for (x = 0; x < 4; x++) {
        if (Board[x][y] == '.')
          has_empty = 1;
      }
    }
    char retstr[100];
    int X_won = check_win(Board, 'X');
    int O_won = check_win(Board, 'O');

    (!(X_won && O_won));
    if (X_won) {
      sprintf(retstr, "X won");
    } else if (O_won) {
      sprintf(retstr, "O won");
    } else {
      if (has_empty) {
        sprintf(retstr, "Game has not completed");
      } else {
        sprintf(retstr, "Draw");
      }
    }
    printf("Case #%d: %s\n", t, retstr);
  }
  return 0;
}