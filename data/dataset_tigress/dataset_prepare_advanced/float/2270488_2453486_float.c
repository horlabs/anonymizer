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

int conv(char c) {
  switch (c) {
  case 'X':
    return 0;
    break;

  case 'O':
    return 1;
    break;

  case 'T':
    return 2;
    break;

  case '.':
    return -1;
    break;
  }
  return -1;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int cas_n;
  int cas;
  int row;
  int col;
  int index;
  int i;
  int tmp;
  int flag;

  int sum[10][3];
  char board[5][5];
  char c;

  scanf("%d", &cas_n);
  getc(stdin);
  for (cas = 1; cas <= cas_n; cas++) {
    flag = 0;
    printf("Case #%d: ", cas);
    if (cas > 1)
      getc(stdin);
    for (row = 0; row < 4; row++) {
      fgets(board[row], sizeof(board[0]), stdin);
      getc(stdin);
    }

    memset(sum, 0, sizeof(sum));

    for (index = 0; index < 4; index++) {
      for (i = 0; i < 4; i++) {
        tmp = conv(board[index][i]);
        if (tmp >= 0)
          sum[index][tmp]++;
        tmp = conv(board[i][index]);
        if (tmp >= 0)
          sum[4 + index][tmp]++;
      }
      tmp = conv(board[index][index]);
      if (tmp >= 0)
        sum[8][tmp]++;
      tmp = conv(board[index][3 - index]);
      if (tmp >= 0)
        sum[9][tmp]++;
    }
    for (i = 0; i < 10; i++) {
      if (sum[i][0] + sum[i][2] == 4) {
        puts("X won");
        flag = 1;
        break;
      } else if (sum[i][1] + sum[i][2] == 4) {
        puts("O won");
        flag = 1;
        break;
      }
    }
    if (flag)
      continue;

    for (row = 0; row < 4 && flag == 0; row++) {
      for (col = 0; col < 4; col++) {
        if (board[row][col] == '.') {
          puts("Game has not completed");
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      continue;
    else
      puts("Draw");
  }
  return 0;
}
