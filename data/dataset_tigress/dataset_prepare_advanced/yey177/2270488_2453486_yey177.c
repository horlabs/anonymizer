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

char s[5][5];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int t;
  int i;
  int j;
  int k;
  int f;
  int f1;

  scanf("%d", &t);
  for (k = 1; k <= t; k++) {
    for (i = 0; i < 4; i++)
      scanf("%s", s[i]);
    f1 = 1;
    for (i = 0; i < 4; i++) {
      f = 3;
      for (j = 0; j < 4; j++) {
        if (s[i][j] == 'T')
          f &= 3;
        else if (s[i][j] == 'O')
          f &= 2;
        else if (s[i][j] == 'X')
          f &= 1;
        else if (s[i][j] == '.') {
          f = 0;
          f1 = 0;
        }
      }
      if (f)
        goto END;
    }
    for (j = 0; j < 4; j++) {
      f = 3;
      for (i = 0; i < 4; i++) {
        if (s[i][j] == 'T')
          f &= 3;
        else if (s[i][j] == 'O')
          f &= 2;
        else if (s[i][j] == 'X')
          f &= 1;
        else if (s[i][j] == '.') {
          f = 0;
          f1 = 0;
        }
      }
      if (f)
        goto END;
    }
    f = 3;
    for (i = 0; i < 4; i++) {
      if (s[i][i] == 'T')
        f &= 3;
      else if (s[i][i] == 'O')
        f &= 2;
      else if (s[i][i] == 'X')
        f &= 1;
      else if (s[i][i] == '.') {
        f = 0;
        f1 = 0;
      }
    }
    if (f)
      goto END;
    f = 3;
    for (i = 0; i < 4; i++) {
      if (s[i][3 - i] == 'T')
        f &= 3;
      else if (s[i][3 - i] == 'O')
        f &= 2;
      else if (s[i][3 - i] == 'X')
        f &= 1;
      else if (s[i][3 - i] == '.') {
        f = 0;
        f1 = 0;
      }
    }
  END:
    printf("Case #%d: ", k);
    if (f == 2)
      puts("O won");
    else if (f == 1)
      puts("X won");
    else if (f1 == 1)
      puts("Draw");
    else
      puts("Game has not completed");
  }
  return 0;
}
