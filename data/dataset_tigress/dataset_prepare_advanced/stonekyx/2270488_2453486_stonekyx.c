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

char map[10][10];

int check_win(int ch) {
  int i;
  for (i = 0; i < 4; i++) {
    int j;
    for (j = 0; j < 4; j++) {
      if (map[i][j] != ch && map[i][j] != 'T') {
        break;
      }
    }
    if (j >= 4)
      return 1;
    for (j = 0; j < 4; j++) {
      if (map[j][i] != ch && map[j][i] != 'T') {
        break;
      }
    }
    if (j >= 4)
      return 1;
  }
  for (i = 0; i < 4; i++) {
    if (map[i][i] != ch && map[i][i] != 'T') {
      break;
    }
  }
  if (i >= 4)
    return 1;
  for (i = 0; i < 4; i++) {
    if (map[i][3 - i] != ch && map[i][3 - i] != 'T') {
      break;
    }
  }
  if (i >= 4)
    return 1;
  return 0;
}

int check_full(void) {
  int i;
  for (i = 0; i < 4; i++) {
    int j;
    for (j = 0; j < 4; j++) {
      if (map[i][j] == '.')
        return 0;
    }
  }
  return 1;
}

int get_res(void) {
  if (check_win('X'))
    return 0;
  if (check_win('O'))
    return 1;
  if (check_full())
    return 2;
  return 3;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int Tcnt = 0;

  for (scanf("%d\n", &T); T; T--) {
    int i;
    int res;
    for (i = 0; i < 5; i++) {
      fgets(map[i], 10, stdin);
    }
    res = get_res();
    printf("Case #%d: ", ++Tcnt);
    switch (res) {
    case 0:
      puts("X won");
      break;
    case 1:
      puts("O won");
      break;
    case 2:
      puts("Draw");
      break;
    case 3:
      puts("Game has not completed");
      break;
    default:
      break;
    }
  }
  return 0;
}
