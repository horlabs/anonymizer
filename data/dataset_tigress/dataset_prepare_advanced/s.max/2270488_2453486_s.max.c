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

int won(char niz[][5], char first, char second) {
  int i;
  int j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)
      if (niz[i][j] != first && niz[i][j] != second)
        break;
    if (j == 4)
      return 1;
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)
      if (niz[j][i] != first && niz[j][i] != second)
        break;
    if (j == 4)
      return 1;
  }

  for (i = 0; i < 4; i++)
    if (niz[i][i] != first && niz[i][i] != second)
      break;
  if (i == 4)
    return 1;

  for (i = 0; i < 4; i++)
    if (niz[i][3 - i] != first && niz[i][3 - i] != second)
      break;

  if (i == 4)
    return 1;

  return 0;
}

int complete(char niz[][5]) {
  int i;
  int j;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (niz[i][j] == '.')
        return 0;
  return 1;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int t;

  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    int i;
    char niz[4][5];

    for (i = 0; i < 4; i++)
      scanf("%s", niz[i]);

    printf("Case #%d: ", t);
    if (won(niz, 'X', 'T'))
      printf("X won");
    else if (won(niz, 'O', 'T'))
      printf("O won");
    else if (complete(niz))
      printf("Draw");
    else
      printf("Game has not completed");
    printf("\n");
  }
  return 0;
}
