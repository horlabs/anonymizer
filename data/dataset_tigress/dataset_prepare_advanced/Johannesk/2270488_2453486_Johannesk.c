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

char b[4][4];

int checkwin(char s) {
  int i;
  int j;
  int c;

  for (i = 0; i < 4; i++) {
    c = 0;
    for (j = 0; j < 4; j++) {
      if ((b[i][j] == s) || (b[i][j] == 'T'))
        c++;
    }
    if (c == 4)
      return 1;
  }
  for (j = 0; j < 4; j++) {
    c = 0;
    for (i = 0; i < 4; i++) {
      if ((b[i][j] == s) || (b[i][j] == 'T'))
        c++;
    }
    if (c == 4)
      return 1;
  }

  c = 0;
  for (i = 0; i < 4; i++) {
    if ((b[i][i] == s) || (b[i][i] == 'T'))
      c++;
  }
  if (c == 4)
    return 1;

  c = 0;
  for (i = 0; i < 4; i++) {
    if ((b[3 - i][i] == s) || (b[3 - i][i] == 'T'))
      c++;
  }
  if (c == 4)
    return 1;

  return 0;
}

int checkdraw() {
  int i;
  int j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (b[i][j] == '.')
        return 0;
    }
  }
  return 1;
}

void printinput() {
  int i;
  int j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("%c", b[i][j]);
    }
    printf("\n");
  }
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

  char line[10];

  (scanf("%d ", &t) == 1);
  for (i = 1; i <= t; i++) {
    (scanf("%c%c%c%c ", &b[0][0], &b[0][1], &b[0][2], &b[0][3]) == 4);
    (scanf("%c%c%c%c ", &b[1][0], &b[1][1], &b[1][2], &b[1][3]) == 4);
    (scanf("%c%c%c%c ", &b[2][0], &b[2][1], &b[2][2], &b[2][3]) == 4);
    (scanf("%c%c%c%c ", &b[3][0], &b[3][1], &b[3][2], &b[3][3]) == 4);

    if (checkwin('X'))
      printf("Case #%d: X won\n", i);
    else if (checkwin('O'))
      printf("Case #%d: O won\n", i);
    else if (checkdraw())
      printf("Case #%d: Draw\n", i);
    else
      printf("Case #%d: Game has not completed\n", i);
  }
  return 0;
}
