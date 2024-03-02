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

int a[4][4];
int b[4][4];
int r1;
int r2;

void solve() {
  int i;
  int j;
  int num = -1;
  int k;

  scanf("%d", &r1);
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      scanf("%d", &a[i][j]);
  scanf("%d", &r2);
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      scanf("%d", &b[i][j]);
  for (k = 1; k < 17; k++) {
    for (i = 0; i < 4; i++)
      if (a[r1 - 1][i] == k)
        goto next;
    continue;
  next:
    for (i = 0; i < 4; i++)
      if (b[r2 - 1][i] == k)
        goto next2;
    continue;
  next2:
    if (num > -1) {
      puts("Bad magician!");
      return;
    }
    num = k;
  }
  if (num < 0)
    puts("Volunteer cheated!");
  else
    printf("%d\n", num);
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

  scanf("%d", &T);
  while (T--)
    printf("Case #%d: ", no++), solve();
  return 0;
}
