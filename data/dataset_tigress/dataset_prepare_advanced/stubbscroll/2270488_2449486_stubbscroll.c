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

int g[111][111];
int try
  [111][111];
int x;
int y;

int can() {
  int i;
  int j;
  int maks;
  int ch;

  for (i = 0; i < x; i++)
    for (j = 0; j < y; j++)
      try
        [i][j] = 100;
  do {
    ch = 0;
    for (i = 0; i < x; i++) {
      maks = 0;
      for (j = 0; j < y; j++)
        if (maks < g[i][j])
          maks = g[i][j];
      for (j = 0; j < y; j++)
        if (try[i][j] > maks)
          try
            [i][j] = maks, ch = 1;
    }
    for (j = 0; j < y; j++) {
      maks = 0;
      for (i = 0; i < x; i++)
        if (maks < g[i][j])
          maks = g[i][j];
      for (i = 0; i < x; i++)
        if (try[i][j] > maks)
          try
            [i][j] = maks, ch = 1;
    }
  } while (ch);
  for (i = 0; i < x; i++)
    for (j = 0; j < y; j++)
      if (try[i][j] != g[i][j])
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
  int no = 1;
  int i;
  int j;

  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &x, &y);
    for (i = 0; i < x; i++)
      for (j = 0; j < y; j++)
        scanf("%d", &g[i][j]);
    printf("Case #%d: %s\n", no++, can() ? "YES" : "NO");
  }
  return 0;
}