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
  int T;
  int t;

  scanf("%d", &T);

  for (t = 1; t <= T; t++) {
    int n;
    int m;
    int i;
    int j;

    int a[100][100];
    int uvjet[100][100] = {0};

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        scanf("%d", a[i] + j);

    int max;
    for (i = 0; i < n; i++) {
      max = 0;
      for (j = 0; j < m; j++)
        if (a[i][j] > max)
          max = a[i][j];
      for (j = 0; j < m; j++)
        if (a[i][j] == max)
          uvjet[i][j] = 1;
    }

    for (j = 0; j < m; j++) {
      max = 0;
      for (i = 0; i < n; i++)
        if (a[i][j] > max)
          max = a[i][j];
      for (i = 0; i < n; i++)
        if (a[i][j] == max)
          uvjet[i][j] = 1;
    }

    printf("Case #%d: ", t);

    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++)
        if (!uvjet[i][j])
          break;
      if (j < m)
        break;
    }

    if (i == n)
      printf("YES");
    else
      printf("NO");
    printf("\n");
  }
}
