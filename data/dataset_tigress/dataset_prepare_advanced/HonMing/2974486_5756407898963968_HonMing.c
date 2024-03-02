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
  int i;
  int j;

  int ii;
  int jj;
  int kk;

  int res;
  int m;
  int map[10][10];
  int end;
  int xw;
  int ow;

  int r1;
  int r2;

  int p[10];
  int p2[10];
  int count;
  int ans;

  unsigned long long result;

  scanf("%d", &m);

  for (ii = 1; ii <= m; ii++) {
    scanf("%d", &r1);
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++) {
        scanf("%d", &map[i][j]);
        if (i == r1 - 1)
          p[j] = map[i][j];
      }

    scanf("%d", &r2);
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++) {
        scanf("%d", &map[i][j]);
        if (i == r2 - 1)
          p2[j] = map[i][j];
      }

    count = 0;
    ans = -1;

    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (p[i] == p2[j]) {
          ans = p[i];
          count++;
          break;
        }
      }
    }

    if (count == 0)
      printf("Case #%d: Volunteer cheated!\n", ii);
    else if (count == 1)
      printf("Case #%d: %d\n", ii, ans);
    else
      printf("Case #%d: Bad magician!\n", ii);
  }
}
