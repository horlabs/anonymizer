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

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    int f = 0;
    int j;
    int k;

    char s[4][5];

    for (j = 0; j < 4; j++)
      scanf("%s", s[j]);

    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        if (s[j][k] == 'O' || s[j][k] == '.')
          break;
      }

      if (k == 4)
        f = 1;

      for (k = 0; k < 4; k++) {
        if (s[k][j] == 'O' || s[k][j] == '.')
          break;
      }

      if (k == 4)
        f = 1;

      for (k = 0; k < 4; k++) {
        if (s[j][k] == 'X' || s[j][k] == '.')
          break;
      }

      if (k == 4)
        f = 2;

      for (k = 0; k < 4; k++) {
        if (s[k][j] == 'X' || s[k][j] == '.')
          break;
      }

      if (k == 4)
        f = 2;
    }

    for (j = 0; j < 4; j++) {
      if (s[j][j] == 'O' || s[j][j] == '.')
        break;
    }

    if (j == 4)
      f = 1;

    for (j = 0; j < 4; j++) {
      if (s[j][3 - j] == 'O' || s[j][3 - j] == '.')
        break;
    }

    if (j == 4)
      f = 1;

    for (j = 0; j < 4; j++) {
      if (s[j][j] == 'X' || s[j][j] == '.')
        break;
    }

    if (j == 4)
      f = 2;

    for (j = 0; j < 4; j++) {
      if (s[j][3 - j] == 'X' || s[j][3 - j] == '.')
        break;
    }

    if (j == 4)
      f = 2;

    if (f == 1) {
      printf("Case #%d: X won\n", i + 1);
    } else if (f == 2) {
      printf("Case #%d: O won\n", i + 1);
    } else {
      for (j = 0; j < 4; j++) {
        for (k = 0; k < 4; k++) {
          if (s[j][k] == '.')
            f = 1;
        }
      }

      if (f == 1) {
        printf("Case #%d: Game has not completed\n", i + 1);
      } else {
        printf("Case #%d: Draw\n", i + 1);
      }
    }
  }

  return 0;
}