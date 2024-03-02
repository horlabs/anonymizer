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

int g[5][10][10];
int vis[20];

void init_tigress() {}
int main_fun(int, char **);
int main(int argc, char **argv) {
  init_tigress();
  main_fun(argc, argv);
}
int main_fun(int argc, char **argv) {
  int T;
  int nCase = 1;

  int i;
  int j;
  int a;
  int b;

  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A_out.txt", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &a);
    for (i = 1; i <= 4; i++)
      for (j = 1; j <= 4; j++)
        scanf("%d", &g[0][i][j]);
    for (i = 1; i <= 4; i++)
      vis[g[0][a][i]] = 1;

    scanf("%d", &b);
    for (i = 1; i <= 4; i++)
      for (j = 1; j <= 4; j++)
        scanf("%d", &g[1][i][j]);

    int ans = 0;
    for (i = 1; i <= 4; i++)
      if (vis[g[1][b][i]])
        if (ans != 0)
          ans = -1;
        else
          ans = g[1][b][i];

    printf("Case #%d: ", nCase++);
    if (ans == -1)
      puts("Bad magician!");
    else if (ans == 0)
      puts("Volunteer cheated!");
    else
      printf("%d\n", ans);
  }
  return 0;
}