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
  int i;
  int j;

  int ii;
  int jj;
  int kk;

  int res;
  int m;
  char map[10][10];
  int end;
  int xw;
  int ow;

  unsigned long long result;

  scanf("%d", &m);

  for (ii = 1; ii <= m; ii++) {
    end = 1;
    xw = 0;
    ow = 0;
    memset(map, 0, 100);
    result = 0;
    for (i = 0; i < 4; i++) {
      scanf("%s", map[i]);
    }

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (map[i][j] == '.')
          break;
      }
      if (j != 4)
        break;
    }
    if (i != 4 && j != 4)
      end = 0;

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (map[i][j] != 'O' && map[i][j] != 'T')
          break;
      }
      if (j == 4)
        ow = 1;
      for (j = 0; j < 4; j++) {
        if (map[i][j] != 'X' && map[i][j] != 'T')
          break;
      }
      if (j == 4)
        xw = 1;
      for (j = 0; j < 4; j++) {
        if (map[j][i] != 'O' && map[j][i] != 'T')
          break;
      }
      if (j == 4)
        ow = 1;
      for (j = 0; j < 4; j++) {
        if (map[j][i] != 'X' && map[j][i] != 'T')
          break;
      }
      if (j == 4)
        xw = 1;
    }

    for (i = 0; i < 4; i++) {
      if (map[i][i] != 'X' && map[i][i] != 'T')
        break;
    }
    if (i == 4)
      xw = 1;

    for (i = 0; i < 4; i++) {
      if (map[3 - i][i] != 'X' && map[3 - i][i] != 'T')
        break;
    }
    if (i == 4)
      xw = 1;

    for (i = 0; i < 4; i++) {
      if (map[i][i] != 'O' && map[i][i] != 'T')
        break;
    }
    if (i == 4)
      ow = 1;

    for (i = 0; i < 4; i++) {
      if (map[3 - i][i] != 'O' && map[3 - i][i] != 'T')
        break;
    }
    if (i == 4)
      ow = 1;

    if (xw == 1)
      printf("Case #%d: X won\n", ii);
    else if (ow == 1)
      printf("Case #%d: O won\n", ii);
    else if (end == 1)
      printf("Case #%d: Draw\n", ii);
    else
      printf("Case #%d: Game has not completed\n", ii);
  }
}
