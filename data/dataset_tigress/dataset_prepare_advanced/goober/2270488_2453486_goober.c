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

char a[4][5];

int check(char c) {
  int cnt;

  cnt = 0;
  for (int i = 0; i < 4; i++)
    cnt += (a[i][i] == c || a[i][i] == 'T');
  if (cnt == 4)
    return 1;

  cnt = 0;
  for (int i = 0; i < 4; i++)
    cnt += (a[i][3 - i] == c || a[i][3 - i] == 'T');
  if (cnt == 4)
    return 1;

  for (int i = 0; i < 4; i++) {
    cnt = 0;
    for (int j = 0; j < 4; j++)
      cnt += (a[i][j] == c || a[i][j] == 'T');
    if (cnt == 4)
      return 1;

    cnt = 0;
    for (int j = 0; j < 4; j++)
      cnt += (a[j][i] == c || a[j][i] == 'T');
    if (cnt == 4)
      return 1;
  }
  return 0;
}

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    for (int i = 0; i < 4; i++)
      scanf("%s", &a[i]);
    const char *msg = "Draw";
    if (check('X'))
      msg = "X won";
    else if (check('O'))
      msg = "O won";
    else {
      int cnt = 0;
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
          if (a[i][j] == '.')
            cnt++;
      if (cnt > 0)
        msg = "Game has not completed";
    }

    printf("Case #%d: %s\n", t, msg);
  }
}
